// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialStateIsOFF) {
    Automata a = Automata();
    ASSERT_EQ(STATES::OFF, a.getState());
}
TEST(AutomataTest, TurnOn) {
    Automata a = Automata();
    a.on();
    ASSERT_EQ(STATES::WAIT, a.getState());
}
TEST(AutomataTest, StateOff) {
    Automata a = Automata();
    a.off();
    ASSERT_EQ(STATES::OFF, a.getState());
}
TEST(AutomataTest, DepositMoney) {
    Automata a = Automata();
    a.on();
    a.coin(50);
    ASSERT_EQ(STATES::ACCEPT, a.getState());
    ASSERT_EQ(50, a.getCash());
}
TEST(AutomataTest, CancelOperation) {
    Automata a = Automata();
    a.on();
    a.coin(100);
    a.cancel();
    ASSERT_EQ(STATES::WAIT, a.getState());
    ASSERT_EQ(0, a.getCash());
}
TEST(AutomataTest, InsertMoreCoinsInACCEPTState) {
    Automata a = Automata();
    a.on();
    a.coin(60);
    a.coin(40);
    ASSERT_EQ(STATES::ACCEPT, a.getState());
    ASSERT_EQ(100, a.getCash());
}
TEST(AutomataTest, ChoiceDrinkHaveMoney) {
    Automata a = Automata();
    a.on();
    a.coin(100);
    a.choice("Cappuccino");
    ASSERT_EQ(STATES::WAIT, a.getState());
    ASSERT_EQ(40, a.getCash());
}
TEST(AutomataTest, ChoiceDrinkDontHaveMoney) {
    Automata a = Automata();
    a.on();
    a.coin(50);
    a.choice("Cappuccino");
    ASSERT_EQ(STATES::ACCEPT, a.getState());
    ASSERT_EQ(50, a.getCash());
}
TEST(AutomataTest, OFFFromACCEPTState) {
    Automata a = Automata();
    a.on();
    a.coin(100);
    a.off();
    ASSERT_EQ(STATES::ACCEPT, a.getState());
    ASSERT_EQ(100, a.getCash());
}
TEST(AutomataTest, ChoiceInvalidDrink) {
    Automata a = Automata();
    a.on();
    a.coin(50);
    a.choice("Juice");
    ASSERT_EQ(STATES::ACCEPT, a.getState());
}
TEST(AutomataTest, MultipleCoinsSumCorrectly) {
    Automata a = Automata();
    a.on();
    a.coin(10);
    a.coin(20);
    a.coin(5);
    ASSERT_EQ(35, a.getCash());
}
TEST(AutomataTest, DepositMoneyWhenOFF) {
    Automata a = Automata();
    a.coin(50);
    ASSERT_EQ(STATES::OFF, a.getState());
    ASSERT_EQ(0, a.getCash());
}
TEST(AutomataTest, CancelInOn) {
    Automata a = Automata();
    a.on();
    a.cancel();
    ASSERT_EQ(STATES::WAIT, a.getState());
}

TEST(AutomataTest, BuyTwoDrinks) {
    Automata a = Automata();
    a.on();
    a.coin(50);
    a.choice("Latte");
    ASSERT_EQ(STATES::WAIT, a.getState());
    a.coin(20);
    a.choice("Milk");
    ASSERT_EQ(STATES::WAIT, a.getState());
    ASSERT_EQ(0, a.getCash());
}












