#include <iostream>
#include "automata.h"

using namespace std;

int main()
{
    Automata automata;

    automata.on();
    cout << "State {1 is needed}:" << automata.getState() << endl;
    automata.coin(60);

    automata.choice(2);
    automata.coin(100);
    automata.choice(4);
    automata.coin(100);
    cout << "State {2 is needed}: " << automata.getState() << endl;
    automata.choice(12);
    cout << "State {1 is needed}: " << automata.getState() << endl;
    automata.coin(100);
    automata.choice(0);
    automata.coin(100);
    automata.choice(6);
    automata.coin(100);
    automata.choice(1);

    double ff = automata.getCash(); // Disables the machine when collecting money
    cout << "State {0 is needed}: " << automata.getState() << endl;
    cout << "Collected funds: " << ff << endl;

    automata.on();

    automata.coin(100);
    automata.choice(5);

}
