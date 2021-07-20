//
// Created by nicco on 16/07/21.
//
#include "../User.h"
#include <gtest/gtest.h>
#include "../BankAccount.h"

TEST(User, noAccountStart){
    User u("user","test","12345","test");
    ASSERT_EQ(0, u.bankAccountVectorSize());
}

TEST(User, getters){
    User u("user","test","12345","test");
    ASSERT_EQ("user", u.getName());
    ASSERT_EQ("test", u.getSurname());
    ASSERT_EQ("12345", u.getTelephoneNumber());
    ASSERT_EQ("test", u.getAddress());
}

TEST(User, exeptions){
    User u("user","test","12345","test");
    ASSERT_THROW(u.findBankAccount(-1), out_of_range);
}
