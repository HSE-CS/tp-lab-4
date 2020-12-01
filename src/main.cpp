#include "automata.h"
#include <iostream>

using namespace std;


int main() {
    Automata automata;
    cout << STATES(automata.getState()) << endl;
    automata.on();
    cout << STATES(automata.getState()) << endl;
    char** menu;
    //automata.getMenu(menu);
    //for (size_t i=0; i<3; i++) cout<<menu[i]<<endl;
    cout << STATES(automata.getState()) << endl;
    automata.coin(50);
    cout << STATES(automata.getState()) << endl;
    automata.coin(25);
    cout << STATES(automata.getState()) << endl;
    automata.choice(0);
    cout << STATES(automata.getState()) << endl;
    automata.coin(100);
    cout << STATES(automata.getState()) << endl;
    automata.choice(2);
    cout << STATES(automata.getState()) << endl;
    automata.cook();
    cout << STATES(automata.getState()) << endl;
    cout << automata.finish() << endl;
    cout << STATES(automata.getState()) << endl;
    cout << STATES(automata.getState()) << endl;
    automata.off();
    cout << STATES(automata.getState()) << endl;
    return 0;
}
