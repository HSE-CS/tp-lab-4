#pragma once

#include <cstdint>
#include <string>
#include <vector>

enum class STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
struct PRODUCT {
	string product;
	int price;
};

class Automata {
private:
	STATES state;
	int bank;
	int cash;
	int order;
	static vector<PRODUCT> menu;
public:
	Automata();
	bool on();
	bool off();
	bool coin(int cash);
	bool choice(int number);
	bool check();
	int cook();
	int cancel();
	static string getMenu();
};
