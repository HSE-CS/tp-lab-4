#pragma once
#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>


using namespace std;
const map <string, int> menu = { {"Milk"   , 10}, {"Water"  ,  5},	{ "Tea"   , 30}, {"Coffee" , 40}, {"Cola"   , 50} };
enum States {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK,
	COOK
};
class Automata {

private:
	int money;
	States state;
	map<string, int> menu;
	map <string, int> users_choice;
	int profit;
	ostream* input_stream;
public:
	Automata();
	Automata(ostream*);
	Automata();
	void printMenu();
	void setSettings();
	void setMenu();
	void on();
	void off();
	void coin();
	void getMenu();
	void getState();
	void choice();
	void coin(int cash);
	map <string, int> getMenu();
	States getState();
	void choice(string product);
	void cancel();
	void cook();
	void finish();
	void reset();
	void return_money();
	int getProfit();
};
#endif 