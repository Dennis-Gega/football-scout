cmake_minimum_required(VERSION 3.15...4.0)
project(football_scout VERSION 1.0
  DESCRIPTION "find undervalued football players"
  LANGUAGES CXX)
add_executable(football_scout ./src/main.cpp ./src/CsvParser.cpp
        src/FeatureEngineer.h
        src/FeatureEngineer.cpp)
