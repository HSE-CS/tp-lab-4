// Copyright 2020 Dev-will-work
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#include <map>

enum class STATES {
  OFF = 0, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
 private:
  size_t all_income = 0;
  STATES state = STATES::OFF;
  std::map<std::string, size_t> menu {
  {"water", 20},
  {"tea", 30},
  {"coffee", 40},
  {"cocoa", 35},
  {"hot chocolate", 50},
  {"latte", 60}
  };
  void cook(std::string);
  void check(std::string);
  void finish();
  size_t cash = 0;
  uint16_t sugar = 0;

 public:
  Automata();
  void on();
  void off();
  void coin(int);
  const std::map<std::string, size_t>& getMenu();
  const STATES getState();
  const size_t getBalance();
  const size_t getMenuSize();
  void choice(std::string, uint16_t);
  void cancel();
};
void printMenu(std::map<std::string, size_t> menu);
#endif  // INCLUDE_AUTOMATA_H_
