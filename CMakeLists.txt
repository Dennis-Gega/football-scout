cmake_minimum_required(VERSION 3.15...4.0)
project(football_deals VERSION 1.0
  DESCRIPTION "find undervalued football players"
  LANGUAGES CXX)
add_executable(football_deals ./src/main.cpp ./src/CsvParser.cpp)
