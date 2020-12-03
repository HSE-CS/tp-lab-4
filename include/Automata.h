// Copyright 2020 test
#ifndef  AUTOMATA_H
#define AUTOMATA_H

#include<iostream>
#include <time.h>
#include<string>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    int cash;
    std::string menu[5] = { "Americano", "Espresso", "Cappuccino", "Long Black", "Hot Chocolate" };
    int  prices[5] = { 25, 35, 40, 38, 30 };
    size_t menu_size = 5;
    unsigned state;
public:
    Automata() {
        state = OFF;
        cash = 0;
    }
    void on();
    void off();
    void coin(int summ);
    std::string getMenu();
    unsigned getState();
    void choice(size_t pos);
    void check(size_t pos);
    void cancel();
    void cook(size_t pos);
    void finish();
    int getCoin();
};

#endif // ! AUTOMATA_H
