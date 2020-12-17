#include "automata.h"

int main()
{
	int my_money = 15;

	Automata Drinks_Maker = Automata();
	Drinks_Maker.PrintState();
	Drinks_Maker.on();

	cout << endl;

	Drinks_Maker.PrintDrinks();
	Drinks_Maker.coin(my_money);
	my_money = Drinks_Maker.choice(1);
	cout << "my money = " << my_money << endl;

	cout << endl;
	my_money += 25;
	cout << "my money = " << my_money << endl;

	Drinks_Maker.coin(my_money);
	my_money = Drinks_Maker.choice(1);
	cout << "my money = " << my_money << endl;

	cout << endl;
	my_money += 100;
	cout << "my money = " << my_money << endl;

	Drinks_Maker.coin(my_money);
	my_money = Drinks_Maker.choice(2);
	

	cout << endl;

	Drinks_Maker.coin(80);
	my_money = Drinks_Maker.cancel();
	cout << "my money = " << my_money << endl;

	my_money += Drinks_Maker.off();
	cout << "my money = " << my_money << endl;
}