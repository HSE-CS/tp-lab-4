#include "gtest/gtest.h"
#include "automata.h"

TEST(init, expect_error)
{
	Automata CoffeeMashine;
	EXPECT_TRUE(CoffeeMashine.off());
}

TEST(init, expect_no_error)
{
	Automata CoffeeMashine;
	EXPECT_FALSE(CoffeeMashine.on());
}

TEST(off, expect_no_error)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	EXPECT_FALSE(CoffeeMashine.off());
}

TEST(coins, expect_error)
{
	Automata CoffeeMashine;
	EXPECT_TRUE(CoffeeMashine.coin(24));
}

TEST(coins, expect_no_error)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	EXPECT_FALSE(CoffeeMashine.coin(24));
}

TEST(choice, expect_error)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	CoffeeMashine.coin(62);
	EXPECT_TRUE(CoffeeMashine.choice(10));
}

TEST(choice, expect_no_error)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	CoffeeMashine.coin(120);
	EXPECT_FALSE(CoffeeMashine.choice(3));
}

TEST(check, expect_error)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	CoffeeMashine.coin(20);
	CoffeeMashine.choice(1);
	EXPECT_TRUE(CoffeeMashine.check());
}

TEST(cook, expect_error)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	CoffeeMashine.coin(15);
	CoffeeMashine.choice(1);
	CoffeeMashine.check();
	EXPECT_EQ(0, CoffeeMashine.cook());
}

TEST(cook, expect_no_error)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	CoffeeMashine.coin(9);
	CoffeeMashine.coin(11);
	CoffeeMashine.choice(1);
	CoffeeMashine.check();
	EXPECT_EQ(1, CoffeeMashine.cook());
}

TEST(cook, expect_order1)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	CoffeeMashine.coin(40);
	CoffeeMashine.choice(2);
	CoffeeMashine.check();
	EXPECT_EQ(2, CoffeeMashine.cook());
}

TEST(cancel, expect_extra1)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	CoffeeMashine.coin(10);
	CoffeeMashine.coin(10);
	EXPECT_EQ(20, CoffeeMashine.cancel());
}

TEST(cook, expect_order2)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	CoffeeMashine.coin(10);
	CoffeeMashine.choice(2);
	CoffeeMashine.check();
	CoffeeMashine.coin(10);
	CoffeeMashine.choice(1);
	CoffeeMashine.check();
	EXPECT_EQ(1, CoffeeMashine.cook());
}


TEST(cancel, expect_extra2)
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	CoffeeMashine.coin(50);
	CoffeeMashine.choice(2);
	CoffeeMashine.check();
	CoffeeMashine.cook();
	EXPECT_EQ(10, CoffeeMashine.cancel());
}
