#include "gtest/gtest.h"
#include "Automata.h"

TEST(automata, automata_constructor){
Automata automata;
int expected = 0;
EXPECT_EQ(expected, automata.getState());
}
