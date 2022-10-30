cmake_minimum_required(VERSION 3.23)
project(INF147_TP2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(INF147_TP2
        main.cpp
        mod_cesar.cpp
        mod_cesar.h
        mod_crypt.cpp
        mod_crypt.h
        mod_outils.cpp
        mod_outils.h
        mod_pirater.cpp
        mod_pirater.h
        mod_vigenere.cpp
        mod_vigenere.h)
