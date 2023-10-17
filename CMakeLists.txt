cmake_minimum_required(VERSION 3.26)
project(aisd_wyklad C)

set(CMAKE_C_STANDARD 11)

add_executable(aisd_wyklad
        w02/MergeSort.c
        w02/insort.c
        w02/liniowe.c
        w03/quickSort.c)
