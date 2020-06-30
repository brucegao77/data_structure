cmake_minimum_required(VERSION 3.16)
project(static_link_list C)

set(CMAKE_C_STANDARD 99)

add_executable(static_link_list main.c static_link_list.c)