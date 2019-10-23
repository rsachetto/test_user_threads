cmake_minimum_required(VERSION 3.15)
project(test_user_threads C)

set(CMAKE_C_STANDARD 11)
link_directories(../user_threads/cmake-build-debug/)


add_executable(test_user_threads
        main.c)
target_link_libraries(test_user_threads user_threads)

