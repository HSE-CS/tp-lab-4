#include <iostream>
#include "Automata.h"


using namespace std;
int main() {
    Automata* automata = new Automata();
    Automata* automata = new Automata();

    cout << "Pass" << endl;
    automata->coin(10);
    automata->cancel();
    automata->cook();

    cout << "Enter menu" << endl;
    automata->on();
    automata->printMenu();

    cout << "Pass" << endl;
    automata->cancel();
    automata->cook();
    cout << "buy milk, return 90" << endl;
    automata->coin(100);
    automata->choice("Milk");
    automata->cook();


    cout << "wait = 1, result = " << automata->getState() << endl;
    cout << "profit = 10, result = " << automata->getProfit() << endl;
    cout << "must be denied" << endl;
    automata->coin(5);
    automata->choice("Tea");
    cout << "must be accept(2)" << automata->getState() << endl;
    automata->cancel();
    cout << "must be wait(1)" << automata->getState() << endl;



    return 0;
}
}