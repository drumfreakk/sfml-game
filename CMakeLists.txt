cmake_minimum_required(VERSION 3.12)
project(sfml_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sfml_game
        blocks.cpp
        blocks.h
        main.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

