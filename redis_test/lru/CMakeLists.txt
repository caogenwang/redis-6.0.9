cmake_minimum_required(VERSION 3.4.0)
project(LRU)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
set(APP_SRC main.cpp adlist.c)

add_executable(LRU ${APP_SRC})