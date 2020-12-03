#include <iostream>
#include <map>
#include <string>
#include "Automata.h"

static string endL = "\n";

Automata::Automata() {
	setSettings();
	this->input_stream = &(cout);
	*(this->input_stream) << "Automata created" << endL;
}

Automata::Automata(ostream* input_stream ){
	setSettings();	
	this->input_stream = input_stream;
	*(this->input_stream) << "Automata created" << endL;
}

void Automata:: setSettings() {
	this->state = OFF;
	this->money = 0;
	this->profit = 0;
	setMenu();
} 

void Automata::setMenu() {
	this->menu = { {"Milk"   , 10},
				   {"Water"  ,  5},
				   { "Tea"   , 30},
				   {"Coffee" , 40},
				   {"Cola"   , 50} };
}

void Automata::on() {
	if (this->state == OFF) {
		this->state = WAIT;
	}
}

void Automata::off() {
	if (this->state == WAIT) {
		this->state = OFF;
	}
}

void Automata::coin(int cash) {
	if (this->state == WAIT || this->state == ACCEPT) {
		this->money += cash;
		this->state = ACCEPT;
	}
	(*input_stream) << "Curent budget is " << this->money << endL;
}

map <string, int> Automata::getMenu() {
	return this->menu;
}

States Automata::getState() {
	return this->state;
}

void Automata::choice(string product) {
	if (this->state == ACCEPT || this->state == CHECK) {
		bool flag = false;
		map <string, int> ::iterator it;
		it = (this->menu).find(product);
		if (it == this->menu.end()) {
			(*input_stream) << "No such Product" << endL;
		}
		else {
			(*input_stream) << "You choosee " << product << endL
				<< "Product cost is " << this->menu[product] << endL;
			flag = true;
		}
		if (flag) {
			if (this->money >= this->menu[product]) {
                this->state = CHECK;
				this->users_choice.insert(make_pair(product, this->menu[product]));
			}
			else {
				(*input_stream) << "You do not have enough money" << endL;
			}
		}
	}
}

void Automata::cook() {
	if (this->state == CHECK) {
		this->state = COOK;
		map <string, int> ::iterator it = this->users_choice.begin();
		this->money -= (*it).second;
		this->profit += (*it).second;
		(*input_stream) << "You successfully bought : " << (*it).first << endL;
		finish();
	}
}

void Automata::finish() {
	if (this->state == COOK) {
		return_money();
		this->state = WAIT;
		reset();
	}
}

void Automata::reset() {
	this->money = 0;
	this->users_choice.clear();
	this->state = WAIT;
}

void Automata::cancel() {
	if (this->state == ACCEPT || this->state == CHECK) {
		this->state = WAIT;
		(*input_stream) << "Return money : " << this->money << endL;
		reset();
	}
}

void Automata::return_money() {
	if (this->state == COOK) {
		(*input_stream) << "Return money : " << this->money << endL;
	}
}

void Automata::printMenu() {
	map <string, int> menu = getMenu();
	if (this->state != OFF) {
		(*input_stream) << "------------Menu-------------" << endL;
		map <string, int> ::iterator it;
		for (it = menu.begin(); it != menu.end();it++) {
			(*input_stream) << it->first << " - " << it->second << endL;
		}
	}
}

int Automata :: getProfit() {
	return this->profit;
}
