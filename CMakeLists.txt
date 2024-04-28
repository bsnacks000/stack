cmake_minimum_required(VERSION 3.26)

project(stack)


set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

set(LIBRARY_NAME stack)

add_executable(${LIBRARY_NAME}_test test.c)
target_compile_options(${LIBRARY_NAME}_test PRIVATE -Wall -Wextra -Wpedantic -Werror)

enable_testing()

add_test(NAME test COMMAND ${LIBRARY_NAME}_test)