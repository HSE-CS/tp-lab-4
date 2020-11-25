#include "automata.h"

int main(){
    Automata *a = new Automata();
    cout << a->on() << endl;

    a->printMenuToConsole();
    cout << a->coin(12.0) << endl;
    cout << a->coin(20.0) << endl;
    cout << a->off() << endl;
    cout << a->choice("coffee") << endl;
    cout << a->cook() << endl;

    cout << endl;
    cout << a->off() << endl;
    return 0;
}