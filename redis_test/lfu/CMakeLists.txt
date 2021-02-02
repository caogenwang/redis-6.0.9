cmake_minimum_required(VERSION 3.4.0)
project(LFU)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
set(APP_SRC main.cpp)

add_executable(LFU ${APP_SRC})