#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <fstream>
#include <string.h>
#include <stdlib.h>

enum STATES{OFF, WAIT, ACCEPT, COOK};

class Automata{
private:
    STATES state = STATES::OFF;
    long cash = 0.0;
    map<string, double> menu;
    string chosen_product;
    void setMenuFromFile(string menu_file_name);
public:
    Automata();
    Automata(string menu_file_name);

    string on();
    string off();

    map<string, double> getMenu();
    STATES getState();

    bool check();

    string coin(double sum);
    string choice(string product);
    string cancel();
    string cook();

    void printMenuToConsole();
};

#endif //TASK1_AUTOMATA_H
