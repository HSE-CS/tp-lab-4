#include "gtest/gtest.h"
#include "Automata.h"
#include "states.h"

TEST(avtomat, test1)
{
    string menu[]{};
    double price[]{};
    Automata automata{menu, price};
    EXPECT_EQ(OFF, automata.getState());
}

TEST(avtomat, test2)
{
    string menu[]{};
    double price[]{};
    Automata automata{menu, price};
    automata.on();
    EXPECT_EQ(WAIT, automata.getState());
}

TEST(avtomat, test3)
{
    string menu[]{};
    double price[]{};
    Automata automata{menu, price};
    automata.on();
    automata.off();
    EXPECT_EQ(OFF, automata.getState());
}

TEST(avtomat, test4)
{
    string menu[]{};
    double price[]{};
    Automata automata{menu, price};
    automata.coin(30);
    EXPECT_EQ(OFF, automata.getState());
}

TEST(avtomat, test5)
{
    string menu[]{};
    double price[]{};
    Automata automata{menu, price};
    automata.on();
    automata.coin(30);
    EXPECT_EQ(ACCEPT, automata.getState());
}

TEST(avtomat, test6)
{
    string menu[]{};
    double price[]{};
    Automata automata{menu, price};
    automata.on();
    automata.coin(30);
    automata.coin(30);
    EXPECT_EQ(ACCEPT, automata.getState());
}

TEST(avtomat, test7)
{
    string menu[]{"coca cola", "sprite", "fanta"};
    double price[]{55, 59.90, 50};
    Automata automata{menu, price};
    automata.on();
    automata.coin(40);
    automata.choice(0);
    EXPECT_DOUBLE_EQ(40, automata.getCash());
}

TEST(avtomat, test8)
{
    string menu[]{"coca cola", "sprite", "fanta"};
    double price[]{55, 59.90, 50};
    Automata automata{menu, price};
    automata.on();
    automata.coin(60);
    automata.choice(0);
    EXPECT_DOUBLE_EQ(5, automata.getCash());
}

TEST(avtomat, test9)
{
    string menu[]{"coca cola", "sprite", "fanta"};
    double price[]{55, 59.90, 50};
    Automata automata{menu, price};
    automata.on();
    automata.coin(60);
    automata.choice(1);
    EXPECT_DOUBLE_EQ(0.1, automata.getCash());
}

TEST(avtomat, test10)
{
    string menu[]{};
    double price[]{};
    Automata automata{menu, price};
    automata.on();
    automata.coin(40);
    EXPECT_EQ(false, automata.check(0));
}

TEST(avtomat, test11)
{
    string menu[]{};
    double price[]{};
    Automata automata{menu, price};
    automata.on();
    automata.coin(60);
    EXPECT_EQ(true, automata.check(0));
}

TEST(avtomat, test12)
{
    string menu[]{};
    double price[]{};
    Automata automata{menu, price};
    automata.on();
    automata.coin(60);
    automata.cancel();
    EXPECT_EQ(WAIT, automata.getState());
}