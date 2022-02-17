cmake_minimum_required(VERSION 3.21)
project(CppHetero_master)


include_directories(.)

add_executable(CppHetero_master
        bacterium.h
        gtest_lite.h
        hetero_store.hpp
        hetero_test.cpp
        memtrace.cpp
        memtrace.h
        testclass.h)

