#ifndef AUTOMATA_H
#define AUTOMATA_H

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

enum STATES
{
	OFF,
	WAIT,
	ACCEPT,
	COOK
};

class Automata
{
private:
	int cash;
	STATES state;
	vector<string> menu;
	vector<int> prices;
	string for_user = "None";

	int finish();
public:
	Automata();
	void on();
	void off();
	void coin(int value);
	string getMenu();
	STATES getState();
	int choice(const string& selected);
	int check(int drink_numb);
	int cook(int drink_numb);
	int cancel();
	string takeDrink();
};
#endif
