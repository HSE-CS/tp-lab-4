#include "gtest/gtest.h"
#include "Automata.h"


TEST(automata, test1)
{

    Automata automata;

    STATES tmp = automata.getState();
    EXPECT_EQ(STATES::OFF, tmp);
}

TEST(automata, test2)
{
    Automata automata;
    automata.on();

    STATES tmp = automata.getState();
    EXPECT_EQ(STATES::WAIT, tmp);
}

TEST(automata, test3)
{
    Automata automata;
    automata.on();
    automata.off();

    States tmp = automata.getState();
    EXPECT_EQ(STATES::OFF, tmp);
}

TEST(automata, test4)
{
    Automata automata;
    automata.on();

    unsigned int tmp = automata.getCash();
    EXPECT_EQ(0, tmp);
}

TEST(automata, test5) {
    Automata automata;
    automata.on();
    automata.coin(154);

    unsigned int tmp = automata.getCash();
    EXPECT_EQ(154, tmp);
}

TEST(automata, test6)
{
    Automata automata;
    automata.on();
    std::vector<std::string> menu = automata.getMenu();
    std::map<std::string, unsigned int> prices = automata.getPrices();
    std::string drink = menu[3];
    unsigned int price = prices[drink];
    automata.coin(price);
    automata.choice(drink);
    unsigned int tmp = automata.getCash();
    EXPECT_EQ(0, tmp);
}

TEST(automata, test7)
{
    Automata automata;
    automata.on();
    std::vector<std::string> menu = automata.getMenu();
    std::map<std::string, unsigned int> prices = automata.getPrices();
    std::string drink = menu[0];
    unsigned int price = prices[drink];
    automata.coin(price - 1);
    automata.choice(drink);
    unsigned int tmp = automata.getCash();
    EXPECT_EQ(price - 1, tmp);
}

TEST(automata, test8)
{
    Automata automata;
    automata.on();
    std::vector<std::string> menu = automata.getMenu();
    std::map<std::string, unsigned int> prices = automata.getPrices();
    std::string drink = menu[3];
    unsigned int price = prices[drink];
    automata.coin(price + 50);
    automata.choice(drink);
    STATES tmp = automata.getStates();
    EXPECT_EQ(STATES::WAIT, tmp);
}

TEST(automata, test9)
{
    Automata automata;
    automata.on();
    std::vector<std::string> menu = automata.getMenu();
    std::map<std::string, unsigned int> prices = automata.getPrices();
    std::string drink = menu[2];
    unsigned int price = prices[drink];
    automata.coin(price - 5);
    automata.choice(drink);
    STATES tmp = automata.getStates();
    EXPECT_EQ(STATES::WAIT, tmp);
}

