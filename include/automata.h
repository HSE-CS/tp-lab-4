#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>


enum states {ON, OFF, WAIT};

class automata {
private:
    int cash_user;
    int cash_automata;
    int choice_user;
    std::vector<std::string> menu; //only drinks
    std::vector<int> prices; //only prices
    states state;

public:
  automata();
    void on();
    void off();
    void coin(int coins);
    std::string getMenu();
    states getState();
    void choice(const std::string& user_choice);
    bool check();
    int cancel();
    void cook();
    void finish();
};