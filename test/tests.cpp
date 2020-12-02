/*
 * @author Stanislav Stoianov
 */

#include "gtest/gtest.h"
#include "automata.h"

TEST(initialize, expect_no_error) {
    Automata machine;
    EXPECT_FALSE(machine.off());
}

TEST(initialize2, expect_no_error) {
    Automata machine;
    EXPECT_TRUE(machine.on());
}

TEST(off, expect_no_error) {
    Automata machine;
    machine.on();
    EXPECT_TRUE(machine.off());
}

TEST(coin_off, expect_no_error) {
    Automata machine;
    EXPECT_FALSE(machine.coin(10));
}

TEST(coin_on, expect_no_error) {
    Automata machine;
    machine.on();
    EXPECT_TRUE(machine.coin(10));
}

TEST(choice, expect_no_error) {
    Automata machine;
    machine.on();
    machine.coin(50);
    EXPECT_FALSE(machine.choice(15));
}

TEST(choice2, expect_no_error) {
    Automata machine;
    machine.on();
    machine.coin(50);
    EXPECT_TRUE(machine.choice(3));
}

TEST(choice3, expect_no_error) {
    Automata machine;
    machine.on();
    machine.coin(10);
    EXPECT_FALSE(machine.choice(1));
}

TEST(choice4, expect_no_error) {
    Automata machine;
    machine.on();
    machine.coin(6);
    machine.coin(6);
    EXPECT_TRUE(machine.choice(1));
}

TEST(choice5, expect_no_error) {
    Automata machine;
    machine.on();
    machine.coin(10);
    EXPECT_FALSE(machine.choice(1));
}

TEST(cancel, expect_no_error) {
    Automata machine;
    machine.on();
    EXPECT_FALSE(machine.cancel());
}

TEST(cancel2, expect_no_error) {
    Automata machine;
    machine.on();
    machine.coin(7);
    EXPECT_TRUE(machine.cancel());
}