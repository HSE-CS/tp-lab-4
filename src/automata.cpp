/*
 * @author Stanislav Stoianov
 */

#include <iostream>
#include <cstring>
#include <thread>
#include "../include/automata.h"

char *getCurrentTime() {
    time_t mytime = time(nullptr);
    char *time_str = ctime(&mytime);
    time_str[strlen(time_str) - 1] = '\0';
    return time_str;
}

std::vector<PRODUCT> Automata::menu = {
        {"Green Tea",      12},
        {"Black Tea",      10},
        {"White Tea",      11},
        {"Yellow Tea",     17},
        {"Oolong Tea",     14},
        {"Puer Tea",       16},
        {"Chamomile Tea",  20},
        {"Rosehip Tea",    14},
        {"Mint Tea",       18},
        {"Strawberry Tea", 15}
};

Automata::Automata() {
    this->status = STATUS::OFF;
    this->cash = 0;
    this->order = 0;
}

bool Automata::on() {
    if (this->status != STATUS::OFF) return false;
    this->status = STATUS::WAIT;
    printf("[%s] INFO: Вендинговая машина включена\n",
           getCurrentTime());
    return true;
}

bool Automata::off() {
    if (this->status != STATUS::WAIT) return false;
    this->status = STATUS::OFF;
    printf("[%s] INFO: Вендинговая машина выключена\n",
           getCurrentTime());
    return true;
}

bool Automata::coin(unsigned int money) {
    if (this->status != STATUS::WAIT && this->status != STATUS::ACCEPT) {
        printf("[%s] INFO: Деньги не были положены на депозит, неверное состояние машины\n",
               getCurrentTime());
        return false;
    } else {
        this->status = STATUS::ACCEPT;
        this->cash += money;
        printf("[%s] INFO: Деньги были положены на депозит, на счёту %u\n",
               getCurrentTime(), this->getCash());
        return true;
    }
}

bool Automata::choice(unsigned int orderNum) {
    if (this->status == STATUS::ACCEPT) {
        if (orderNum == 0 || orderNum > Automata::menu.size())
            return false;
        this->status = STATUS::CHECK;
        this->order = orderNum - 1;
        printf("[%s] INFO: Напиток %s выбран, проверка денежных средств...\n",
               getCurrentTime(), menu[this->getChoice()].name.c_str());
        return check();
    } else {
        printf("[%s] ERROR: Ничего не было выбрано - неверояное состояние или выбор из меню\n",
               getCurrentTime());
        return false;
    }
}

bool Automata::check() {
    if (this->cash < menu[order].price) {
        printf("[%s] ERROR: Не хватате денег на депозите, пополните счёт\n",
               getCurrentTime());
        return false;
    } else {
        printf("[%s] INFO: Деньги %u списаны со счёта\n",
               getCurrentTime(), menu[order].price);
        this->cash -= menu[order].price;
        return cook();
    }
}

bool Automata::cancel() {
    if (this->status != STATUS::ACCEPT && this->status != STATUS::CHECK) {
        printf("[%s] ERROR: Невозможно сделать отмену\n",
               getCurrentTime());
        return false;
    } else {
        this->status = STATUS::WAIT;
        this->order = 0;
        printf("[%s] INFO: Машина переведена в состояние ожидания, выбор очищен\n",
               getCurrentTime());
        return true;
    }
}

bool Automata::cook() {
    this->status = STATUS::COOK;
    printf("[%s] INFO: Напиток готовится...\n",
           getCurrentTime());
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    printf("[%s] INFO: Напиток готов, на депозите %u денег \n",
           getCurrentTime(), this->getCash());
    return finish();
}

bool Automata::finish() {
    this->status = STATUS::WAIT;
    printf("[%s] INFO: Машина переведена в статус ожидания\n",
           getCurrentTime());
    return true;
}

void Automata::getMenu() {
    printf("[%s] INFO: Меню выводится...\n",
           getCurrentTime());
    for (auto &i : menu) std::cout << "Напиток " << i.name << " по цене " << i.price << std::endl;
}

unsigned int Automata::getCash() const {
    return this->cash;
}

unsigned int Automata::getChoice() const {
    return this->order;
}
