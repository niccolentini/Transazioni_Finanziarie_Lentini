cmake_minimum_required(VERSION 3.19)
project(TransazioniFinanziarie)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES User.h Bank.h BankAccount.h User.cpp Bank.cpp BankAccount.cpp test/BankAccountTest.cpp test/UserTest.cpp)
add_executable(TransazioniFinanziarie main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(TransazioniFinanziarie core)