#include<vector>
#include<iostream>
#include<map>



enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};
class Automata
{
  private:
    STATES state;
    std::map<std::string, int> menu{{"tea", 30}, {"coffee", 50}, {"capuchino", 75}, {"chocolate", 60}, {"water", 20}};
    int cash; //- для хранения текущей суммы;

  public:
    Automata();// конструктор
    void on(); // - включение автомата;
    void off(); // - выключение автомата;
    void coin(int summ); // - занесение денег на счёт пользователем;
    std::map<std::string, int> getMenu(); // -  меню с напитками и ценами для пользователя;
    STATES getState(); // - текущее состояния для пользователя;
    void choice(std::string drink_name); // - выбор напитка пользователем;
    bool check(std:: string); // - проверка наличия необходимой суммы;
    void cancel(); // - отмена сеанса обслуживания пользователем;
    void cook(); // - имитация процесса приготовления напитка;
    void finish(); // - завершение обслуживания пользователя.
};
