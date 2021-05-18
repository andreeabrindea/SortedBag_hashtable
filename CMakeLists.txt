cmake_minimum_required(VERSION 3.19)
project(SortedBag_hashtable)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortedBag_hashtable main.cpp ExtendedTest.cpp ExtendedTest.h ShortTest.cpp ShortTest.h SortedBag.cpp SortedBag.h SortedBagIterator.cpp SortedBagIterator.h)