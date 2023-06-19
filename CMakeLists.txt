cmake_minimum_required(VERSION 3.25)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled4 main.cpp GameManager.cpp GameManager.h Utils.cpp Utils.h CLI.cpp CLI.h Board.cpp Board.h UI.h GUI.cpp GUI.h)

include_directories(untitled4 "C:\\mingw32\\include")

target_link_libraries(untitled4 "C:\\mingw32\\lib\\libbgi.a")