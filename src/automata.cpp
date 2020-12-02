//
// Created by Алексей Трутнев on 24.11.2020.
//

#include "automata.h"
#include<string>

void Automata::on() {
    status = STATES::WAIT;
}

void Automata::off() {
    status = STATES::OFF;
}

void Automata::coin(unsigned int coins) {
    if (status == STATES::WAIT) {
        status = STATES::ACCEPT;
        cash += coins;
    }
}

void Automata::choice(size_t index){
    if (status == STATES::ACCEPT && 0 <= index - 1  && index - 1 < menu_size) {
        status = STATES::CHECK;
        check(index - 1);
    }
    cancel();
}

void Automata::check(size_t index) {
    if (cash >= prices[index])
        cook(index);
    else
        cancel();
}

void Automata::cook(size_t index) {
    status = STATES::COOK;
    cash -= prices[index];
    std::cout << "DONE: " << menu[index] << "\n";
    finish();
}

void Automata::finish(){
    cash = 0;
    status = STATES::WAIT;
}

void Automata::cancel() {
    if (status == STATES::ACCEPT || status == STATES::CHECK) {
        cash = 0;
        status = STATES::WAIT;
    }
}

unsigned int Automata::getCash() const {
    return cash;
}

std::string Automata::getState() const {
    switch (status) {
        case STATES::OFF:
            return "OFF";
        case STATES::WAIT:
            return "WAIT";
        case STATES::ACCEPT:
            return "ACCEPT" ;
        case STATES::CHECK:
            return "CHECK" ;
        case STATES::COOK:
            return "COOK" ;

        default:
            return "Oops...";
    }
}

std::string Automata::getMenu() const {
    std::string menu_price;
    if (status == STATES::WAIT) {
        for (size_t index = 0; index < menu_size; ++index)
            menu_price += std::to_string(index + 1) + ". " + menu[index] + " (" + std::to_string(prices[index]) + " coins)\n";
        return menu_price;
    }
    return menu_price;
}
