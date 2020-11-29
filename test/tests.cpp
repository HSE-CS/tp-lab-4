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
   automata.coin(174);
   States tmp = automata.getState();
   EXPECT_EQ(STATES::ACCEPT, tmp);
}

TEST(automata, test5) {
    Automata automata;
    automata.on();
    automata.coin(174);
    int tmp = automata.cansel();
    EXPECT_EQ(174, tmp);
}

TEST(automata, test6)
{
    Automata automata;
    automata.on();
    automata.coin(174);
    automata.choice(1);
    bool tmp= automata.check();
    EXPECT_EQ(true, tmp);
}

TEST(automata, test7)
{
    Automata automata;
    automata.on();
    automata.coin(174);
    automata.choice(1);
    States tmp = automata.getState();
   EXPECT_EQ(STATES::CHECK, tmp);   
}

TEST(automata, test8)
{
    Automata automata;
    automata.on();
    automata.coin(174);
    automata.choice(1);
    automata.cook ();
    States tmp = automata.getState();
    EXPECT_EQ(STATES::COOK, tmp);   
}

TEST(automata, test9)
{
    Automata automata;
    automata.on();
    automata.coin(174);
    automata.choice(1);
    automata.cook ();
    automata.finish();
    States tmp = automata.getState();
    EXPECT_EQ(STATES::WAIT, tmp);    
}

TEST(automata, test10)
{
    Automata automata;
    automata.on();
    automata.coin(174);
    automata.choice(1);
    automata.cook ();
    int tmp =automata.finish();
    EXPECT_EQ(154, tmp);    
}
