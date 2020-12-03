#include <iostream>
#include "automata.h"


using namespace std;
int main() {
    Automata* automata = new Automata();

    cout << "ignor" << endl;
    automata->coin(10);
    automata->cancel();
    automata->cook();
    
    cout << "print menu, automato is ready" << endl;
    automata->on();
    automata->printMenu();

    cout << "ignor" << endl;
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
    cout <<"must be accept(2)" <<  automata->getState() << endl;
    automata->cancel();
    cout << "must be wait(1)" << automata->getState() << endl;



	return 0;
}
