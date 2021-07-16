cmake_minimum_required(VERSION 3.5)

add_subdirectory(./googletest)
set(gtest_SOURCE_DIR, ./googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES UserTest.cpp BankAccountTest.cpp)
add_executable(TransazioniFinanziarie_test ${TEST_SOURCE_FILES})
target_link_libraries(TransazioniFinanziarie_test gtest gtest_main core)