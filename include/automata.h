//
// Created by victor on 25.11.2020.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H
#include <string>
#include <vector>

typedef struct {
    std::string name;
    int price;
} ITEM;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK , len };

class Automata
{
private:
    STATES state;

    double all_cash;
    double user_cash;
    int user_choice = 0;

    static std::vector<ITEM> menu;

    bool is_in_states(STATES *states);
    bool check_and_change(STATES *check_states, STATES new_state);

public:
    bool on();
    bool off();
    bool coin(double money);
    bool choice(int num);
    bool check();
    bool cancel();
    bool cook();
    bool finish();

    static std::string getMenu();
    STATES getState();
    ITEM getUserChoice();
    double getUserCash();

    Automata();
};
#endif //TASK1_AUTOMATA_H
