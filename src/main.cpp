//
// Created by Vadim Makarov on 23.11.2020.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "Automata.h"



using namespace std;

int main() {
    Automata automata1;
    cout << "State: "<< automata1.getState() << endl << endl;

    automata1.on();
    cout << "State: "<< automata1.getState() << endl << endl;

    automata1.coin(60);
    cout << "State: "<< automata1.getState() << endl << endl;

    auto* menu = new string [5];
    menu = automata1.getMenu();
    cout << "State: "<< automata1.getState() << endl << endl;

    for (int i = 0; i < 5; ++i) {
        cout << menu[i] << endl;
    }

    automata1.choice(2);
    cout << endl << "Final State: "<< automata1.getState() << endl << endl;



    if (automata1.getState() == WAIT){
        cout << "SUCCESS" << endl;
    }






    delete[] menu;

    return 0;





}

