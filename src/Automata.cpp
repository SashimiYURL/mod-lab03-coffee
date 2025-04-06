//Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>
#include <string>

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "The machine is turned on. Waiting for action.\n";
    } else {
        std::cout << "The machine is already on.\n";
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        cash = 0;
        std::cout << "The machine is off.\n";
    } else {
        std::cout << "Can not turn OFF the automata in this state!\n";
    }
}

void Automata::coin(int amount) {
    if (state == WAIT || state == ACCEPT) {
        cash += amount;
        state = ACCEPT;
        std::cout << "Added " << amount << "rub.";
        std::cout << "Current balance: " << cash << "rub.\n";
    } else {
        std::cout << "It is impossible to deposit money.\n";
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        std::cout << "The operation has been cancelled.";
        std::cout << "Refund of money: " << cash << " rub.\n";
        cash = 0;
        state = WAIT;
    } else {
        std::cout << "It is not possible to cancel the operation.\n";
    }
}

void Automata::choice(std::string nameDrink) {
    if (state == ACCEPT) {
        int priceDrink = -1;
        for (int drinkIndex = 0; drinkIndex < menu.size(); drinkIndex++) {
            if (nameDrink == menu[drinkIndex]) {
                priceDrink = prices[drinkIndex];
                state = CHECK;
                std::cout << "Drink selected: " << menu[drinkIndex];
                std::cout << " (" << prices[drinkIndex] << " rub.)\n";
                check(drinkIndex);
            }
        }
        if (priceDrink == -1) {
            std::cout << "This drink is not on the menu!\n";
        }
    } else {
        std::cout << "You cannot select a drink in the current state.\n";
    }
}

void Automata::check(int indexDrink) {
    if (state == CHECK) {
        int selectedPrice = prices[indexDrink];
        if (cash >= selectedPrice) {
            cash -= selectedPrice;
            std::cout << "There are enough funds.";
            std::cout << "The remainder: " << cash << " rub.\n";
            state = COOK;
            cook();
        } else {
            std::cout << "There are not enough funds.";
            std::cout << "Required: " << selectedPrice - cash << " rub.\n";
            state = ACCEPT;
        }
    } else {
        std::cout <<"The amount cannot be verified in the current state.\n";
    }
}

void Automata::cook() {
    if (state == COOK) {
        std::cout << "Making a drink...\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << "." << std::flush;
        }
        std::cout << "\nThe drink is ready!\n";
        finish();
    } else {
        std::cout <<"It's impossible to make a drink in the current state.\n";
    }
}

void Automata::finish() {
    if (state == COOK) {
        std::cout << "The service is completed.";
        std::cout << "Return of change: " << cash << " rub.\n";
        state = WAIT;
    } else {
        std::cout << "It is not possible to complete maintenance.\n";
    }
}

STATES Automata::getState() {
    std::cout << state;
    return state;
}

void Automata::getMenu() {
    std::cout << "Drinks menu:\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << menu[i] << " - " << prices[i] << " rub.\n";
    }
}

int Automata::getCash() {
    return cash;
}
