//
// Created by tao on 2021/1/12.
//

#include "UniTest.h"


TEST(Base, 4plus4)
{
    std::string a = "ddd";
    std::string b = " ";
    std::string c = " ddd   ";
    deleteAllMark(c, b);
    EXPECT_EQ(a, c);
//    EXPECT_TRUE(true);
}//通过


TEST(Base, Normal)
{
    std::string expr = "a(b|c)*";
    deleteAllMark(expr, " ");
    auto e = insertExplicitConcatOperator(expr);
    EXPECT_EQ(e, std::string("a#(b|c)*"));
    auto te = m_to_b(e);
    auto nfa = NFA();
    auto res = nfa.build(te);
    EXPECT_EQ(1, 1);

}//不通过



TEST(MTOB, success) {
    std::string expr = "(a|b)*#c";
    auto res = m_to_b(expr);
    EXPECT_EQ(res, std::string("ab|*c"));
}


//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}