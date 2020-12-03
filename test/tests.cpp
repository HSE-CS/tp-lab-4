#include "gtest/gtest.h"
#include "Automata.h"

TEST(automata, test1){
    Automata A;
    STATES expected = OFF;
    EXPECT_EQ(expected, A.getState());
}

TEST(automata, test2){
    Automata A;
    A.on();
    STATES expected = WAIT;
    EXPECT_EQ(expected, A.getState());
}

TEST(automata, test3){
    Automata A;
    A.on();
    A.coin(2);
    STATES expected = ACCEPT;
    EXPECT_EQ(expected, A.getState());
}

TEST(automata, test4){
    Automata A;
    A.coin(2);
    STATES expected = OFF;
    EXPECT_EQ(expected, A.getState());
}

TEST(automata, test5){
    Automata A;
    A.on();
    A.coin(2);
    A.choice();
    STATES expected = CHECK;
    EXPECT_EQ(expected, A.getState());
}

TEST(automata, test6){
    Automata A;
    A.on();
    A.coin(1);
    A.choice();
    A.check(1);
    STATES expected = CHECK;
    EXPECT_EQ(expected, A.getState());
}

TEST(automata, test7){
    Automata A;
    A.on();
    A.coin(2);
    A.choice();
    A.check(1);
    STATES expected = WAIT;
    EXPECT_EQ(expected, A.getState());
}

TEST(automata, test8){
    Automata A;
    A.on();
    A.coin(2);
    A.choice();
    A.cancel();
    STATES expected = WAIT;
    EXPECT_EQ(expected, A.getState());
}