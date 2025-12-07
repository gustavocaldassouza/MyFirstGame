cmake_minimum_required(VERSION 3.10)
project(MyFirstGame)

set(CMAKE_CXX_STANDARD 17)

# Try to find Raylib using standard CMake mechanisms
find_package(raylib QUIET)

# If not found, try to use pkg-config (common on macOS/Linux)
if (NOT raylib_FOUND)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(RAYLIB REQUIRED raylib)
endif()

add_executable(MyFirstGame src/main.cpp)

if (raylib_FOUND)
    target_link_libraries(MyFirstGame raylib)
else()
    target_include_directories(MyFirstGame PRIVATE ${RAYLIB_INCLUDE_DIRS})
    target_link_libraries(MyFirstGame ${RAYLIB_LIBRARIES})
endif()
