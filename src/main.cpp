// Copyright 2020 GHA Test Team
#include "Automata.h"


int main() {
  Automata a;
  a.getMenu();
  std::cout << std::endl;
  a.on();
  std::cout << "Current state is: " << a.getState() << std::endl;
  a.coin(50.0);
  std::cout << "Current state is: " << a.getState() << std::endl;
  a.coin(20.0);
  std::cout << "Current state is: " << a.getState() << std::endl;
  a.choice("vodka");
  std::cout << "Current state is: " << a.getState() << std::endl;
  a.choice("coffee");
  std::cout << "Current state is: " << a.getState() << std::endl;
  a.cook();
  std::cout << "Current state is: " << a.getState() << std::endl;
  double change = a.finish();
  std::cout << "Current state is: " << a.getState() << " Change is: " << change << std::endl;
  a.off();
  std::cout << "Current state is: " << a.getState() << std::endl;
  return 0;
}
