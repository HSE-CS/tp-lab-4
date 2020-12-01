#pragma once

#include <cstring>
#include <iostream>

using namespace std;

enum States
{
    Off,
    Wait,
    Accept,
    Check,
    Cook
};

class Automata
{
private:
    States state;
    double cash;
    double lastBuyer;
    string menu[13] = {"Coffee with milk", "Milk", "Green tea", "Red tea", "Black tea", "Hot chocolate", "Latte",
                       "Americano", "Double americano", "Cappuccino", "Mokkachino", "Espresso", "Double espresso"};
    int prices[13] = {70, 60, 45, 50, 40, 65, 80, 55, 75, 80, 85, 45, 60};

public:
    Automata()
    {
        lastBuyer = 0;
        cash = 0;
        state = Off;
    }

    void on();

    void off();

    void coin(int money);

    string *getMenu();

    States getState();

    void choice(int number);

    void check(int number);

    void cancel();

    void cook();

    void finish();

    double getCash();
};