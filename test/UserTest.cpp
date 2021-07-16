//
// Created by nicco on 16/07/21.
//
#include "../User.h"
#include "googletest/googletest/include/gtest/gtest.h"

TEST(User, noAccountStart){
    User u("?","?","?","?");
    ASSERT_EQ(0, u.bankaccount.size());
}
