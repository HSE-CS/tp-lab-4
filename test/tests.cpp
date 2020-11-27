#include "gtest/gtest.h"
#include "Automata.h"

TEST(test_1, test1)
{
    Automata test;
    EXPECT_EQ(OFF, test.getState());
}

TEST(on, test2)
{
    Automata test;
    test.on();
    EXPECT_EQ(WAIT, test.getState());
}

TEST(off, test3)
{
    Automata test;
    test.off();
    EXPECT_EQ(OFF, test.getState());
}

TEST(cancel, test4)
{
Automata test;
test.cancel();
EXPECT_EQ(WAIT, test.getState());
}

TEST(finish, test5)
{
Automata test;
test.finish();
EXPECT_EQ(WAIT, test.getState());
}

TEST(cash_1, test6)
{
    Automata test;
    test.on();
    test.coin(100);
    EXPECT_EQ(100, test.cancel());
}

TEST(cash_2, test7)
{
    Automata test;
    test.on();
    test.coin(25);

    test.choice("tea");
    if (test.check())
        test.cook();
    else
        test.cancel();

    EXPECT_EQ(0, test.cancel());
}

TEST(cash_3, test8)
{
    Automata test;
    test.on();
    test.coin(15);
    test.choice("tea");
    EXPECT_FALSE(test.check());
}


TEST(menu, test9)
{
    Automata test;
    test.on();
    test.coin(50);
    test.choice("tea");
    EXPECT_TRUE(test.check());
}