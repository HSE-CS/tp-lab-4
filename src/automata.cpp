
#include "automata.h"
#include <string>

using namespace std;

void Automata::on()
{
    if (state == Off)
        state = Wait;
}

void Automata::off()
{
    if (state == Wait)
        state = Off;
}

void Automata::coin(int funds)
{
    if (state == Wait || state == Accept)
    {
        cash += funds;
        lastBuyer = funds;
        state = Accept;
    }
}

string *Automata::getMenu()
{
    if (state != Off)
    {
        string *menu_dop = new string[13];

        for (int i = 0; i < 13; ++i)
        {
            menu_dop[i] += to_string(i + 1);
            menu_dop[i] += ". ";
            menu_dop[i] += menu[i];
            menu_dop[i] += ". Cost: ";
            menu_dop[i] += to_string(prices[i]);
        }
        return menu_dop;
    } else
        return nullptr;
}

States Automata::getState()
{
    return state;
}

void Automata::choice(int selected)
{
    if (state == Accept)
    {
        state = Check;
        check(selected);
    }
}

void Automata::check(int selected)
{
    if (lastBuyer >= prices[selected])
    {
        cash += prices[selected] - lastBuyer;
        cook();
    } else
    {
        cancel();
    }
}

void Automata::cancel()
{
    if (state == Check || state == Accept)
    {
        cash -= lastBuyer;
        state = Wait;
    }
}

void Automata::cook()
{
    state = Cook;
    finish();
    cout << "Funds in auto: " << cash << endl;
}

void Automata::finish()
{
    if (state == Cook)
        state = Wait;
}

double Automata::getCash()
{
    if (state == Wait)
    {
        off();
        double tmp;
        tmp = cash;
        cash = 0;
        return tmp;
    }
    return 0;
}