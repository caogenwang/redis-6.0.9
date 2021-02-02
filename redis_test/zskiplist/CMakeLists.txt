cmake_minimum_required(VERSION 3.4.0)
project(zskiplist)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
set(APP_SRC main.c sds.c zskiplist.c)

add_executable(zskiplist ${APP_SRC})