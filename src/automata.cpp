//Copyright 2020 FOM
#include <iostream>
#include "automata.h"

Automata::Automata() {
    state = STATES::OFF;
    bank = 0;
    cash = 0;
    order = 0;
}

void Automata::on() {
    if (state == STATES::OFF)
        state = STATES::WAIT;
}

void Automata::off() {
    if (state == STATES::WAIT)
        state = STATES::OFF;
}

bool Automata::coin(int cash) {
    if ((state == STATES::WAIT) && (state == STATES::ACCEPT)) {
        state = STATES::ACCEPT;
        cash += cash;
        return true;
    }
    return false;
}

