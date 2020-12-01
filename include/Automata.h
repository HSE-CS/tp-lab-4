// Copyright 2020 GHA Test Team
#ifndef INCLUDE_AUTOMATA_H
#define INCLUDE_AUTOMATA_H

#include <iostream>
#include <string>
#include <map>


enum class STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
 private:
  double cash = 0.0f;
  std::string target_product;
  std::map <std::string, double> menu = {{"coca-cola", 60.0}, {"fanta", 50.0}, {"sprite ", 55.0}, {"coffee", 30.0}};
  STATES state;
  void get_menu_data_from_file(std::string = "data.txt");
  void set_name_and_price(std::string, double);

 public:
   Automata();
   void getMenu();
   void on();
   void off();
   void coin(double);
   std::string getState() const;
   void choice(std::string);
   bool check();
   double cancel();
   void cook();
   double finish();
};

#endif  // INCLUDE_AUTOMATA_H
