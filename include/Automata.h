#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED

#include <vector>
#include<string>
#include <map>


enum STATES
{
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata
{
private:
    unsigned int cash;
    static std::vector<std::string> menu;
    static std::map<std::string, unsigned int> prices;
    STATES state;

    bool check(unsigned int cost);
    void cook();
    void finish();

public:
    Automata();
    void on();
    void off();
    void coin(unsigned int dep);
    std::vector<std::string> getMenu();
    std::map<std::string, unsigned int> getPrices();
    unsigned int getCash();
    STATES getState();
    void choice(std::string drink);
    void cancel();
};
#endif
