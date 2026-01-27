cmake_minimum_required(VERSION 3.15)

project(Mariner VERSION 1.0 LANGUAGES CXX)

# Force Debug on all generators
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

# No global flags. Ever.
# No mixed standards. Ever.

# Find GLFW
find_package(glfw3 CONFIG REQUIRED)

file(GLOB_RECURSE MARINER_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/include/**/*.hpp
    ${CMAKE_SOURCE_DIR}/src/**/*.cpp
)

add_library(Mariner SHARED ${MARINER_SOURCES})

target_include_directories(Mariner
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(Mariner PUBLIC cxx_std_23)

target_compile_options(Mariner PRIVATE
    -g
    -O0
)

target_link_options(Mariner PRIVATE
    -g
)

# Link GLFW to the library (remove if only examples use it)
target_link_libraries(Mariner
    PRIVATE glfw
)

add_executable(MarinerExample
    ${CMAKE_SOURCE_DIR}/examples/main.cpp
)

target_compile_features(MarinerExample PUBLIC cxx_std_23)

target_compile_options(MarinerExample PRIVATE
    -g
    -O0
)

target_link_options(MarinerExample PRIVATE
    -g
)

target_link_libraries(MarinerExample
    PRIVATE
        Mariner
        glfw
)
