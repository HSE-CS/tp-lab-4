#pragma once
#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <vector>
#define COUNT_OF_FOODS 4

enum States
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
private:
	int cash;
	std::string menu[COUNT_OF_FOODS] = { "espresso", "latte", "capucino", "raf" };
	int prices[COUNT_OF_FOODS] = { 20, 30, 30, 40 };
	States state;
public:
	Automata();
	void on();
	void off();
	void coin(int);
	std::string getMenu();
	States getState();
	void choice(int);
	bool check(int);
	void cancel(int);
	void cook();
	void finish();

};

#endif 
