#include <iostream>
#include "automata.h"

int main() {
    Automata coffee_point;
    std::cout << coffee_point.getState() << "\n";   // OFF

    coffee_point.on();
    std::cout << coffee_point.getState() << "\n";   // ON

    std::cout << coffee_point.getMenu();    // Output menu

    coffee_point.coin(300);
    std::cout << coffee_point.getCash() << "\n";    // 500
    std::cout << coffee_point.getState() << "\n";   // ACCEPT

    coffee_point.choice(5);
    std::cout << coffee_point.getState() << "\n";   // Automatically cook "DONE: Hot Chocolate"

    coffee_point.off();
    std::cout << coffee_point.getState() << "\n";   // OFF
    return 0;
}
