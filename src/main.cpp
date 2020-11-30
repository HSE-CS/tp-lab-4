#include <iostream>
#include "automata.h"

int main() {
	Automata machine;
	machine.on();

	// Get the menu
	std::cout << machine.getMenu() << std::endl;

	// Insert a money (30 rub)
	machine.coin(10);
	machine.coin(10);
	machine.coin(10);

	// Choice the black coffee (#2) - 40 rub
	machine.choice(2);
	if (machine.check())
		std::cout << "Not enough money!" << std::endl;

	// Choice the cheaper product (#1) - 20 rub
	machine.choice(1);
	if (machine.check())
		std::cout << "Not enough money!" << std::endl;
	else
	{
		std::cout << "Please, take your order #" << machine.cook() << std::endl; // Order #1
		std::cout << "Please, take extra money: " << machine.cancel() << std::endl; // Extra money = 10
	}

	return 0;
}
