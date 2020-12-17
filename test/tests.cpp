  
#include "gtest/gtest.h"
#include "automata.h"

TEST(automata, if_cancel)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(130);
	int cash = automat.cancel();
	EXPECT_EQ(130, cash);
}

TEST(automata, if_not_enough)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(13);
	int cash = automat.choice(1);
	EXPECT_EQ(13, cash);
}

TEST(automata, if_equal)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(40);
	int cash = automat.choice(1);
	EXPECT_EQ(0, cash);
}

TEST(automata, if_more)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(100);
	int cash = automat.choice(1);
	cash = automat.off();
	EXPECT_EQ(60, cash);
}

TEST(automata, more_than_one)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(100);
	int cash = automat.choice(1);
	cash = automat.choice(1);
	cash += automat.off();
	EXPECT_EQ(40, cash);
}