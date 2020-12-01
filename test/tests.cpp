#include "gtest/gtest.h"
#include "Automata.h"


TEST(Automata, check_state_on) {  // 1
  Automata automata;
  automata.on();
  ASSERT_EQ(WAIT, automata.getState());
}

TEST(Automata, check_state_off) { // 2
  Automata automata;
  automata.off();
  ASSERT_EQ(OFF, automata.getState());
}

TEST(Automata,check_money) {  // 3
  Automata automata;
  automata.on();
  automata.coin(150);
  ASSERT_EQ(150, automata.getBalance());
}


TEST(Automata,check_cook_after_creation) {  // 4
  Automata automata;
  ASSERT_FALSE(automata.cook());
}

TEST(Automata,check_true) {  // 5
  Automata automata;
  automata.on();
  automata.coin(300);
  std::string choice = automata.choice("Raw");
  ASSERT_TRUE(automata.check(choice));
}

TEST(Automata,check_order) {  // 6
  Automata automata;
  automata.on();
  automata.coin(150);
  ASSERT_EQ("Frappe", automata.choice("Frappe"));
}

TEST(Automata,check_show_menu) {  // 7
  Automata automata;
  automata.on();
  std::map<std::string, int> menu = {{"Cappuccino", 100},
                                     {"Cocoa", 150},
                                     {"Latte", 120},
                                     {"Espresso", 70},
                                     {"Frappe", 150},
                                     {"Raw", 200},
                                     {"Green Tea", 55},
                                     {"Black Tea", 50},
                                     {"Milk", 60},
                                     {"Sugar", 0}}; ;
  ASSERT_EQ(menu, automata.getMenu());
}

TEST(Automata,check_false) {  // 8
  Automata automata;
  automata.on();
  automata.coin(100);
  std::string choice = automata.choice("Raw");
  ASSERT_FALSE(automata.check(choice));
}

TEST(Automata,check_normal_cook) {  // 9
  Automata automata;
  automata.on();
  automata.coin(300);
  std::string choice = automata.choice("Raw");
  automata.check(choice);
  ASSERT_TRUE(automata.cook());
}

TEST(Automata, check_finish) { // 10
  Automata automata;
  automata.on();
  automata.coin(300);
  std::string choice = automata.choice("Raw");
  automata.check(choice);
  automata.cook();
  automata.finish();
  ASSERT_EQ(WAIT, automata.getState());
}