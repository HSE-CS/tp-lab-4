#include "gtest/gtest.h"
#include "automata.h"

TEST(init, expect_error)
{
	Automata machine;
	EXPECT_TRUE(machine.off());
}

TEST(init, expect_no_error)
{
	Automata machine;
	EXPECT_FALSE(machine.on());
}

TEST(off, expect_no_error)
{
	Automata machine;
	machine.on();
	EXPECT_FALSE(machine.off());
}

TEST(coins, expect_error)
{
	Automata machine;
	EXPECT_TRUE(machine.coin(10));
}

TEST(coins, expect_no_error)
{
	Automata machine;
	machine.on();
	EXPECT_FALSE(machine.coin(10));
}

TEST(choice, expect_error)
{
	Automata machine;
	machine.on();
	machine.coin(50);
	EXPECT_TRUE(machine.choice(10));
}

TEST(choice, expect_no_error)
{
	Automata machine;
	machine.on();
	machine.coin(50);
	EXPECT_FALSE(machine.choice(3));
}

TEST(check, expect_error)
{
	Automata machine;
	machine.on();
	machine.coin(10);
	machine.choice(1); // cost = 20
	EXPECT_TRUE(machine.check());
}

TEST(check, expect_no_error)
{
	Automata machine;
	machine.on();
	machine.coin(10);
	machine.coin(10);
	machine.choice(1); // cost = 20
	EXPECT_FALSE(machine.check());
}

TEST(cook, expect_error)
{
	Automata machine;
	machine.on();
	machine.coin(10);
	machine.choice(1); // cost = 20
	machine.check();
	EXPECT_TRUE(machine.cook());
}

TEST(cook, expect_no_error)
{
	Automata machine;
	machine.on();
	machine.coin(10);
	machine.coin(10);
	machine.choice(1); // cost = 20
	machine.check();
	EXPECT_FALSE(machine.cook());
}

TEST(cook, expect_order1)
{
	Automata machine;
	machine.on();
	machine.coin(40);
	machine.choice(2); // cost = 40
	machine.check();
	EXPECT_EQ(2, machine.cook()); // order #2 returned
}

TEST(cook, expect_order2)
{
	Automata machine;
	machine.on();
	machine.coin(10);
	machine.choice(2); // cost = 40
	machine.check();
	machine.coin(10);
	machine.choice(1); // cost = 10
	machine.check();
	EXPECT_EQ(1, machine.cook()); // order #1 returned
}

TEST(cancel, expect_extra1)
{
	Automata machine;
	machine.on();
	machine.coin(10);
	machine.coin(10);
	EXPECT_EQ(20, machine.cancel());
}

TEST(cancel, expect_extra2)
{
	Automata machine;
	machine.on();
	machine.coin(50);
	machine.choice(2); // cost = 40
	machine.check();
	machine.cook();
	EXPECT_EQ(10, machine.cancel()); // 50 - 40 = 10
}
