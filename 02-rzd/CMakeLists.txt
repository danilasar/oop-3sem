cmake_minimum_required(VERSION 3.25)
project(rzd)

set(CMAKE_CXX_STANDARD 23)

add_executable(rzd main.cpp trains/vagon.h trains/vagon.cpp trains/platscard.h trains/platscard.cpp trains/coupe.h trains/coupe.cpp trains/special.h trains/special.cpp)
