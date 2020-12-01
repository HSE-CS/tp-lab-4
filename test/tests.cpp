#include "gtest/gtest.h"
#include "Automata.h"

TEST(automata, test0) {
  Automata automata;
  int expected = 0;
  EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test1) {
  Automata automata;
  STATES expected = OFF;
  EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test2) {
  Automata automata;
  automata.on();
  STATES expected = WAIT;
  EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test3) {
  Automata automata;
  automata.on();
  automata.off();
  STATES expected = OFF;
  EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test4) {
  Automata automata;
  automata.on();
  automata.coin(100);
  automata.cancel();
  STATES expected = WAIT;
  EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test5) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.getMenu();
    automata.choice("coffee");
    STATES expected = WAIT;
    EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test6) {
    Automata automata;
    automata.on();
    automata.coin(0);
    automata.getMenu();
    automata.choice("tea");
    STATES expected = WAIT;
    EXPECT_EQ(expected, automata.getState());
}

TEST(automata, test7) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.getMenu();
    automata.choice("tea");
    long expected = 70;
    EXPECT_EQ(expected, automata.getCash());
}

TEST(automata, test8) {
    Automata automata;
    automata.on();
    automata.coin(13);
    automata.getMenu();
    automata.choice("tea");
    long expected = 13;
    EXPECT_EQ(expected, automata.getCash());
}

TEST(automata, test9) {
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.getMenu();
    automata.choice("coffee");
    automata.coin(200);
    automata.getMenu();
    automata.choice("chocolate");

    long expected = 90;
    EXPECT_EQ(expected, automata.getCash());
}
