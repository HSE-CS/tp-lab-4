// Copyright 2020 Dev-will-work
#include <cstdlib>
#include <iostream>
#include "Automata.h"
Automata::Automata() {
  this->state = STATES::OFF;
  this->all_income = 0;
  this->cash = 0;
  this->sugar = 0;
}

void Automata::on() {
  if (this->state != STATES::OFF) return;
  this->state = STATES::WAIT;
}

void Automata::off() {
  if (this->state != STATES::WAIT) return;
  this->state = STATES::OFF;
}

void Automata::coin(int money) {
  if (this->state != STATES::WAIT && this->state != STATES::ACCEPT) return;
  this->state = STATES::ACCEPT;
  this->cash += money;
  this->all_income += money;
}

const std::map<std::string, size_t>& Automata::getMenu() {
  return this->menu;
}

const STATES Automata::getState() {
  return this->state;
}

const size_t Automata::getBalance() {
  return this->cash;
}

void Automata::choice(std::string name, uint16_t sugar_count = 1) {
  if (this->state != STATES::ACCEPT) return;
  this->sugar = sugar_count;
  this->state = STATES::CHECK;
  check(name);
}

void Automata::check(std::string name) {
  if (this->state != STATES::CHECK ||
  this->menu.find(name) == this->menu.end()) {
  cancel();
  return;
  }
  if (this->menu[name] > this->cash) {
  cancel();
  } else {
  this->cash -= this->menu[name];
  cook(name);
  }
}

void Automata::cancel() {
  if (this->state != STATES::CHECK && this->state != STATES::ACCEPT) return;
  if (this->state == STATES::ACCEPT) this->cash = 0;
  this->state = STATES::WAIT;
}

void Automata::cook(std::string name) {
  if (this->state != STATES::CHECK) return;
  this->state = STATES::COOK;
  _sleep(3000);
  finish();
}

void Automata::finish() {
  if (this->state != STATES::COOK) return;
  this->sugar = 0;
  this->state = STATES::WAIT;
}

void printMenu(std::map<std::string, size_t> menu) {
  for (auto it : menu) {
  std::cout << "  " << it.first << "  " << it.second << std::endl;
  }
}

const size_t Automata::getMenuSize() {
  return this->menu.size();
}
