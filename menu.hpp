#pragma once

#include <iostream>

class Menu{

    public:
        void printWinScreen(char character);
        void printTakeYourTurn(char character);
        void printPlaceAlreadyTaken();
        void printStartMenu();
        void printStartMenuInvalidOption();
        void printHistory(std::string history);
        void printDeleted();
};