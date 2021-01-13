cmake_minimum_required(VERSION 3.17)
project(extentor)

set(CMAKE_CXX_STANDARD 20)

add_executable(extentor main.cpp MorseCode.cpp MorseCode.h string_view.cpp string_view.h array.h Editor.h NameList.h CheckedValue.h Time.cpp Time.h Accumulator.h Encypter.h Polynomial.h)