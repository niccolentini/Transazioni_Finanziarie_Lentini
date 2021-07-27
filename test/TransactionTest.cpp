//
// Created by nicco on 27/07/21.
//

#include "../Transaction.h"
#include <gtest/gtest.h>

TEST(transaction, creation){
    ASSERT_THROW(Transaction t(1,2,-500, "data", true), std::invalid_argument);
    ASSERT_THROW(Transaction t(1,1,30,"data", true), std::invalid_argument);
}