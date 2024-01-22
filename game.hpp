#pragma once
#include "board.hpp"
#include "persistenceProvider.hpp"
#include "menu.hpp"
#include "ai.hpp"
#include <iostream>

class Game{
    private:
        Board *board;
        PersistenceProvider *persistenceProvider;
        Menu menu;
        AI* ai;
        std::string *history;
        
        void takeYourTurn(char c);
        bool checkVictory();
        char getPlayersStartingTurnAfterLoading();
        void startGameAI(char turn);
        void startGamePlayer(char turn);
        void loadGameAI();
        void loadGamePlayer();
    public:
        Game();
        void start();
};