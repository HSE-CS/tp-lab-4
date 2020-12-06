
#include <gtest/gtest.h>
#include "Automata.h"

TEST(Automata, test_on) {
	Automata automata;
	automata.on();
	EXPECT_EQ(WAIT, automata.getState());
}

TEST(Automata, test_off) {
	Automata automata;
	automata.off();
	EXPECT_EQ(OFF, automata.getState());
}

TEST(Automata, test_coin) {
	Automata automata;
	automata.coin(10);
	EXPECT_EQ(ACCEPT, automata.getState());
}

TEST(Automata, test_coin_2) {
	Automata automata;
	automata.coin(10);
	EXPECT_EQ(10, automata.getCash());
}

TEST(Automata, test_coin_3) {
	Automata automata;
	automata.coin(10);
	automata.coin(25);
	EXPECT_EQ(35, automata.getCash());
}

TEST(Automata, test_choice) {
	Automata automata;
	automata.coin(50);
	automata.choice(1);
	EXPECT_EQ(COOK, automata.getState());
}

TEST(Automata, test_choice_with_cash) {
	Automata automata;
	automata.coin(50);
	automata.choice(4);
	EXPECT_EQ(20, automata.getCash());
}

TEST(Automata, test_choice) {
	Automata automata;
	automata.coin(50);
	automata.choice(3);
	EXPECT_EQ(0, automata.getCash());
}

TEST(Automata, test_choice) {
	Automata automata;
	automata.coin(50);
	automata.choice(1);
	automata.finish();
	EXPECT_EQ(WAIT, automata.getState());
}
