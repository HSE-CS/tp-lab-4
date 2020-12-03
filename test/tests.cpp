//Copyright 2020 Dev-will-work
#include "gtest/gtest.h"
#include "Automata.h"

TEST(Automate, on_creation) {
  Automata automate;
  EXPECT_EQ(automate.getState(), STATES::OFF);
}

TEST(Automate, enable) {
  Automata automate;
  automate.on();
  EXPECT_EQ(automate.getState(), STATES::WAIT);
}

TEST(Automate, disable) {
  Automata automate;
  automate.on();
  automate.off();
  EXPECT_EQ(automate.getState(), STATES::OFF);
}

TEST(Automate, money_taking1) {
  Automata automate;
  automate.on();
  automate.coin(50);
  EXPECT_EQ(automate.getState(), STATES::ACCEPT);
  EXPECT_EQ(automate.getBalance(), 50);
}

TEST(Automate, money_taking2) {
  Automata automate;
  int counter = 5;
  automate.on();
  while (counter > 0) {
    automate.coin(50);
    counter--;
  }
  EXPECT_EQ(automate.getState(), STATES::ACCEPT);
  EXPECT_EQ(automate.getBalance(), 250);
}

TEST(Automate, stop1) {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.cancel();
  EXPECT_EQ(automate.getState(), STATES::WAIT);
  EXPECT_EQ(automate.getBalance(), 0);
}

TEST(Automate, stop2) {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.choice("latte", 2);
  EXPECT_EQ(automate.getBalance(), 50);
  EXPECT_EQ(automate.getState(), STATES::WAIT);
}

TEST(Automate, choose) {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.choice("tea", 1);
  EXPECT_EQ(automate.getBalance(), 20);
  EXPECT_EQ(automate.getState(), STATES::WAIT);
}

TEST(Automate, wrong_choose) {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.choice("approximation", 1);
  EXPECT_EQ(automate.getBalance(), 50);
  EXPECT_EQ(automate.getState(), STATES::WAIT);
  EXPECT_EQ(automate.getMenuSize(), 6);
}

TEST(Automate, wrong_order) {
  Automata automate;
  automate.coin(100);
  EXPECT_EQ(automate.getBalance(), 0);
  EXPECT_EQ(automate.getState(), STATES::OFF);
}

TEST(Automate, cook) {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.choice("hot chocolate", 1);
  EXPECT_EQ(automate.getState(), STATES::WAIT);
  EXPECT_EQ(automate.getBalance(), 0);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
}
