/*
 * @author Stanislav Stoianov
 */

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <string>
#include <vector>

enum class STATE {
    OFF, WAIT, ACCEPT, CHECK, COOK
};

struct PRODUCT {
    std::string name;
    unsigned int price;
};

class Automata {
private:

    unsigned int cash;

    unsigned int order;

    STATE state;

    static std::vector<PRODUCT> menu;

    bool check();

    bool cook();

    bool finish();

    unsigned int getCash() const;

    unsigned int getChoice() const;

public:
    Automata();

    bool on();

    bool off();

    bool coin(unsigned int money);

    bool choice(unsigned int orderNum);

    bool cancel();

    static void getMenu();

    STATE getState();
};

#endif