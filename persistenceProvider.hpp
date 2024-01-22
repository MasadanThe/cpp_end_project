#pragma once
#include "board.hpp"
#include <iostream>


class PersistenceProvider{

    public:
        void loadGame(Board *board);
        void saveGame(Board *board);
        void loadHistory(std::string *history);
        void saveHistory(std::string *history);
    
};