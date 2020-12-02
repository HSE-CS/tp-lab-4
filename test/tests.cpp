#include "gtest/gtest.h"
#include "automata.h"

TEST(on, expect_no_error)
{
Automata automat;
EXPECT_TRUE(automat.on());
}

TEST(off, expect_no_error)
{
Automata automat;
automat.on();
EXPECT_FALSE(automat.off());
}

TEST(insert_money, expect_error)
{
Automata automat;
EXPECT_TRUE(automat.coin(50));
}

TEST(insert_money, expect_no_error)
{
Automata automat;
automat.on();
EXPECT_FALSE(automat.coin(20));
}

TEST(choice, expect_error)
{
Automata automat;
automat.on();
automat.coin(50);
EXPECT_TRUE(automat.choice(123));
}

TEST(choice, expect_no_error)
{
Automata automat;
automat.on();
automat.coin(50);
EXPECT_FALSE(automat.choice(3));
}

TEST(check, expect_error)
{
Automata automat;
automat.on();
automat.coin(10);
automat.choice(3);
automat.check()
EXPECT_TRUE(automat.getState()==STATES::ACCEPT);
}

TEST(check, expect_no_error)
{
Automata automat;
automat.on();
automat.coin(10);
automat.coin(10);
automat.choice(3);
automat.check()
EXPECT_TRUE(automat.getState()==STATES::COOK);
}

TEST(cook, expect_error)
{
Automata automat;
automat.on();
automat.coin(10);
automat.choice(3);
automat.check();
EXPECT_TRUE(automat.cook())
}

TEST(cook, expect_no_error)
{
Automata automat;
automat.on();
automat.coin(10);
automat.coin(10);
automat.choice(3);
automat.check();
EXPECT_FALSE(automat.cook())
}

TEST(getUserChoice, expect_user_choice_price)
{
Automata automat;
automat.on();
automat.coin(40);
automat.choice(4);
automat.check();
automat.cook()
EXPECT_EQ(40, automat.getUserChoice().price);
}

TEST(getUserChoice, expect_user_choice_price2)
{
Automata automat;
automat.on();
automat.coin(10);
automat.choice(6);
automat.check();
automat.coin(10);
automat.choice(1);
automat.check();
automat.cook()
EXPECT_EQ(10, automat.getUserChoice().price);
}

TEST(getUserCash, expect_extra_money)
{
Automata automat;
automat.on();
automat.coin(10);
automat.coin(10);
EXPECT_EQ(20, automat.getUserCash())
}

TEST(getUserCash, expect_extra_money2)
{
Automata automat;
automat.on();
automat.coin(50);
automat.choice(5);
automat.check();
automat.cook();
EXPECT_EQ(0, automat.getUserCash())
}
