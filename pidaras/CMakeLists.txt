cmake_minimum_required(VERSION 3.28)
project(rzd)

set(CMAKE_CXX_STANDARD 23)

add_executable(rzd main.cpp
        cars/car.cpp
        cars/car.h
        cars/cars.h
        cars/coach.h
        cars/coach.cpp
        cars/compartment.cpp
        cars/compartment.h
        cars/couchette.cpp
        cars/couchette.h
        cars/components/toilet.h
        cars/components/toilet.cpp
        cars/errors/car_error.h
        cars/errors/toilet_error.h
        utils/vector.h
        utils/vector.cpp
        cars/components/seat.cpp
        cars/components/seat.h
        utils/vector_error.cpp
        utils/vector_error.h
)
