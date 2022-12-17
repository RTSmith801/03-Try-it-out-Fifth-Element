cmake_minimum_required(VERSION 3.22)
project(03_Try_it_out_Fifth_Element)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(03_Try_it_out_Fifth_Element
        FifthElement.cpp
        FifthElement.h
        FifthElementTester.cpp
        LinkedList.cpp
        LinkedList.h)
