cmake_minimum_required (VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
set(This grid)

set(Headers
    include/grid/grid.hpp
)

set(Sources
    src/grid.cpp
)
add_library (${This} ${Headers} ${Sources})
target_include_directories(${This} PUBLIC include)

add_subdirectory(test)

enable_testing()