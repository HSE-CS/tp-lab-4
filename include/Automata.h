#ifndef AUTOMATA_H
#define AUTOMATA_H

enum STATES{
OFF,
WAIT,
ACCEPT,
CHECK,
COOK,
};

class Automata{
private:
double cash;
int count;
char ** menu;
double * prices;
STATES state;
int chos;
public:
Automata();
int on();
int off();
int coin(double);
char** getMenu() const;
STATES getState() const;
int choice(int);
boolean check() const;
int cansel();
int cook();
int finish();
};
#endif
