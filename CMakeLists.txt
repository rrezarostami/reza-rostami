cmake_minimum_required(VERSION 3.29)
project(untitled137)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled137 main.cpp
        person.h
        person.cpp
        product.h
        product.cpp
        customer.h
        customer.cpp
        dealer.h
        dealer.cpp
        purchase.h
        purchase.cpp)
