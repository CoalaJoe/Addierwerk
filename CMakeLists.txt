cmake_minimum_required(VERSION 3.8)
project(Addierwerk)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Halbaddierer.cpp Halbaddierer.h Volladdierer.cpp Volladdierer.h Addierwerk.cpp Addierwerk.h)
add_executable(Addierwerk ${SOURCE_FILES})
