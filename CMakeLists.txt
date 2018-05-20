cmake_minimum_required(VERSION 2.8)
project(rover_ai)
find_package(WiringPi REQUIRED)
include_directories(include ${WIRINGPI_INCLUDE_DIRS})
file(GLOB SOURCES "src/*.cpp")
add_executable(motor ${SOURCES})
target_link_libraries(motor ${WIRINGPI_LIBRARIES}) 

