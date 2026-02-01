cmake_minimum_required(VERSION 3.15)
project(Mariner VERSION 1.0 LANGUAGES C CXX)

# ---------- Build type ----------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

# Enable PIC for shared library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ---------- Find GLFW ----------
find_package(glfw3 CONFIG REQUIRED)

# ---------- GLAD ----------
set(GLAD_DIR ${CMAKE_SOURCE_DIR}/extern/glad)
set(GLAD_SOURCES
    ${GLAD_DIR}/src/glad.c
)

# ---------- Cling ----------
set(CLING_DIR ${CMAKE_SOURCE_DIR}/extern/cling)
set(CLING_INCLUDE_DIR ${CLING_DIR}/include)
set(CLING_LIB_DIR ${CLING_DIR}/lib)
include_directories(SYSTEM ${CLING_INCLUDE_DIR})

# Separate Cling dynamic and static libraries
file(GLOB CLING_DYLIBS "${CLING_LIB_DIR}/*.dylib")
file(GLOB CLING_STATIC "${CLING_LIB_DIR}/*.a")

# ---------- Include directories ----------
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${GLAD_DIR}/include)

# ---------- Mariner sources ----------
file(GLOB_RECURSE MARINER_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/include/**/*.hpp
    ${CMAKE_SOURCE_DIR}/src/**/*.cpp
)

# ---------- Mariner shared library ----------
add_library(Mariner SHARED
    ${MARINER_SOURCES}
    ${GLAD_SOURCES}
)

target_compile_features(Mariner PUBLIC cxx_std_23)
target_compile_options(Mariner PRIVATE -g -O0 -Wno-deprecated -Wno-deprecated-declarations)
target_link_options(Mariner PRIVATE -g)

# Link libraries
target_link_libraries(Mariner PRIVATE glfw ${CLING_STATIC} ${CLING_DYLIBS})

# ---------- macOS RPATH for Mariner ----------
if(APPLE)
    set_target_properties(Mariner PROPERTIES
        MACOSX_RPATH TRUE
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_NAME_DIR "@rpath"
        INSTALL_RPATH "@loader_path"
    )

    # Apply install_name_tool only to dylibs
    foreach(lib ${CLING_DYLIBS})
        get_filename_component(lib_name ${lib} NAME)
        add_custom_command(TARGET Mariner POST_BUILD
            COMMAND install_name_tool -id @rpath/${lib_name} ${lib}
            COMMAND install_name_tool -change ${lib} @rpath/${lib_name} $<TARGET_FILE:Mariner>
        )
    endforeach()
endif()

# ---------- Link system libraries ----------
find_library(ZLIB_LIB z)
find_library(ZSTD_LIB zstd)
find_library(NCURSES_LIB ncurses)
target_link_libraries(Mariner PRIVATE ${ZLIB_LIB} ${ZSTD_LIB} ${NCURSES_LIB})

# ---------- Example executable ----------
add_executable(MarinerExample
    ${CMAKE_SOURCE_DIR}/examples/main.cpp
)

target_compile_features(MarinerExample PUBLIC cxx_std_23)
target_compile_options(MarinerExample PRIVATE -g -O0 -Wno-deprecated -Wno-deprecated-declarations)
target_link_options(MarinerExample PRIVATE -g)
target_link_libraries(MarinerExample PRIVATE Mariner glfw)

# ---------- macOS RPATH & copy for executable ----------
if(APPLE)
    set_target_properties(MarinerExample PROPERTIES
        MACOSX_RPATH TRUE
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "@loader_path/../Frameworks;@loader_path"
    )

    # Copy Mariner.dylib into executable Frameworks folder
    add_custom_command(TARGET MarinerExample POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
            $<TARGET_FILE_DIR:MarinerExample>/../Frameworks
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Mariner>
            $<TARGET_FILE_DIR:MarinerExample>/../Frameworks/
    )

    # Copy Cling dylibs into executable Frameworks folder
    foreach(lib ${CLING_DYLIBS})
        add_custom_command(TARGET MarinerExample POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${lib}
                $<TARGET_FILE_DIR:MarinerExample>/../Frameworks/
        )
    endforeach()
endif()
