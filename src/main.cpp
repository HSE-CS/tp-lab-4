#include "Automata.h"

int main() {
	Automata automata;
	automata.on();
	std::cout << automata.getMenu() << std::endl;
	std::cout << automata.getState() << std::endl;
	automata.coin(20);
	std::cout << automata.getState() << std::endl;
	automata.choice(0);
	std::cout << automata.getState() << std::endl;
	automata.cancel(1);
	std::cout << automata.getState() << std::endl;
	return 0;
}
