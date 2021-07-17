//
// Created by nicco on 16/07/21.
//
#include "../User.h"
#include <gtest/gtest.h>

TEST(User, noAccountStart){
    User u("user","test","12345","test");
    ASSERT_EQ(0, u.bankaccount.size());
}
