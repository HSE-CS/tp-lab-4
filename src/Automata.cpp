#include "Automata.h"

Automata::Automata()
{
    this->cash = 0;
    this->state = OFF;
    std::ifstream menuF("menu.txt");
    std::ifstream priceF("price.txt");
    while (!menuF.eof())
    {
        std::string tmpStr;
        menuF >> tmpStr;
        this->menu.push_back(tmpStr);
        double tmpD;
        priceF >> tmpD;
        this->price.push_back(tmpD);
    }
    
}

void Automata::on()
{
    if (this->state != OFF)
        return;
    this->state = WAIT;
}

void Automata::off()
{
    this->cash = 0;
    this->state = OFF;
}

void Automata::coin(double coin)
{
    if (this->state != ACCEPT && this->state != WAIT)
        return;
    this->state = ACCEPT;
    this->cash += coin;
}

std::vector<std::string> Automata::getMenu()
{
    return this->menu;
} 

STATES Automata::getState()
{
    return this->state;
}  

void Automata::choice()
{
    if(this->state != ACCEPT)
        return;
    this->state = CHECK;
}

void Automata::check(int number)
{
    if (this->state == CHECK)
        if (this->cash >= this->price[number-1])
            cook();
    return;
}

void Automata::cancel()
{
    if (this->state == OFF)
        return;
    this->state = WAIT;
    this->cash = 0;
}

void Automata::cook()
{
    this->state = COOK;
    printf("Cooking...\n");
    finish();
}

void Automata::finish()
{
    this->state = WAIT;
    this->cash = 0;
}