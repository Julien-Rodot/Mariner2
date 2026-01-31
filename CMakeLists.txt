cmake_minimum_required(VERSION 3.15)

project(Mariner VERSION 1.0 LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

# Find GLFW
find_package(glfw3 CONFIG REQUIRED)

# GLAD
set(GLAD_DIR ${CMAKE_SOURCE_DIR}/extern/glad)
set(GLAD_SOURCES
    ${GLAD_DIR}/src/glad.c
)

# Cling
set(CLING_DIR ${CMAKE_SOURCE_DIR}/extern/cling)
set(CLING_INCLUDE_DIR ${CLING_DIR}/include)
set(CLING_LIB_DIR ${CLING_DIR}/lib)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${GLAD_DIR}/include)
include_directories(SYSTEM ${CLING_INCLUDE_DIR})  # SYSTEM to suppress warnings

# Mariner sources
file(GLOB_RECURSE MARINER_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/include/**/*.hpp
    ${CMAKE_SOURCE_DIR}/src/**/*.cpp
)

# Mariner shared library
add_library(Mariner SHARED
    ${MARINER_SOURCES}
    ${GLAD_SOURCES}
)

target_compile_features(Mariner PUBLIC cxx_std_23)

target_compile_options(Mariner PRIVATE
    -g
    -O0
    -Wno-deprecated
    -Wno-deprecated-declarations
)

target_link_options(Mariner PRIVATE -g)

target_link_libraries(Mariner PRIVATE glfw)

# Link Cling libraries to Mariner
if(EXISTS ${CLING_LIB_DIR})
    target_link_directories(Mariner PRIVATE ${CLING_LIB_DIR})
    file(GLOB CLING_LIBS "${CLING_LIB_DIR}/*.a" "${CLING_LIB_DIR}/*.dylib" "${CLING_LIB_DIR}/*.so")
    if(CLING_LIBS)
        target_link_libraries(Mariner PRIVATE ${CLING_LIBS})
    endif()
endif()

# macOS ARM64: link ncurses for LLVM/Cling terminal symbols
find_library(NCURSES_LIB ncurses)
if(NCURSES_LIB)
    target_link_libraries(Mariner PRIVATE ${NCURSES_LIB})
endif()

# Example executable
add_executable(MarinerExample
    ${CMAKE_SOURCE_DIR}/examples/main.cpp
)

target_compile_features(MarinerExample PUBLIC cxx_std_23)

target_compile_options(MarinerExample PRIVATE
    -g
    -O0
    -Wno-deprecated
    -Wno-deprecated-declarations
)

target_link_options(MarinerExample PRIVATE -g)

target_link_libraries(MarinerExample
    PRIVATE
        Mariner
        glfw
)
