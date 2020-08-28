cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(SDL2 REQUIRED)
include_directories(tests ${SDL2_INCLUDE_DIRS} include)
file(GLOB_RECURSE SOURCES  "src/*.cpp")
add_executable(tests ${SOURCES} main.cpp)
target_link_libraries(tests -lSDL2 -lSDL2_image  ${SDL2_LIBRARIES})
