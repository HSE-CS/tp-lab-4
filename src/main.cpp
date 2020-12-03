// Copyright 2020 Dev-will-work
#include <iostream>
#include "Automata.h"

int main() {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.cancel();
  automate.coin(50);
  automate.choice("tea", 1);
  automate.getBalance();
  automate.getState();
  automate.off();
  automate.on();
  automate.choice("hot chocolate", 1);
  automate.getBalance();
  automate.getState();
  automate.off();
}
