cmake_minimum_required(VERSION 3.20)
project(3DSoftwareRenderer LANGUAGES C)


set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_GENERATOR "MinGW Makefiles")

set(DEPENDENCIES_DIR "dependencies/")
set(SDL3_DIR "${DEPENDENCIES_DIR}/SDL3-3.4.2/cmake")
find_package(SDL3 REQUIRED)

set(SOURCES src/goop/goop.c src/goop/goop.h)

add_library(GOOP STATIC
    src/goop/goop.c
)

add_executable(${PROJECT_NAME}
    src/main.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 GOOP)

