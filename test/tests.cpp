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

TEST(finishing, test4) {
  Automata test;
  test.finish();

  EXPECT_EQ(WAIT, test.getState());
}

TEST(canceling, test5) {
  Automata test;
  test.cancel();

  EXPECT_EQ(WAIT, test.getState());
}

TEST(cash1, test6) {
  Automata test;
  test.on();
  test.coin(200);

  EXPECT_EQ(200, test.cancel());
}

TEST(cash2, test7) {
  Automata test;
  test.on();
  test.coin(200);
  test.choice("herbal tea");
  if (test.check())
    test.cook();
  else
    test.cancel();
  test.choice("herbal tea");
  if (test.check())
    test.cook();
  else
    test.cancel();
  test.choice("herbal tea");
  if (test.check())
    test.cook();
  else
    test.cancel();
  test.choice("herbal tea");
  if (test.check())
    test.cook();
  else
    test.cancel();

  EXPECT_EQ(0, test.cancel());
}

TEST(cash3, test8) {
  Automata test;
  test.on();
  test.coin(45);
  test.choice("herbal tea");

  EXPECT_FALSE(test.check());
}

TEST(cash4, test9) {
  Automata test;
  test.on();
  test.coin(50);
  test.choice("herbal tea");

  EXPECT_TRUE(test.check());
}

TEST(menu, test10) {
  Automata test;
  test.on();
  test.coin(50);
  test.choice("herbal tea");

  EXPECT_TRUE(test.check());
}

