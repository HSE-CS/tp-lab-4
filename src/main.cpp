#include "Automata.h"

int main() {
    Automata example;
    example.coin(10);
    example.on();

    cout << endl << "**** COFFEE MACHINE ****" << endl;
    cout << "------------------------" << endl;
    cout << example.getMenu();
    cout << "------------------------" << endl;

    example.coin(10);
    example.coin(10);
    example.coin(10);
    example.coin(5);

    example.choice("cappuccino");
    if (example.check())
        example.cook();
    else
        cerr << "NOT ENOUGH MONEY" << endl;

    example.coin(10);

    example.choice("tea");
    if (example.check())
    {
        cout << "tea is ";
        example.cook();
    }
    else
        cerr << "NOT ENOUGH MONEY" << endl;

    example.choice("milk");
    if (example.check())
    {
        cout << "milk is ";
        example.cook();
    }
    else
        cerr << "NOT ENOUGH MONEY" << endl;

    example.finish();
}