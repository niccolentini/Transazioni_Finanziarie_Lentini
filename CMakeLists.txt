cmake_minimum_required(VERSION 3.19)
project(TransazioniFinanziarie)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransazioniFinanziarie main.cpp User.cpp User.h Bank.cpp Bank.h BankAccount.cpp BankAccount.h)