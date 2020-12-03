#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4, test1)
{
    Automata* automata = new Automata();
    automata->choice("Milk");
    int i = automata->getState();
    EXPECT_EQ(0, i);
}

TEST(lab4, test2)
{
    Automata* automata = new Automata();
    automata->on();
    int i = automata->getState();
    EXPECT_EQ(1, i);
}

TEST(lab4, test3)
{
    Automata* automata = new Automata();
    automata->on();
    automata->printMenu();
    automata->coin(100);
    automata->choice("Milk");
    automata->cook();
    int i = automata->getProfit();
    EXPECT_EQ(10, i);
}

TEST(lab4, test4)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    automata->choice("Milk");
    automata->cancel();
    int i = automata->getProfit();
    EXPECT_EQ(0, i);
}

TEST(lab4, test5)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    automata->choice("Milk");
    automata->cancel();
    automata->off();
    int i = automata->getState() ;
    EXPECT_EQ(0, i);
}
TEST(lab4, test6)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(5);
    automata->choice("Tea");
    int i = automata->getState();
    EXPECT_EQ(2, i);
}
TEST(lab4, test7)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    int i = automata->getState();
    EXPECT_EQ(2, i);
}
TEST(lab4, test8)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    automata->choice("Milk");
    int i = automata->getState();
    EXPECT_EQ(3, i);

}

TEST(lab4, test9)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    automata->choice("Coffee");
    automata->cook();
    int i = automata->getProfit();
    EXPECT_EQ(40, i);
}
TEST(lab4, test10)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    automata->choice("Coffee");
    automata->reset();
    int i = automata->getState();
    EXPECT_EQ(1, i);
}

TEST(lab4, test11)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    automata->choice("Coffee");
    automata->cook();
    automata->coin(50);
    automata->choice("Coffee");
    automata->cook();
    automata->coin(5000);
    automata->choice("Coffee");
    automata->cook();

    int i = automata->getProfit();
    EXPECT_EQ(120, i);
}

TEST(lab4, test12)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    automata->choice("Milk");
    automata->cancel();
    automata->coin(50);
    automata->cancel();
    automata->cook();

    automata->coin(5);
    automata->choice("Coffee");
    automata->cook();

    int i = automata->getProfit();
    EXPECT_EQ(0, i);
}

TEST(lab4, test13)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    automata->choice("Milk");
    automata->cook();
    automata->off();
 
    int i = automata->getProfit();
    EXPECT_EQ(10, i);
}

TEST(lab4, test14)
{
    Automata* automata = new Automata();
    automata->on();
    automata->coin(100);
    automata->choice("Milk");
    automata->cook();
    automata->off();
    automata->coin(1);
    automata->choice("Milk");
    automata->cook();

    automata->coin(50);
    automata->choice("Tea");
    automata->cook();

    automata->on();
    automata->choice("Tea");
    automata->cook();

    automata->coin(1000);
    automata->choice("Cola");
    automata->cook();

    int i = automata->getProfit();
    EXPECT_EQ(60, i);
}
