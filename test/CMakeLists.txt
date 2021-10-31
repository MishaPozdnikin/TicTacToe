project(TIC-TAC-TOE-TEST)

set(Sources tic-tac-toe-test.cpp
    main.cpp
    )

add_executable(TIC-TAC-TOE-TEST ${Sources})


add_test(
    NAME TIC-TAC-TOE-TEST
    COMMAND TIC-TAC-TOE-TEST
    )
target_include_directories(TIC-TAC-TOE-TEST PUBLIC ../src) 
target_link_libraries(TIC-TAC-TOE-TEST PUBLIC tic_tac_toe-lib gtest_main)
