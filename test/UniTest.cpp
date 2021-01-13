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

TEST(asdasdasd, 5plus5)
{
    EXPECT_TRUE(false);
}//不通过



//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}