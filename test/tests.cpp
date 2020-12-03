// Copyright 2020 test
#include "gtest/gtest.h"
#include "Automata.h"

TEST(AutomataTest, test1) {
    Automata test;
    EXPECT_EQ(test.getState(), OFF);  // проверка выключен ли автомат по умолчанию
}

TEST(AutomataTest, test2) {
    Automata test;
    test.on();
    EXPECT_EQ(test.getState(), WAIT);  // меняется ли статус на WAIT
}

TEST(AutomataTest, test3) {
    Automata test;
    test.on();
    test.coin(10);
    EXPECT_EQ(test.getState(), ACCEPT);  // меняется ли статус на ACCEPT
}

TEST(AutomataTest, test4) {
    Automata test;
    test.on();
    test.coin(10);
    test.choice(1);
    EXPECT_EQ(test.getState(), WAIT);  // меняется ли статус на ACCEPT, если мало денег
}

TEST(AutomataTest, test5) {
    Automata test;
    test.on();
    test.coin(40);
    test.choice(1);
    EXPECT_EQ(test.getState(), WAIT);  // меняется ли статус на ACCEPT, если достаточно денег
}

TEST(AutomataTest, test6) {
    Automata test;
    test.on();
    test.coin(1);
    test.finish();
    EXPECT_EQ(test.getState(), 1);  // меняется ли статус при окончании работы
}

TEST(AutomataTest, test7) {
    Automata test;
    test.cancel();
    EXPECT_EQ(test.getState(), 0);              // меняется ли статус, при выключенном автомате при отмене
}

TEST(AutomataTest, test8) {
    Automata test;
    test.finish();
    EXPECT_EQ(test.getState(), 0);               // меняется ли статус, при выключенном автомате при завершении работы
}

TEST(AutomataTest, test9) {
    Automata test;
    test.on();
    test.coin(10);
    test.coin(30);
    EXPECT_EQ(test.getCoin(), 40);             // суммируются ли деньги
}

TEST(AutomataTest, test10) {
    Automata test;
    test.on();
    std::string menu = "1 Americano 25\n2 Espresso 35\n3 Cappuccino 40\n4 Long Black 38\n5 Hot Chocolate 30\n";
    EXPECT_EQ(test.getMenu(), menu);        // проверка меню
}
