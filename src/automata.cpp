#include "automata.h"
using namespace std;
vector<PRODUCT> Automata::menu = 
{
    {"Tea? in CoffeeMashine?", 20},
    {"Espresso", 40},  
    {"White coffee", 50},  
    {"Prosto coffee podorozhe", 300},
    {"EspressoX2", 60},
    {"Cappuccino", 70},
    {"Americano", 50},
    {"Mokachino", 80},
};

Automata::Automata() 
{
    this->bank = 0;
    this->cash = 0;
    this->state = STATES::OFF;
    this->order = 0;
}

bool Automata::on() 
{
    if (this->state != STATES::OFF)return EXIT_FAILURE;
    this->state = STATES::WAIT;
    return 0;
}

bool Automata::off() 
{
    if (this->state != STATES::WAIT)
        return EXIT_FAILURE;
    this->state = STATES::OFF;
    return 0;
}

bool Automata::coin(int money) 
{
    if (this->state != STATES::WAIT && this->state != STATES::ACCEPT) return EXIT_FAILURE;
    this->state = STATES::ACCEPT;
    this->cash += money;
    return 0;
}

bool Automata::choice(int choose) 
{
    if (this->state != STATES::ACCEPT) return EXIT_FAILURE;
    if (choose > this->menu.size() || choose == 0) return EXIT_FAILURE;
    this->state = STATES::CHECK;
    this->order = choose - 1;
    return 0;
}

bool Automata::check() 
{
    if (this->state != STATES::CHECK) return EXIT_FAILURE;
    if (this->cash < this->menu[this->order].price)
    {
        this->state = STATES::ACCEPT;
        return EXIT_FAILURE;
    }
    this->state = STATES::COOK;
    return 0;
}

int Automata::cook() 
{
    if (this->state != STATES::COOK) return 0;
    this->state = STATES::WAIT;
    this->bank += this->cash;
    this->cash -= this->menu[this->order].price;
    return this->order + 1;
}

int Automata::cancel() 
{
    uint32_t ret = this->cash;
    this->state = STATES::WAIT;
    this->order = 0;
    this->cash = 0;
    return ret;
}

string Automata::getMenu() 
{
    string menu;
    menu.append("Menu:\n");
    uint32_t position = 1;
    for (auto product : Automata::menu) 
    {
        menu.append(std::to_string(position));
        menu.append(") ");
        for (uint16_t i = product.name.length(); i < 12; i++) menu.push_back(' ');
        menu.append(product.name);
        menu.append(" | ");
        if (product.price < 100) menu.push_back(' ');
        menu.append(to_string(product.price));
        menu.append(" million USD | ");
        menu.push_back('\n');
        position++;
    }
    menu.pop_back();
    return menu;
}
