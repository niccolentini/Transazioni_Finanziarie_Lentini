cmake_minimum_required(VERSION 3.5)
project(TransazioniFinanziarie)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES User.h Bank.h BankAccount.h User.cpp Bank.cpp BankAccount.cpp)
add_executable(TransazioniFinanziarie main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(TransazioniFinanziarie core)