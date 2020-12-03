#include "automata.h"

int main() {
  Automata automata;
  automata.on();  // TURN ON the automata;

  std::cout << "Position:\t" << "Price:" << std::endl; // PRINT MENU
  for (const auto &item:automata.getMenu()) {
    std::cout << item.first << " -> " << item.second << std::endl;
  }
  std::cout << std::endl;

//  automata.coin(-1); // PUT MONEY
  automata.coin(300); // PUT MONEY
//  automata.coin(0); // PUT MONEY

  ///////////////////////////// 1st purchase  //////////////////////////////////
  std::string choice = automata.choice("Raw"); // CHOOSE DRINK
//  std::string choice = automata.choice("Sugar"); // CHOOSE DRINK

  if (automata.check(choice)) {  // CHECK MONEY
    std::cout << "You choose: " << choice << ". It's started to cook!" << std::endl;
    std::cout << "You balance: " << automata.getBalance() << '.' << std::endl;

    if (automata.cook()) { // START TO COOK
      std::cout << "You order is ready!\n" << std::endl;

      automata.finish();  // FINISH
    }

  } else {
    std::cout << "You balance: " << automata.getBalance() << '.' << std::endl;
    automata.cancel();  // CANCEL

    automata.finish();  // FINISH
  }

  ///////////////////////////// 2nd purchase  //////////////////////////////////
  automata.coin(100); // PUT MONEY

  std::string choice2 = automata.choice("Cocoa"); // CHOOSE 2nd DRINK

  if (automata.check(choice2)) {  // CHECK MONEY
    std::cout << "You choose: " << choice2 << ". It's started to cook!" << std::endl;
    std::cout << "You balance: " << automata.getBalance() << '.' << std::endl;

    if (automata.cook()) { // START TO COOK
      std::cout << "You order is ready!" << "\n\n";

      automata.finish();  // FINISH
    }

  } else {
    std::cout << "!!! NOT ENOUGH MONEY !!!\nYou balance: " << automata.getBalance() << '.' << std::endl;
    automata.cancel();  // CANCEL

    automata.off();  // OFF
  }

  automata.off(); // OFF

  return 0;
}
