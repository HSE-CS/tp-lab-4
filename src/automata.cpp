#include "automata.h"

Automata::Automata() {
    this->state=STATES::OFF;

    this->all_cash = 0;
    this->user_cash = 0;
    this->user_choice = 0;
}

std::vector<ITEM> Automata::menu = {
    {"Black Tea", 10},
    {"Green Tea", 10},
    {"Black Coffee", 20},
    {"Mochaccino", 40},
    {"Cappuccino", 50},
    {"Latte", 70}
};

bool Automata::is_in_states(STATES* states){
    for(int i = 0; i < STATES::len; i++){
        if (this->state == states[i])
            return true;
    }
    return false;
}

bool Automata::check_and_change(STATES * check_states, STATES new_state){
    if (is_in_states(check_states)) {
        this->state = new_state;
        return EXIT_SUCCESS;
    }else
        return EXIT_FAILURE;
}

bool Automata::on() {
    STATES old_states[] = {STATES::OFF};
    return Automata::check_and_change(
            old_states,
            STATES::WAIT
            );
}

bool Automata::off(){
    STATES old_states[] = {STATES::WAIT};
    return Automata::check_and_change(
            old_states,
            STATES::OFF
    );
}

bool Automata::coin(double money){
    this->user_cash += money;
    this->all_cash += money;

    STATES old_states[] = {STATES::WAIT, STATES::ACCEPT};
    return Automata::check_and_change(
            old_states,
            STATES::ACCEPT
    );
}

bool Automata::choice(int num){
    this->user_choice = num-1;

    STATES old_states[] = {STATES::ACCEPT};
    return Automata::check_and_change(
            old_states,
            STATES::CHECK
    );
}

bool Automata::cancel(){
    this->user_cash = 0;
    this->user_choice = 0;

    STATES old_states[] = {STATES::CHECK, STATES::ACCEPT};
    return Automata::check_and_change(
            old_states,
            STATES::WAIT
    );
}

bool Automata::check(){
    STATES old_states[] = {STATES::CHECK};
    STATES st;
    if (Automata::menu[this->user_choice].price < this->user_cash)
    {
        st = STATES::COOK;
    } else{
        st = STATES::ACCEPT;
    }
    return Automata::check_and_change(
            old_states,
            st
    );
}

bool Automata::cook(){
    this->user_cash -= Automata::menu[this->user_choice].price;

    STATES old_states[] = {STATES::COOK};
    return Automata::check_and_change(
            old_states,
            STATES::COOK
    );
}

bool Automata::finish(){
    this->user_choice = 0;

    STATES old_states[] = {STATES::COOK};
    return Automata::check_and_change(
            old_states,
            STATES::WAIT
    );
}

std::string Automata::getMenu(){
    std::string menu_str;
    int max_len = 0;
    for (const auto& item: menu)
        if (max_len < item.name.length())
            max_len = item.name.length();
    for (int j = 0; j < (max_len + 9)/2; j++)
        menu_str.push_back(' ');
    menu_str.append("MENU:\n\n");
    auto it = Automata::menu.begin();
    for (int i = 0; it != Automata::menu.end(); it++, i++) {
        menu_str.append(std::to_string(i+1));
        menu_str.append(") ");
        menu_str.append(it->name);
        for (int j = it->name.length(); j < max_len; j++)
            menu_str.push_back(' ');
        menu_str.append(" ");
        menu_str.append(std::to_string(it->price));
        menu_str.append(" rub\n");
    }
    return menu_str;
}

STATES Automata::getState() {
    return this->state;
}

ITEM Automata::getUserChoice() {
    return Automata::menu[this->user_choice];
}

double Automata::getUserCash(){
    return this->user_cash;
}