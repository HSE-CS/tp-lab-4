#include <iostream>
<<<<<<< HEAD
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
=======
#include "Automata.h"


using namespace std;
int main() {
    Automata* automata = new Automata();
    Automata* automata = new Automata();

    cout << "Pass" << endl;
    automata->coin(10);
    automata->cancel();
    automata->cook();

    cout << "Enter menu" << endl;
    automata->on();
    automata->printMenu();

    cout << "Pass" << endl;
    automata->cancel();
    automata->cook();
    cout << "buy milk, return 90" << endl;
    automata->coin(100);
    automata->choice("Milk");
    automata->cook();


    cout << "wait = 1, result = " << automata->getState() << endl;
    cout << "profit = 10, result = " << automata->getProfit() << endl;
    cout << "must be denied" << endl;
    automata->coin(5);
    automata->choice("Tea");
    cout << "must be accept(2)" << automata->getState() << endl;
    automata->cancel();
    cout << "must be wait(1)" << automata->getState() << endl;



    return 0;
}
}
>>>>>>> 42f821985a9fb00ab69720f249229ccc02b3ad07
