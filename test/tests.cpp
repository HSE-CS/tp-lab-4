#include "gtest/gtest.h"
#include "Automata.h"

TEST(automata, test1){
    Automata automata;
    STATES expected = OFF;
    EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test2){
    Automata automata;
    automata.on();
    STATES expected = WAIT;
    EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test3){
    Automata automata;
    automata.on();
    automata.off();
    STATES expected = OFF;
    EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test4){
    Automata automata;
    automata.on();
    automata.coin(60);
    automata.cancel();
    STATES expected = WAIT;
    EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test5){
    Automata automata;
    automata.on();
    automata.coin(70);
    automata.getMenu();
    automata.choice(1);
    STATES expected = WAIT;
    EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test6){
    Automata automata;
    automata.on();
    automata.coin(4);
    automata.getMenu();
    automata.choice(1);
    STATES expected = WAIT;
    EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test7){
    Automata automata;
    automata.on();
    automata.coin(70);
    automata.getMenu();
    automata.choice(1);
    long expected = 40;
    EXPECT_EQ(expected, automata.getCash());
}

TEST(automata, test8){
    Automata automata;
    automata.on();
    automata.coin(13);
    automata.getMenu();
    automata.choice(1);
    long expected = 0;
    EXPECT_EQ(expected, automata.getCash());
}

TEST(automata, test9){
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.getMenu();
    automata.choice(1);

    automata.coin(200);
    automata.getMenu();
    automata.choice(2);

    long expected = 85;
    EXPECT_EQ(expected, automata.getCash());
}

TEST(automata, test10){
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.getMenu();
    automata.choice(1);

    automata.coin(3);
    automata.getMenu();
    automata.choice(2);

    long expected = 40;
    EXPECT_EQ(expected, automata.getCash());
}
