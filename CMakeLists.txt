cmake_minimum_required(VERSION 3.12...3.24)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(demo VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_MODE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ALLOW_DUPLICATE_CUSTOM_TARGETS TRUE)

include(FetchContent)

add_subdirectory("src")

target_compile_definitions(demo PUBLIC -DGLFW_INCLUDE_NONE)
target_link_options(demo PUBLIC -static)

