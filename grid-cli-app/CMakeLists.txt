cmake_minimum_required (VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
set(This grid-cli)

set(Sources
    src/main.cpp
)
add_executable(${This} ${Sources})
target_include_directories(${This} PUBLIC include)
target_link_libraries(
    ${This}
    grid
)
