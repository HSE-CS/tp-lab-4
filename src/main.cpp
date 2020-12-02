#include <iostream>
#include "automata.h"

int main() {
	Automata machine;
	machine.on();
	std::cout << machine.getMenu() << std::endl;
	machine.coin(10);
	machine.coin(10);
	machine.coin(10);
	machine.choice(2);
	if (machine.check())
		std::cout << "Not enough money!" << std::endl;
	machine.choice(1);
	if (machine.check())
		std::cout << "Not enough money!" << std::endl;
	else{
		std::cout << "Please, take your order #" << machine.cook() << std::endl;
		std::cout << "Please, take extra money: " << machine.cancel() << std::endl;
	}

	return 0;
}
