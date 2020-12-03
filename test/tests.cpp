#include "gtest/gtest.h"
#include "automata.h"

TEST(test_off, test1)
{
    Automata A;
    EXPECT_EQ(OFF, A.getState());
}

TEST(test_on, test2)
{
    Automata A;
    A.on();
    EXPECT_EQ(WAIT, A.getState());
}

TEST(test_coin, test3)
{
    Automata A;
    A.on();
    A.coin(5);
    EXPECT_EQ(ACCEPT, A.getState());
}

TEST(test_cancel, test4)
{
    Automata A;
    A.on();
    A.coin(3);
    EXPECT_EQ(3, A.cancel());
}

TEST(test_cancel2, test5)
{
    Automata A;
    A.on();
    EXPECT_EQ(-1, A.cancel());
}

TEST(test_cancdrink, test6)
{
    Automata A;
    A.on();
    A.coin(20)
    EXPECT_EQ(20, A.choice("milk"));
}

TEST(test_drink, test7)
{
    Automata A;
    A.on();
    A.coin(13)
    EXPECT_EQ(3, A.choice("hot water"));
}





