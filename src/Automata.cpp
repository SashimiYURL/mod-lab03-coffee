#include "Automata.h"

#include <iostream>
#include <string>


void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "The machine is turned on. Waiting for action." << std::endl;
    }
    else {
        std::cout << "The machine is already on." << std::endl;
    }
}

void Automata::off() {
    state = OFF;
    cash = 0;
    std::cout << "The machine is off." << std::endl;
}

void Automata::coin(int amount) {
    if (state == WAIT || state == ACCEPT) {
        cash += amount;
        state = ACCEPT;
        std::cout << "Added " << amount << " rub . Current balance: " << cash << " rub." << std::endl;
    }
    else {
        std::cout << "It is not possible to deposit money in the current state." << std::endl;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        std::cout << "The operation has been cancelled. Refund of money: " << cash << " rub." << std::endl;
        cash = 0;
        state = WAIT;
    }
    else {
        std::cout << "It is not possible to cancel the operation in the current state." << std::endl;
    }
}

void Automata::choice(std::string nameDrink) {
    if (state == ACCEPT) {
        int priceDrink = -1;
        for (int drinkIndex = 0; drinkIndex < menu.size(); drinkIndex++)
        {
            if (nameDrink == menu[drinkIndex]) {
                priceDrink = prices[drinkIndex];
                state = CHECK;
                std::cout << "Drink selected: " << menu[drinkIndex] << " (" << prices[drinkIndex] << " rub.)" << std::endl;
                check(drinkIndex);
            }
        }

        if (priceDrink == -1) {
            std::cout << "This drink is not on the menu!\n";
        }
    }
    else {
        std::cout << "It is not possible to select a drink in the current state." << std::endl;
    }
}

void Automata::check(int indexDrink) {
    if (state == CHECK) {
        int selectedPrice = prices[indexDrink];
        if (cash >= selectedPrice) {
            cash -= selectedPrice;
            std::cout << "There are enough funds. The remainder: " << cash << " rub." << std::endl;
            state = COOK;
            cook();
        }
        else {
            std::cout << "There are not enough funds. Required: " << selectedPrice-cash << " rub." << std::endl;
            state = ACCEPT;
        }
    }
    else {
        std::cout <<"It is impossible to verify the amount in the current state." << std::endl;
    }
}

void Automata::cook() {
    if (state == COOK) {
        std::cout << "Making a drink..." << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << "." << std::flush;
        }
        std::cout << "\nThe drink is ready!" << std::endl;
        finish();
    }
    else {
        std::cout <<"It's impossible to make a drink in the current state." << std::endl;
    }
}

void Automata::finish() {
    if (state == COOK) {
        std::cout << "The service is completed. Return of change: " << cash << " rub." << std::endl;
        state = WAIT;
    }
    else {
        std::cout << "It is not possible to complete maintenance in the current state." << std::endl;
    }
}

STATES Automata::getState() {
    std::cout << state;
    return state;
}

void Automata::getMenu() {
    std::cout << "Drinks menu:" << std::endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << " rub." << std::endl;
    }
}

int Automata::getCash() {
    return cash;
}