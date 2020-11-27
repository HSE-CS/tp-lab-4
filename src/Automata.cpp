#include "Automata.h"

vector <int> cost{ 20, 15, 25, 40, 30, 35, 45};

vector <string> drinks{ "milk", "water", "tea", "hot chocolate",
                        "americano", "espresso", "cappuccino" };

Automata::Automata()
{
    this->cash = 0;
    this->bank = 0;
    this->option = 0;
    this->state = OFF;
    this->prices = cost;
    this->menu = drinks;
}

void Automata::on()
{
    if (this->getState() == OFF)
        this->state = ON;
    this->state = WAIT;
}

void Automata::off()
{
    if (this->getState() == WAIT)
        this->state = OFF;
    cerr << "FINISH" << endl;
}

void Automata::coin(int coins)
{
    if (this->getState() == WAIT)
        cash += coins;
    else
        cerr << "*** ERROR ***\nThe automata is turned off" << endl;
}

string Automata::getMenu()
{
    if (this->getState() == WAIT)
    {
        string select;
        for ( int i = 0; i < prices.size(); i++ )
            select += (menu[i] + " - " + to_string(prices[i]) + " coins" + "\n");
        return select;
    }
    else
        cerr << "*** ERROR ***\nThe automata is turned off" << endl;
    return nullptr;
}

STATES Automata::getState()
{
    return this->state;
}

void Automata::choice(const string& option)
{
    this->option = 0;
    for (auto &position : menu)
        if (position == option)
            break;
        else
            this->option++;

    if (option != menu[this->option])
    {
        cerr << "\t\t*** WRONG NAME ***" << endl;
        cancel();
    }
}

bool Automata::check()
{
    if (prices[this->option] > this->cash)
        return false;
    else
        return true;
}

int Automata::cancel()
{
    int coins = this->cash;
    this->cash = 0;
    this->option = 0;
    this->state = WAIT;
    return coins;
}

void Automata::cook()
{
    this->bank += prices[this->option];
    this->cash -= prices[this->option];
    _sleep(6500);
    cout << "DONE" << endl;
}

void Automata::finish()
{
    cancel();
    off();
}