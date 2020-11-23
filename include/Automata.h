//
// Created by freeb on 23.11.2020.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include "states.h"
#include <string>

using namespace std;

class Automata {
private:
    double cash;
    string *menu;
    double *prices;
    STATES state;

public:
    Automata(string *menu, double *prices);

    void on();

    void off();

    void coin(double _cash);

    string* getMenu();

    STATES getState();

    double getCash() const;

    void choice(int _choice);

    bool check(int _check);

    void cancel();

    void cook();

    void finish();
};


#endif //TASK1_AUTOMATA_H
