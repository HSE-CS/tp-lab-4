#include "automata.h"

std::vector<PRODUCT> Automata::menu = {
    {"Tea", 20},
    {"Black coffee", 40},  // without milk
    {"White coffee", 50},  // with milk
    {"Irish coffee", 300}, // with whiskey and cream
    {"Espresso", 60},      // strong without milk
    {"Cappuccino", 70},    // strong with milk
    {"Americano", 50},     // Espresso with a lot of hot water
    {"Latte", 80},         // Cappuccino with foam
};

Automata::Automata() {
    this->state = STATES::OFF;
    this->bank = 0;
    this->cash = 0;
    this->order = 0;
}

bool Automata::on() {
    if (this->state != STATES::OFF)
        return EXIT_FAILURE;
    this->state = STATES::WAIT;
    return 0;
}

bool Automata::off() {
    if (this->state != STATES::WAIT)
        return EXIT_FAILURE;
    this->state = STATES::OFF;
    return 0;
}

bool Automata::coin(uint32_t cash) {
    if (this->state != STATES::WAIT && this->state != STATES::ACCEPT)
        return EXIT_FAILURE;
    this->state = STATES::ACCEPT;
    this->cash += cash;
    return 0;
}

bool Automata::choice(uint32_t number) {
    if (this->state != STATES::ACCEPT)
        return EXIT_FAILURE;
    if (number > this->menu.size() || number == 0)
        return EXIT_FAILURE;
    this->state = STATES::CHECK;
    this->order = number - 1;
    return 0;
}

bool Automata::check() {
    if (this->state != STATES::CHECK)
        return EXIT_FAILURE;
    if (this->cash < this->menu[this->order].price)
    {
        this->state = STATES::ACCEPT;
        return EXIT_FAILURE;
    }
    this->state = STATES::COOK;
    return 0;
}

uint32_t Automata::cook() {
    if (this->state != STATES::COOK)
        return EXIT_FAILURE;
    this->bank += this->cash;
    this->cash = 0;
    // Cooking...
    return this->order + 1;
}

uint32_t Automata::cancel() {
    uint32_t ret = this->cash;
    this->state = STATES::WAIT;
    this->order = 0;
    this->cash = 0;
    return ret;
}

std::string Automata::getMenu() {
    std::string menu;
    menu.append("Menu:\n");
    uint32_t position = 1;
    for (auto product : Automata::menu) {
        menu.append(std::to_string(position));
        menu.append(") ");
        for (uint16_t i = product.name.length(); i < 12; i++)
            menu.push_back(' ');
        menu.append(product.name);
        menu.append(" | ");
        if (product.price < 100)
            menu.push_back(' ');
        menu.append(std::to_string(product.price));
        menu.append(" rub | ");

        switch (position) {
        case 1:
            menu.append("Just a green tea."); break;
        case 2:
            menu.append("Coffee without milk."); break;
        case 3:
            menu.append("Coffee with milk."); break;
        case 4:
            menu.append("Coffee with whiskey and milk cream."); break;
        case 5:
            menu.append("Strong coffee without milk."); break;
        case 6:
            menu.append("Strong coffee with milk."); break;
        case 7:
            menu.append("Strong coffee with a lot of hot water."); break;
        case 8:
            menu.append("Strong coffee with milk and foam."); break;
        }
        menu.push_back('\n');
        position++;
    }
    menu.pop_back();
    return menu;
}
