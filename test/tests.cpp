#include "gtest/gtest.h"
#include "Automata.h"
//#include "pch.h"
//#include "../Tp-Lab4/Automata.cpp"


TEST(Automata, StateOff1) {
  Automata a;
  EXPECT_EQ("OFF", a.getState());
}

TEST(Automata, StateOff2) {
  Automata a;
  a.coin(10.0);
  a.cancel();
  EXPECT_EQ("OFF", a.getState());
}

TEST(Automata, StateOff3) {
  Automata a;
  a.on();
  a.off();
  EXPECT_EQ("OFF", a.getState());
}


TEST(Automata, StateWait1) {
  Automata a;
  a.on();
  EXPECT_EQ("WAIT", a.getState());
}

TEST(Automata, StateWait2) {
  Automata a;
  a.on();
  a.coin(10.0);
  a.cancel();
  EXPECT_EQ("WAIT", a.getState());
}

TEST(Automata, StateWait3) {
  Automata a;
  a.on();
  a.coin(100.0);
  a.choice("coca-cola");
  a.cancel();
  EXPECT_EQ("WAIT", a.getState());
}

TEST(Automata, StateWait4) {
  Automata a;
  a.on();
  a.coin(100.0);
  a.choice("coca-cola");
  a.cook();
  a.finish();
  EXPECT_EQ("WAIT", a.getState());
}


TEST(Automata, StateAccept1) {
  Automata a;
  a.on();
  a.coin(10.0);
  EXPECT_EQ("ACCEPT", a.getState());
}

TEST(Automata, StateAccept2) {
  Automata a;
  a.on();
  a.coin(10.0);
  a.coin(20.0);
  a.coin(30.0);
  EXPECT_EQ("ACCEPT", a.getState());
}

TEST(Automata, StateAccept3) {
  Automata a;
  a.on();
  a.coin(10.0);
  a.choice("i am not existing");
  EXPECT_EQ("ACCEPT", a.getState());
}


TEST(Automata, StateCheck1) {
  Automata a;
  a.on();
  a.coin(100.0);
  a.getMenu();
  a.choice("coffee");
  EXPECT_EQ("CHECK", a.getState());
}

TEST(Automata, StateCheck2) {
  Automata a;
  a.on();
  a.coin(100.0);
  a.choice("coca-cola");
  EXPECT_EQ("CHECK", a.getState());
}

TEST(Automata, StateCheck3) {
  Automata a;
  a.on();
  a.coin(100.0);
  a.choice("coca-cola");
  a.check();
  a.check();
  EXPECT_EQ("CHECK", a.getState());
}


TEST(Automata, StateCook1) {
  Automata a;
  a.on();
  a.coin(100.0);
  a.choice("coffee");
  a.cook();
  EXPECT_EQ("COOK", a.getState());
}

TEST(Automata, StateCook2) {
  Automata a;
  a.on();
  a.coin(100.0);
  a.choice("coca-cola");
  a.cook();
  EXPECT_EQ("COOK", a.getState());
}
