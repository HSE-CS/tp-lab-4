//
// Created by freeb on 23.11.2020.
//

#include "Automata.h"

Automata::Automata(string *_menu, double *_prices){
    cash = 0;
    menu = _menu;
    prices = _prices;
    state = OFF;
}

void Automata::on() {
    if (state == OFF){
        state = WAIT;
    }
}

void Automata::off() {
    if (state == WAIT){
        state = OFF;
    }
}

void Automata::coin(double _cash) {
    if (state == WAIT || state == ACCEPT) {
        if (state == WAIT){
            state = ACCEPT;
        }
        cash += _cash;
    }
}

string *Automata::getMenu() const {
    if (state != OFF){
        return menu;
    } else return nullptr;
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(int _choice) {
    if (state == ACCEPT){
        state = CHECK;
        if (check(_choice)){
            cash -= prices[_choice];
            cook();
        } else {
            state = WAIT;
            cancel();
        }
    }
}

bool Automata::check(int _check) const {
    return cash > prices[_check];
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK){
        state = WAIT;
        cash = 0;
    }
}

void Automata::cook() {
    if (state == CHECK){
        state = COOK;
        finish();
    }
}

void Automata::finish() {
    if (state == COOK){
        state = WAIT;
    }
}

double Automata::getCash() const{
    return cash;
}
