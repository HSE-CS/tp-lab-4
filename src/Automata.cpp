// Copyright 2020 test 
#include "Automata.h"

void Automata::on() {
    state = STATES::WAIT;
    return;
}

void Automata::off() {
    state = STATES::OFF;
    return;
}

void Automata::coin(int summ) {
    if (state == STATES::OFF)  return;
    state = STATES::ACCEPT;
    cash += summ;
    return;
}

std::string  Automata::getMenu() {
    if (state == STATES::OFF) {
        std::string men{ "" };
        return men;
    }
    std::string men = "";
    for (size_t i = 0; i < menu_size; ++i) {
        men += std::to_string(i + 1) + " " + menu[i] + " " + std::to_string(prices[i]) + "\n"; 
    }
    return men;
}

unsigned Automata::getState() {
    return state;
}

int Automata::getCoin() {
    return cash;
}

void Automata::choice(size_t pos) {
    if (pos == 0 || pos - 1 > menu_size ||state == STATES::OFF) return;
    state = STATES::CHECK;
    check(pos - 1);
    return;
}

void Automata::check(size_t pos) {
    if (prices[pos] > cash) {
        cancel();
        return;
    }
    cook(pos);
    return;
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK)
        state = STATES::WAIT;
    return;
}

void Automata::cook(size_t pos) {
    cash -= prices[pos];
    state = STATES::COOK;
    time_t start = clock();
    while (clock() - start < 10) {

    }
    finish();
    return;
}

void Automata::finish() {
    if (state == STATES::OFF) return;
    cash = 0;
    state = STATES::WAIT;
    return;
}
