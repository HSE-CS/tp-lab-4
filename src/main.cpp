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
    hall.cancel(); //not enough money return back 45 coins

  //try again
  hall.coin(10);
  hall.coin(10);
  hall.coin(10);
  hall.coin(10);
  hall.coin(5);
  hall.coin(5);

  hall.choice("herbal tea");
  if (hall.check())
    hall.cook();
  else
    hall.cancel();
}