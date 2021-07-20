//
// Created by nicco on 16/07/21.
//
#include "../BankAccount.h"
#include <gtest/gtest.h>

TEST(BankAccount, InitialZero){
    BankAccount bA(0);
    ASSERT_EQ(0, bA.getBalance());
    ASSERT_EQ(0, bA.vectorTransactionSize());
}

TEST(BankAccount, changeBalance){
    BankAccount bA2(0, 500);
    bA2.recharge(500);
    ASSERT_EQ(1000, bA2.getBalance());
    bA2.withdraw(600);
    ASSERT_EQ(400, bA2.getBalance());
}

TEST(BankAccount, getters){
    BankAccount bA(12, 500);
    ASSERT_EQ(12, bA.getBankAccountNumber());
    ASSERT_EQ(500, bA.getBalance());
}

TEST(BankAccount, exceptions){
    BankAccount bA(0);
    BankAccount bA2(1);
    ASSERT_THROW(bA.recharge(-10), std::out_of_range);
    ASSERT_THROW(bA.withdraw(-10), std::out_of_range);
    ASSERT_THROW(bA.nuovaTransazione(true, bA2, -100, false), std::out_of_range);
}

TEST(BankAccount, files){
    ofstream tfile;
    tfile.open("testfile.txt");
    tfile<<"testing";
    tfile.close();
    ifstream testfile;
    testfile.open("testfile.txt");
    string line;
    while( getline (testfile, line)){
        ASSERT_EQ("testing", line);
    }
    testfile.close();
}