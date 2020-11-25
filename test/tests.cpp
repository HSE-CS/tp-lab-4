#include "gtest/gtest.h"
#include "Automata.h"

TEST(constructor, test1) {
  Automata test;
  EXPECT_EQ(OFF, test.getState());
}

TEST(on, test2) {
  Automata test;
  test.on();
  EXPECT_EQ(WAIT, test.getState());
}

TEST(off, test3) {
  Automata test;
  test.off();
  EXPECT_EQ(OFF, test.getState());
}

TEST(finish, test4) {
  Automata test;
  test.finish();
  EXPECT_EQ(WAIT, test.getState());
}

TEST(cash, test5) {
  Automata test;
  test.on();
  test.coin(200);
  EXPECT_EQ(200, test.cash_user);
}

TEST(cash2, test6) {
  Automata test;
  test.on();
  test.coin(200);
  test.choice("herbal tea");
  test.choice("herbal tea");
  test.choice("herbal tea");
  test.choice("herbal tea");
  EXPECT_EQ(200, test.cash_automata);
}

TEST(cash3, test7) {
  Automata test;
  test.on();
  test.coin(55);
  EXPECT_EQ(55, test.cancel());
}

TEST(cash3, test7) {
  Automata test;
  test.on();
  test.coin(55);

  EXPECT_EQ(55, test.cancel());
}