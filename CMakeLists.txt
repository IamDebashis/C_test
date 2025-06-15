cmake_minimum_required(VERSION 3.31)
project(C_test C)

set(CMAKE_C_STANDARD 11)

add_executable(C_test main.c
        infixPrefix/InfixPrefixPostfix.c
        stack/Stack.h
        stack/Stack.c
        infixPrefix/InfixPrefix.h
)
