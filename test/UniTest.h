//
// Created by tao on 2021/1/12.
//

#ifndef RE_UNITEST_H
#define RE_UNITEST_H


#include <gtest/gtest.h>
#include <glog/logging.h>
#include "../src/Utils.h"


TEST(TestM2B, testSuccess) {
    std::string reg = "(a|b)*c";
    auto r = insertExplicitConcatOperator(reg);
    EXPECT_EQ(r, "(a|b)*#c");
    auto res = m_to_b(r);
    EXPECT_EQ("ab|*c", res);
}

#endif //RE_UNITEST_H