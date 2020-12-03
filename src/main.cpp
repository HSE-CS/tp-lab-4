#include "automata.h"

int main()
{
	Automata A;
	cout << A.getState() << endl;
	A.on();
	cout << A.takeDrink() << endl;
	cout << A.getMenu();
	cout << A.getState() << endl;
	A.coin(15);
	A.coin(5);
	A.coin(20);
	cout << A.choice("americano") << endl;
	cout << A.takeDrink() << endl;
	A.coin(7);
	cout << A.choice("hot water") << endl;
	A.off();
	cout << A.getState() << endl;
	return 0;
}
