cmake_minimum_required(VERSION 3.25)
project(rzd)

set(CMAKE_CXX_STANDARD 23)

add_executable(rzd main.cpp
        cars/cars.h
        cars/car.h cars/car.cpp
        cars/coach.h cars/coach.cpp
        cars/compartment.h cars/compartment.cpp
        cars/couchette.h cars/couchette.cpp
        cars/errors/car_error.h cars/errors/toilet_error.h
        cars/components/toilet.h cars/components/toilet.cpp)
