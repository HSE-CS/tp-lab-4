#include "automata.h"

vector<string>new_menu{"hot water","milk","americano","espresso","capuchino","hot chocolate","double chocolate"};
vector<int>new_prices{10,22,35,27,42,40,50};

vector<int>emulate_pause{ 1,5,10,7,9,6,7 };

void delay(clock_t sec)
{
	clock_t start_time = clock();
	clock_t end_time = sec + start_time;
	while (clock() != end_time);
}

Automata::Automata()
{
	cash = 0;
	state = OFF;
	menu = new_menu;
	prices = new_prices;
}

STATES Automata::getState()
{
	return state;
}

string Automata::getMenu()
{
	string result="";
	string tab = ". ";
		for (int i = 0; i < menu.size(); i++)
			result = result + to_string(i+1) + tab +  to_string(prices[i]) +" rubles   "   + menu[i]+ "\n";
	return result;
}

void Automata::on()
{
	if (getState() == OFF)
		state = WAIT;
}

void Automata::off()
{
	if (getState() == WAIT)
		state = OFF;
}

void Automata::coin(int value)
{
	if (getState()== WAIT)
	{
		state = ACCEPT;
		cash += value;
	}
	else if (getState() == ACCEPT)
		cash += value;
}

int Automata::cancel()
{
	if (getState() == ACCEPT)
	{
		int money = cash;
		cash = 0;
		state = WAIT;
		cout << "Take the rest of the money!" << endl;
		return money;
	}
	return -1;
}

int Automata::finish()
{
	cout << "Enjoy your drink!" << endl;
	return cancel();
}

int Automata::cook(int drink_numb)
{
	delay(1000 * emulate_pause[drink_numb]);
	for_user = menu[drink_numb];
	return finish();
}

int Automata::check(int drink_numb)
{

	if (prices[drink_numb] < cash && state == ACCEPT)
	{
		cash -= prices[drink_numb];
		return cook(drink_numb);
	}
	else
	{
		cout << "Not enough money!" << endl;
		return cancel();
	}
}

int Automata::choice(const string& selected)
{
	if (getState() == ACCEPT)
		for (int i = 0; i < menu.size(); i++)
			if (selected == menu[i])
				return check(i);
	return -1;
}

string Automata::takeDrink()
{
	string result = for_user;
	for_user = "None";
	return result;
}



