#include <iostream>
#include "automata.h"

int main() {
    Automata automat;
    automat.on();

    std::cout << automat.getMenu() << std::endl;

    automat.coin(5);
    automat.coin(10);
    automat.coin(5);

    automat.choice(6);

    automat.check();

    if(automat.getState() == STATES::COOK)
    {
        automat.cook();
        std::cout << "Cooking...\n" << std::endl;
    }
    else
        std::cout << "Not enough cash...\n" << std::endl;

    automat.coin(55);
    automat.choice(6);
    automat.check();

    if(automat.getState() == STATES::COOK)
    {
        automat.cook();
        std::cout << "Cooking...\n" << std::endl;
    }

    std::cout << "Take your \"" << automat.getUserChoice().name << "\"" << std::endl;
    std::cout << "Take extra money " << automat.getUserCash() << " rub"<< std::endl;

    automat.off();

    return 0;
}