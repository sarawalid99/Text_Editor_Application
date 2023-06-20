cmake_minimum_required(VERSION 3.25)
project(Text_Editor_App)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Text_Editor_App
        main.cpp
        txteditor.cpp
        txteditor.h)
