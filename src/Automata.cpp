#include "Automata.h"
std::vector<std::string> Automata::menu{"tea", "coffee", "milk", "koumiss", "shubat"};
std::map<std::string, unsigned int> Automata::prices{{"tea", 72},
                                                    {"coffee", 91},
                                                    {"milk", 56},
                                                    {"koumiss", 89},
                                                    {"shubat", 103}};


Automata::Automata()
{
    state = STATES::OFF;
    cash = 0;
}


void Automata::on()
{
    if (STATES::OFF == state)
        state = STATES::WAIT;
}


void Automata::off()
{
    if (STATES::WAIT == state)
        state = STATES::OFF;
}

void Automata::coin(unsigned int dep)
{
    if (STATES::WAIT == state ||
        STATES::ACCEPT == state)
    {
        cash += dep;
        state = STATES::ACCEPT;
    }
}

std::vector<std::string> Automata::getMenu()
{
    if (STATES::WAIT == state ||
        STATES::ACCEPT == state)
        return menu;
    else
        return std::vector<std::string>();
}

std::map<std::string, unsigned int> Automata::getPrices()
{
    if (STATES::WAIT == state ||
        STATES::ACCEPT == state)
        return prices;
    else
        return std::map<std::string, unsigned int>();

}

unsigned int Automata::getCash()
{
    return cash;
}

STATES Automata::getState()
{
    return state;
}

void Automata::choice(std::string drink)
{
    if (STATES::ACCEPT != state)
        return;
    state = STATES::CHECK;
    if (check(prices[drink]))
    {
        cash -= prices[drink];
        cook();
    }
    else
        cancel();
}

bool Automata::check(unsigned int cost)
{
    return cash >= cost;
}

void Automata::cancel()
{
    if (STATES::ACCEPT == state ||
        STATES::CHECK == state)
        state = STATES::WAIT;
}


void Automata::cook()
{
    if (STATES::CHECK == state)
    {
        state = COOK;
        finish();
    }
}

void Automata::finish()
{
    if (STATES::COOK == state)
        state = STATES::WAIT;
}
