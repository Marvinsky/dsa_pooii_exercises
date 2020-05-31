cmake_minimum_required(VERSION 3.10)

project(poo2)

file(GLOB SOURCES "src/*")

add_executable(poo2 main.cpp ${SOURCES})
