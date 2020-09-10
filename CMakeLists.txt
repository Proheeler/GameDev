cmake_minimum_required(VERSION 3.5)

project(sdlDev LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(SDL2 REQUIRED)
find_package(SDL_ttf REQUIRED)
include_directories(sdlDev ${SDL2_INCLUDE_DIRS} include)
file(GLOB_RECURSE SOURCES  "src/*.cpp")
add_executable(sdlDev ${SOURCES} main.cpp)
target_link_libraries(sdlDev -lSDL2 -lSDL2_image  -lSDL2_ttf ${SDL2_LIBRARIES} -ltinyxml2)
