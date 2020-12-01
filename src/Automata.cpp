// Copyright 2020 GHA Test Team
#include "Automata.h"
#include "windows.h"
#include <fstream>

void Automata::get_menu_data_from_file(std::string file_name) {
  std::string line;
  std::ifstream file("data.txt"); 
  if (file.is_open()){
    while (getline(file, line)){
      // std::cout << line << std::endl;
      std::string name;
      std::string price;
      bool name_flag = true;
      for (int i = 0; i < line.size(); i++) {
        if (name_flag && line[i] != ' ')
          name += line[i];
        if (!name_flag)
          price += line[i];
        if (line[i] == ' ')
          name_flag = false;
      }
      set_name_and_price(name, atof(price.c_str()));
    }
  }
  file.close();     
}

void Automata::set_name_and_price(std::string name, double price) {
  menu[name] = price;
}

Automata::Automata() {
  // get_menu_data_from_file();
  state = STATES::OFF;
}

void Automata::getMenu() {
  std::map <std::string, double> :: iterator it = menu.begin();
  for (int i = 0; it != menu.end(); it++, i++) {
    std::cout << it->first << ": " << it->second << std::endl;
  }
}

void Automata::on() {
  if (state == STATES::OFF)
    state = STATES::WAIT;
}

void Automata::off() {
  if (state == STATES::WAIT)
    state = STATES::OFF;
}

void Automata::coin(double coin_num) {
  if (state == STATES::WAIT || state == STATES::ACCEPT) {
    cash += coin_num;
    state = STATES::ACCEPT;
  }
}

std::string Automata::getState() const {
  std::string result = "";
  switch (state)
  {
  case STATES::OFF:
    result = "OFF";
    break;
  case STATES::WAIT:
    result = "WAIT";
    break;
  case STATES::ACCEPT:
    result = "ACCEPT";
    break;
  case STATES::CHECK:
    result = "CHECK";
    break;
  case STATES::COOK:
    result = "COOK";
    break;
  default:
    break;
  }
  return result;
}

void Automata::choice(std::string name) {
  if (state == STATES::ACCEPT) {
    std::map <std::string, double> ::iterator it = menu.begin();
    for (int i = 0; it != menu.end(); it++, i++) {
      if (it->first == name) {
        target_product = name;
        state = STATES::CHECK;
      }
    }
  }
}

bool Automata::check() {
  return (state == STATES::CHECK && cash >= menu[target_product]) ? true : false;
}

double Automata::cancel() {
  if (state == STATES::ACCEPT || state == STATES::CHECK) {
    state = STATES::WAIT;
    double cash_to_back = cash;
    cash = 0.0;
    return cash_to_back;
  }
  else
    return 0.0;
}

void Automata::cook() {
  if (state == STATES::CHECK && check()) {
    state = STATES::COOK;
    Sleep(2500);
  }
}

double Automata::finish() {
  if (state == STATES::COOK){
    state = STATES::WAIT;
    return cash - menu[target_product];
  }
  return 0.0;
}
