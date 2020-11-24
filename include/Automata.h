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

    void cook();

    void finish();

public:
    Automata(string *menu, double *prices);

    void on();

    void off();

    void coin(double _cash);

    string* getMenu() const;

    STATES getState() const;

    double getCash() const;

    void choice(int _choice);

    bool check(int _check) const;

    void cancel();
};


#endif //TASK1_AUTOMATA_H
