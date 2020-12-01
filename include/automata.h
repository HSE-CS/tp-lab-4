//Copyright 2020 FOM
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include<vector>
#include <string>

enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK,
	COOK
};

class Automata {
 public:
	 Automata();
	 void on();
	 void off();
	 bool coin(int chash);
	 std::string* getMenu();
	 STATES getState();
	 void choice(int number);
	 bool check();
	 void cancel();
	 void cook();
	 void finish();

 private:
	int cash;
	std::string menu[10] = {"Espresso","Cappuccino",
		"Ristretto","Lungo",
		"Latte","Latte macchiato",
		"Tea","Green tea",
		"Cold tea","Water" };
	int prices[10] = { 40, 40, 60, 55, 45,
		55, 25, 30, 20, 20 };
	STATES state;
	int bank;
	int order;
};
#endif // INCLUDE_AUTOMATA_H_
