cmake_minimum_required(VERSION 3.22) 
add_library(HAL 
    Button.cpp 
    Led.cpp 
    Uart.cpp
    Seg.cpp
    Adapter.cpp)
target_include_directories(HAL PUBLIC ${CMAKE_SOURCE_DIR}/includes/)
