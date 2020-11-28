#include "Automata.h"
#include <iostream>
int main() {

    Automata automata;

    std::cout << STATES(automata.getState()) << std::endl;

    automata.on();

    std::cout << STATES(automata.getState()) << std::endl;

    std::vector <std::string> menu = automata.getMenu();
    for(auto drink:menu)
        std::cout << drink << std::endl;

    std::cout << STATES(automata.getState()) << std::endl;

    std::map<std::string, unsigned int> prices = automata.getPrices();

    for(auto drink:menu)
        std::cout << drink << ": " << prices[drink] << " tenge" << std::endl;

    std::cout << STATES(automata.getState()) << std::endl;

    automata.coin(50);

    std::cout << STATES(automata.getState()) << std::endl;

    automata.coin(25);

    std::cout << STATES(automata.getState()) << std::endl;

    automata.choice(menu[0]);

    std::cout << STATES(automata.getState()) << std::endl;

    automata.coin(100);

    std::cout << STATES(automata.getState()) << std::endl;

    automata.choice(menu[4]);

    std::cout << STATES(automata.getState()) << std::endl;

    automata.off();

    std::cout << STATES(automata.getState()) << std::endl;


    return 0;
}
