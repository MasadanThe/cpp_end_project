#include "game.hpp"
#include "board.hpp"
#include "persistenceProvider.hpp"
#include "menu.hpp"
#include <iostream>

int main(){
    Game *game = new Game();

    game->start();
    delete(game);
    return 0;
}