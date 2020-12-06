#include <iostream>
#include "automata.h"

using namespace std;

int main() 
{
	Automata CoffeeMashine;
	CoffeeMashine.on();
	cout << CoffeeMashine.getMenu() << endl;
	CoffeeMashine.coin(2);
	CoffeeMashine.coin(18);
	CoffeeMashine.coin(10);
	CoffeeMashine.choice(2);
	if (CoffeeMashine.check()) cout << "I NEEED MORERERE MONNNNEY!" << endl;
	CoffeeMashine.choice(1);
	if (CoffeeMashine.check()) cout << "Give me more money!" << endl;
	else
	{
		cout << "Take your choose, leather face #" << CoffeeMashine.cook() << endl;
		cout << "Take extra money, leaather face: " << CoffeeMashine.cancel() << endl;
	}
	return 0;
}
