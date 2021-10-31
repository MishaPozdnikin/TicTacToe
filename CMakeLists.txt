cmake_minimum_required(VERSION 3.22)
project(TIC-TAC-TOE)

set(CMAKE_C_STANDARD 99)

set(CXXMAKE_C_STANDARD 11)
set(POSITION_INDEPENDENT_CODE ON)

enable_testing()

include_directories(src)
add_subdirectory(test)
add_subdirectory(src)
add_subdirectory(googletest)

add_executable(TIC-TAC-TOE main.c)

target_link_libraries(TIC-TAC-TOE tic_tac_toe-lib)
