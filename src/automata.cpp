#include "automata.h"
std::vector <std::string> drinks{"hot water",
                                 "lemon tea",
                                 "black tea",
                                 "green tea",
                                 "herbal tea"};
std::vector <int> cost{10,
                       20,
                       30,
                       40,
                       50};

automata::automata() {
    cash_automata = 0;
    cash_user = 0;
    choice_user = 0;
    state = OFF;
    menu = drinks;
    prices = cost;
}

std::string automata::getMenu() {
    if (getState() == WAIT) {
      std::string overview;
      for (unsigned int num = 0; num < prices.size(); num++){
        overview += (menu[num] + " " + std::to_string(prices[num])
                     + " coins" + "\n");
      }
      return overview;
   }
    else
      std::cerr << "Please, turn on the automata" << std::endl;

  return nullptr;
}

void automata::on() {
    state = ON;
    state = WAIT;
}

void automata::off() {
    state = OFF;
}

void automata::coin(int coins) {
    if (getState() == WAIT)
      cash_user += coins;
    else
      std::cerr << "Please, turn on the automata" << std::endl;
}

states automata::getState() {
    return state;
}

void automata::choice(const std::string& user_choice) {
    this->choice_user = 0;
    for (auto &position : menu)
      if (position == user_choice)
        break;
      else
        this->choice_user++;

    if (user_choice != menu[this->choice_user]) {
      std::cerr << "wrong name" << std::endl;
      cancel();
    }
}

bool automata::check() {
    if (prices[this->choice_user] > cash_user)
      return false;
    else
      return true;
}

int automata::cancel() {
    int enter_coins = this->cash_user;
    this->cash_user = 0;
    this->choice_user = 0;
    this->state = WAIT;
    std::cout << "Please, take your extra money back " << enter_coins << std::endl;
    return enter_coins;
}

void automata::cook() {
    this->cash_automata += prices[this->choice_user];
    this->cash_user -= prices[this->choice_user];
    std::cout << "Thank u, take your drink, have a nice day"  << std::endl;
}

void automata::finish() {
    cancel();
}