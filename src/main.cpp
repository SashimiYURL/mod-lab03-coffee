#include "Automata.h"
#include <iostream>

int main() {
    Automata automata = Automata();

    automata.on();
    automata.getMenu();
    automata.coin(40);
    automata.coin(20);
    automata.choice("Americano");
    automata.coin(60);
    automata.cancel();
    automata.choice("Latte");
    automata.off();
}