#include "gtest/gtest.h"
#include "automata.h"

TEST(Constructor, test1) {
Automata test;
EXPECT_EQ(test.getState(), OFF);
}

TEST(STATES, test1) {
Automata test;
test.on();
EXPECT_EQ(test.getState(), WAIT);
}

TEST(STATES, test2) {
Automata test;
test.on();
test.coin(50);
EXPECT_EQ(test.getState(), ACCEPT);
}

TEST(coin, test1) {
Automata test;
test.on();
test.coin(500);
EXPECT_EQ(test.getCash(), 500);
}

TEST(coin, test2) {
Automata test;
test.on();
test.coin(25);
test.coin(4);
EXPECT_EQ(test.getCash(), 29);
}

TEST(coin, test3) {
Automata test;
test.on();
test.coin(146587);
test.coin(33);
test.coin(90);
EXPECT_EQ(test.getCash(), 146710);
}

TEST(cook, test1) {
Automata test;
test.on();
test.coin(10);
test.choice(1);
EXPECT_EQ(test.getState(), WAIT);   //  Мы не смогли оплатить, деньги вернулись покупателю
}

TEST(cook, test2) {
Automata test;
test.on();
test.coin(40);
test.choice(1);
EXPECT_EQ(test.getState(), WAIT);   // Покупатель получил свой товар
}

TEST(cook, test3) {
Automata test;
test.on();
test.coin(30);
test.choice(5);
EXPECT_EQ(test.getState(), WAIT);   // Покупатель получил свой товар
}


TEST(cancel, test1) {
Automata test;
test.cancel();
EXPECT_EQ(test.getState(), OFF);    // Мы не можем отменить выключенный аппарат
}

TEST(cancel, test2) {
Automata test;
test.on();
test.cancel();
EXPECT_EQ(test.getState(), WAIT);
}

TEST(cancel, test3) {
Automata test;
test.on();
test.coin(30);
EXPECT_EQ(test.getState(), WAIT);
}