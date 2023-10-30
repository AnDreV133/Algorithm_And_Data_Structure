cmake_minimum_required(VERSION 3.24)
project(Algorithm_And_Data_Structure)

set(CMAKE_CXX_STANDARD 17)

add_library(
        mystring
        mystring/mystring.cpp
        mystring/mystring.h
)

add_library(
        mytranslatornum
        mytranslatornum/mytranslatornum.cpp
        mytranslatornum/mytranslatornum.h
)

add_library(
        mysorts
        mysorts/mysorts.cpp
        mysorts/mysorts.h
)

add_library(
        myqueue
        myqueue/solution.cpp
        myqueue/solution.h
        myqueue/myqueue.cpp
        myqueue/myqueue.h
)

add_library(
        mystack
        mystack/mystack.cpp
        mystack/mystack.h
)

add_library(
        mylinerlist
        mylinerlist/mylinerlist.cpp
        mylinerlist/mylinerlist.h
        mylinerlist/solutionlinearlist.cpp
        mylinerlist/solutionlinearlist.h
)

add_library(
        tests
        tests/test_mystring.cpp
        tests/test_mystring.h
        tests/test_mytranslatornum.cpp
        tests/test_mytranslatornum.h
        tests/test_mysorts.cpp
        tests/test_mysorts.h
        tests/test_mylinerlist.cpp
        tests/test_mylinerlist.h
)

add_executable(
        main
        main.cpp
)

target_link_libraries(
        main
        tests
        mylinerlist
        mystring
        mytranslatornum
        myqueue
        mystack
)
