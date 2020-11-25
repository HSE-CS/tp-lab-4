#include "Automata.h"
#include <iostream>

int main() {
  Automata hall;
  hall.on();

  std::cout << hall.getMenu();
  //want to buy herbal tea 50
  hall.coin(10);
  hall.coin(10);
  hall.coin(10);
  hall.coin(10);
  hall.coin(5);

  hall.choice("herbal tea");
  if (hall.check())
    hall.cook();
  else
    std::cout << "not enough money" << std::endl;

  hall.coin(10); //add money

  hall.choice("black tea");
  if (hall.check())
    hall.cook(); //take the first drink
  else
    std::cout << "not enough money" << std::endl;

  hall.choice("lemon tea");
  if (hall.check())
    hall.cook(); //take the second drink
  else
    std::cout << "not enough money" << std::endl;

  hall.finish(); //take extra money back
}