#include "gtest/gtest.h"
#include "automata.h"

TEST(Auto, test1)
{
    Automata automata;
    EXPECT_EQ(Off, automata.getState());
}

TEST(Auto, test2)
{
    Automata automata;
    automata.on();
    EXPECT_EQ(Wait, automata.getState());
}

TEST(Auto, test3)
{
    Automata automata;
    automata.on();
    automata.coin(100);
    EXPECT_EQ(Accept, automata.getState());
}

TEST(Auto, test4)
{
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(6);
    EXPECT_EQ(Wait, automata.getState());
}

TEST(Auto, test5)
{
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice(6);
    EXPECT_EQ(Wait, automata.getState());
}

TEST(Auto, test6)
{
    Automata automata;
    automata.coin(100);
    automata.choice(6);
    EXPECT_EQ(Off, automata.getState());
}

TEST(Auto, test7)
{
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(6);
    EXPECT_DOUBLE_EQ(80, automata.getCash());
}

TEST(Auto, test8)
{
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(6);
    automata.getCash();
    EXPECT_EQ(Off, automata.getState());
}

TEST(Auto, test9)
{
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(6);
    automata.getCash();
    EXPECT_DOUBLE_EQ(0, automata.getCash());
}

TEST(Auto, test10)
{
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(6);
    automata.coin(100);
    automata.choice(7);
    automata.coin(100);
    automata.choice(10);
    automata.coin(100);
    automata.choice(1);
    automata.coin(100);
    automata.choice(3);
    EXPECT_DOUBLE_EQ(330, automata.getCash());
}

TEST(Auto, test11)
{
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.cancel();
    EXPECT_EQ(Wait, automata.getState());
}