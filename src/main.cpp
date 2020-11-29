/*
 * @author Stanislav Stoianov
 */

#include "../include/automata.h"

int main() {
    auto *automata = new Automata();
    automata->on();
    Automata::getMenu();
    automata->coin(20);
    automata->cancel();
    automata->coin(10);
    automata->choice(5);
    automata->coin(0);
    automata->choice(6);
    automata->off();
    delete(automata);
    return 0;
}

