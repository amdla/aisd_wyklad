cmake_minimum_required(VERSION 3.26)
project(aisd_wyklad C)

set(CMAKE_C_STANDARD 11)

add_executable(aisd_wyklad
        w02/MergeSort.c
        w02/Insort.c
        w03/QuickSort.c
        w04/HeapSort.c
        w04/PriorityQueueAndHeap.c
        w04/MergeFiles.c)
