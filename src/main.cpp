#include "Automata.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  Automata machine;

  cout << STATES(machine.getState()) << '\n';
  machine.on();
  cout << STATES(machine.getState()) << '\n';
  machine.coin(100);
  cout << STATES(machine.getState()) << '\n';
  machine.choice("coffee");
}
