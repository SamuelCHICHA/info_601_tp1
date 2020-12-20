cmake_minimum_required(VERSION 3.19)
project(TP1 C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Wextra -ansi -pedantic")

include_directories(headers)

add_executable(TP1
        block.c
        flake.c
        info.c
        main.c
        ncurses_extra.c
        simu.c
        status.c
        window.c
        list.c
        cell.c)

target_link_libraries(TP1 "-lncurses")
