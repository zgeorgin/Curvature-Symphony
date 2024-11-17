cmake_minimum_required(VERSION 3.27)
project(Curve)

include_directories(./headers/)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(yaml-cpp REQUIRED)

set(SOURCE_DIR "src")
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

add_executable (Curve ${SOURCES})

target_include_directories(Curve PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(Curve PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(Curve PRIVATE yaml-cpp)

add_compile_options(-g)
