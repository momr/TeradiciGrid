cmake_minimum_required (VERSION 3.19)
project (Grid)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(grid-cli-app)
add_subdirectory(grid)
enable_testing()