#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum STATES { ON, OFF, WAIT };

class Automata
{
private:
    int cash;
    int bank;
    int option;
    STATES state;
    vector <int> prices;
    vector <string> menu;

public:
    Automata();
    void on();
    void off();
    void coin(int coins);
    string getMenu();
    STATES getState();
    void choice(const string& option);
    bool check();
    int cancel();
    void cook();
    void finish();
};

#endif //TASK1_AUTOMATA_H