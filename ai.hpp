#pragma once
#include "board.hpp"
class AI{
    private:
        Board *board;
        int pointCalculator(int numX, int numO);
        int pointChecker();
        bool choiceAvailable(int i);
    public:
        AI(Board *board);
        int AIMove();

};