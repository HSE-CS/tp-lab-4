#ifndef LAB_4__AUTOMATA_H_
#define LAB_4__AUTOMATA_H_

#include <map>
#include <iostream>

enum STATES {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata {
 public:
  explicit Automata(STATES state = OFF);
  void on();
  void off();
  void coin(int money);
  std::map<std::string, int> getMenu();
  STATES getState();
  std::string choice(std::string order);
  bool check(const std::string &user_order);
  void cancel();
  bool cook();
  int getBalance() const; // узнать свой баланс
  void finish();

 private:
  int cash; // для хранения текущей суммы
  std::string order;
  std::map<std::string, int> price_menu;  // menu
  STATES state; //текущее состояние автомата
};

#endif //LAB_4__AUTOMATA_H_
