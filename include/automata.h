#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Automata
{
private:
    int cash;
    vector<string> drinks = {"tea", "coffee", "water", "milk", "hot chocolate"};
    vector<int> prices = { 30, 40, 35, 20, 35 };
    enum States {OFF, WAIT, ACCEPT, CHECK, COOK};
    vector<string> states = {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
    States state;

	bool check(int drink);
	void cook(int drink);
	int finish();

public:
    Automata();
    void on();
    int off();
    void coin(int money);
    void PrintDrinks();
    void PrintState();
    int choice(int drink);
    int cancel();

};

#endif