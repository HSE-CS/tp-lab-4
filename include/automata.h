//
// Created by Алексей Трутнев on 24.11.2020.
//

#ifndef AUTOMATA_AUTOMATA_H
#define AUTOMATA_AUTOMATA_H

#include <iostream>
#include <string>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:  // Доступное только системе
    unsigned int cash;
    STATES status;
    static size_t const menu_size = 6;
    std::string menu[menu_size] = {"Lungo", "Cappucino", "Matcha", "Americano", "Espresso", "Hot Chocolate"};
    unsigned int  prices[menu_size] = {25, 40, 80, 38, 31, 9};

protected:  // Доступное только внутри системы
    void check(size_t); // - проверка наличия необходимой суммы
    void cook(size_t); // - имитация процесса приготовления напитка
    void finish(); // - завершение обслуживания пользователя

public: // Доступное пользователю
    void on(); // - включение автомата
    void off(); // - выключение автомата
    void cancel(); // - отмена сеанса обслуживания пользователем
    void coin(unsigned int); //- занесение денег на счёт пользователем
    std::string getMenu() const; // - считывание меню с напитками и ценами для пользователя
    void choice(size_t); // - выбор напитка пользователем
    std::string getState() const; // - считывание текущего состояния для пользователя
    unsigned int getCash() const; // - считывание текущего количество денег

//  Constructors
    Automata() {cash = 0; status = OFF;}
};


#endif //AUTOMATA_AUTOMATA_H
