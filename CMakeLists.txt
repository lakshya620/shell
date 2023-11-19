cmake_minimum_required(VERSION 3.0.0)
project(ccsh VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(ccsh main.cpp)

