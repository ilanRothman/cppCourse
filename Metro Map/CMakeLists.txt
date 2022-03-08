cmake_minimum_required(VERSION 3.21)
project(MetroMap)

set(CMAKE_CXX_STANDARD 98)

add_executable(MetroMap main.cpp Map.h Simulator.cpp Simulator.h Car.h FamilyCar.h Car.cpp LuxuryCar.h SportsCar.h Maserati.h Junction.cpp Junction.h Metropolis.h Road.h Metropolis.cpp Road.cpp FamilyCar.cpp LuxuryCar.cpp SportsCar.cpp Maserati.cpp)
