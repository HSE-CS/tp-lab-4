#include<vector>
#include<iostream>
#include<map>
#include "Automata.h"
#include <unistd.h>
using namespace std;

Automata::Automata() {
  cash = 0;
  state = STATES::OFF;
}

void Automata::on() {
  cash = 0;
  if (state == STATES::OFF)
    state = STATES::WAIT;
  else
    cout << "Machine is already swithed on\n";
}

void Automata::off() {
  cash = 0;
  if (state == STATES::WAIT)
    state = STATES::OFF;
  else
    cout << "ALERT, Please finish the action\n";
}

void Automata::coin(int summ) {
  if(state == STATES::WAIT || state == STATES::ACCEPT) {
    cash += summ;
    state = STATES::ACCEPT;
  }
  else
    cout << "ALERT, Can't accept the money\n";
}

std::map<std::string, int> Automata::getMenu() {
  return menu;
}

STATES Automata::getState() {
  return state;
}

bool Automata::check(std::string drink_name) {
  if (menu[drink_name] <= cash)
    return true;
  return false;
}

void Automata::cancel() {
  if(state == STATES::ACCEPT || state == STATES::CHECK)
    state = STATES::WAIT;
}

void Automata::choice(std::string drink_name) {
  if (state == STATES::ACCEPT)
    state = STATES::CHECK;
  else
  {
    cout << "ALERT, can't go to choice drink\n";
    return;
  }

  if (check(drink_name))
  {
    cash -= menu[drink_name];
    cook();
  }
  else
  {
    cout << "lack of money!\n";
    cancel();
  }
}

void Automata::finish() {
  if (state == STATES::COOK)
  {
    state = STATES::WAIT;
  }
}

void Automata::cook() {
  if (state == STATES::CHECK)
  {
    state = STATES::COOK;

    for (int i = 0; i < 21; i++)
    {
      printf("%c", '.');
    }
    printf("\r");
    for (int i = 0; i < 21; i++)
    {
      printf("Cooking: ");
      for(int j = 0; j < i; j++)
      {

        printf("%c", '|');
      }
      printf("%d%%", i * 5);
      printf("\r");
      usleep(100000);
      fflush(stdout);
    }
    printf("\n");
  }

  else {
    cout << "ALERT, machine can't cooks now\n";
  }
  finish();
}
