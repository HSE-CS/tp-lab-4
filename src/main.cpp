// Copyright 2020 test
#include<iostream>
#include "Automata.h"



int main() {
    Automata test;
    test.on();  // € пришел купить попить. ¬ключил автомат
    std::cout << test.getMenu();  // узнал что в меню
    test.coin(10);  // положил 10
    std::cout << test.getState() << "\n";
    test.choice(5);  // выбрал гор€чий шоколад 0_0
    std::cout << test.getState() << "\n";
    std::cout << test.getCoin() << "\n";  // а сколько € положил уже в автомат? 
    test.coin(20);  // еще 20 положить нужно :( 
    test.choice(5);  // ’ќ„” √ќ–я„»… Ўќ ќЋјƒ
    test.finish();  // ”–јјј! Ўќ ќЋјјƒ!
    test.off();  // всЄ, не нужен мне болше автомат -_-
    std::cout << test.getState() << "\n";
    return 0;
}
