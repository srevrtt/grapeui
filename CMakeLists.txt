cmake_minimum_required(VERSION 3.0)
project(GrapeUI VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(GRAPE_SRCS grape/Main.cpp grape/Lexer.cpp grape/Utils.cpp grape/Parser.cpp grape/Tree.cpp grape/GenKotlin.cpp)

add_executable(GrapeUI ${GRAPE_SRCS})
