#include "Automata.h"

Automata::Automata()
{
	this->cash = 0;
	this->state = OFF;
}

void Automata::on()
{
	this->state = WAIT;
}

void Automata::off()
{
	this->cash = 0;
	this->state = OFF;
}

void Automata::coin(int value)
{
	if (this->state == WAIT || this->state == ACCEPT) {
		this->state = ACCEPT;
		this->cash += value;
	}
	else {
		std::cout << "You are already done this part" << std::endl;
		return; 
	}
}

std::string Automata::getMenu()
{
	std::string result = "";
	int length = 0;
	for (size_t i = 0; i < COUNT_OF_FOODS; i++)
	{
		result += this->menu[i] + ":" + std::to_string(this->prices[i]) + "\n";
	}
	return result;
}

States Automata::getState()
{
	return this->state;
}

void Automata::choice(int value)
{
	if (this->state == ACCEPT) {
		if (this->check(value)) {
			std::cout << "Please, w8" << std::endl;
			this->cook();
		}
		else {
			std::cout << "U have no enough money for buy this. Please, put more coins or chose different drink." << std::endl;
			this->cancel(1);
		}
	}
}

bool Automata::check(int value)
{
	if (this->state == ACCEPT)
	{
		this->state = CHECK;
		if (this->prices[value] <= this->cash) {
			return true;
		}
		return false;
	}
}

void Automata::cancel(int reason)
{
	if (reason) {
		this->state = ACCEPT;
	}
	else
	{
		this->state = WAIT;
	}
}

void Automata::cook()
{
	if (this->state == CHECK) {
		this->state = COOK;
		std::cout << "W8 a minute, your drink is cooking" << std::endl;
		Sleep(2000);
		this->finish();
	}
}

void Automata::finish()
{
	if (this->state == COOK) {
		this->cash = 0;
		this->state = WAIT;
	}
}
