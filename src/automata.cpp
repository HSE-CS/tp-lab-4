//
// Created by Vadim Makarov on 23.11.2020.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <unistd.h>
#include "Automata.h"

void Automata::on() {
    state = WAIT;
}

void Automata::off() {
    state = OFF;
}

void Automata::coin(int money) {
    if (state == WAIT) {
        cash += money;
        lastTransaction += money;
        state = ACCEPT;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash -= lastTransaction;
        state = WAIT;
    }
}

string* Automata::getMenu() {
    auto *menu = new string[5];

    for (int i = 0; i < 5; ++i) {
        menu[i] += to_string(i + 1) += ") ";
        menu[i] += this->menu[i] += " - ";
        menu[i] += to_string(this->prices[i]);
    }

    return menu;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int number) {
    if (state == ACCEPT) {
        state = CHECK;
        this->check(number);
    }
}

void Automata::check(int number) {
    if (lastTransaction >= prices[number]){
        this->cook();
    }
    else {
        cancel();
    }
}

void Automata::cook() {
    state = COOK;
    this->finish();
}

void Automata::finish() {
    state = WAIT;
}
