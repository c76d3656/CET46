cmake_minimum_required(VERSION 3.20)
project(CET46)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
add_executable(CET46 main.cpp EngToCh.cpp EngToCh.h SturctFront.cpp SturctFront.h ChToEng.cpp ChToEng.h)
