cmake_minimum_required(VERSION 3.15)
project(network_programming_beginner C)

set(CMAKE_C_STANDARD 99)

add_executable(network_programming_beginner server.c client.c showip.c)