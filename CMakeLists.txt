cmake_minimum_required(VERSION 3.30)
project(practice)

set(CMAKE_CXX_STANDARD 20)

add_executable(practice main.cpp
        lambdaFunctions.cpp
        threadsWithLambdaFunc.cpp
        WriterReaderMutex.cpp
        dataRaceExample.cpp)
