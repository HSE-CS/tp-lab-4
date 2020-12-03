#include "Automata.h"

Automata::Automata(STATES state) {
  this->state = state;
  this->cash = 0; // текущая сумма
  this->order = ""; // текущй заказ
  this->price_menu = {{"Cappuccino", 100},
                      {"Cocoa", 150},
                      {"Latte", 120},
                      {"Espresso", 70},
                      {"Frappe", 150},
                      {"Raw", 200},
                      {"Green Tea", 55},
                      {"Black Tea", 50},
                      {"Milk", 60},
                      {"Sugar", 0}};  // menu
}

void Automata::on() {
  this->state = WAIT;
}

void Automata::off() {
  this->state = OFF;
}

void Automata::coin(int money) {
  if (money < 0){
    std::cout << "You enter a negative number!" << std::endl;
    exit(-1);
  }
  STATES st = getState();
  if (st == ACCEPT || st == WAIT) {
    this->state = ACCEPT;
    this->cash += money;
  }
}

std::map<std::string, int> Automata::getMenu() {
  return this->price_menu;
}

STATES Automata::getState() {
  return this->state;
}

std::string Automata::choice(std::string new_order) {
  STATES st = getState();
  if (st == ACCEPT) {
    if (price_menu.find(new_order) == price_menu.end()) {
      std::cout << "No such drink in a menu." << std::endl;
      exit(-1);
    }
    this->state = CHECK;
    this->order = std::move(new_order);
    return this->order;
  } else {
    return "Wrong state of automata: " + std::to_string(this->state);
  }
}

bool Automata::check(const std::string &user_order) {
  bool flg = true;
  STATES st = getState();
  if (st == ACCEPT || st == CHECK) {
    int price = price_menu[user_order];
    if (price <= cash) { // если цена напитка иеньше или == сумме наличности пользователя
      this->state = CHECK;
      this->cash -= price; //  забираем деньги
      flg = true;
    } else {
      this->state = ACCEPT;
      flg = false;
    }
  }
  return flg;
}

void Automata::cancel() {
  STATES st = getState();
  if (st == ACCEPT || st == CHECK) {
    this->state = WAIT;
    this->order = "";
    this->cash = 0;
  }
}

bool Automata::cook() {
  STATES st = getState();
  if (st == CHECK) {
    this->state = COOK;
    this->cash = 0; // в сдачу ушло
    return true;
  }
  return false;
}

void Automata::finish() {
  STATES st = getState();
  if (st == COOK) {
    this->state = WAIT;
  }
}
int Automata::getBalance() const {
  return this->cash;
}
