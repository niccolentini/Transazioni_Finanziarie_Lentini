//
// Created by nicco on 16/07/21.
//
#include "../BankAccount.h"
#include <gtest/gtest.h>

TEST(BankAccount, InitialZero){
    BankAccount bA(0);
    ASSERT_EQ(0, bA.getBalance());
    ASSERT_EQ(0, bA.transazioni.size());
}

TEST(BankAccount, changeBalance){
    BankAccount bA2(0, 500);
    bA2.recharge(500);
    ASSERT_EQ(1000, bA2.getBalance());
    bA2.withdraw(600);
    ASSERT_EQ(400, bA2.getBalance());

    bA2.recharge(-5);
    ASSERT_EQ(400, bA2.getBalance());
    bA2.withdraw(1000);
    ASSERT_EQ(400, bA2.getBalance());

}
