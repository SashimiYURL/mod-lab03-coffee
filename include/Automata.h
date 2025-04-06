//Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H
#define INCLUDE_AUTOMATA_H
#include <vector>
#include <string>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};
class Automata {
public:
    void on();
    void off();
    void coin(int money);
    void choice(std::string nameDrink);
    void cancel();
    STATES getState();
    void getMenu();
    int getCash();
    Automata() {
        cash = 0;
        state = OFF;
        menu = { "Latte", "Americano", "Milk", "Cappuccino" };
        prices = { 30, 50, 40, 60 };
    }

private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    void check(int indexDrink);
    void cook();
    void finish();
};
#endif //INCLUDE_AUTOMATA_H