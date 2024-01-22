#include "game.hpp"


Game::Game(){
    board = new Board();
    ai = new AI(board);
    history = new std::string();
    
}

void Game::start(){
    bool end = false;
    char useless;

    //Reset board
    board->resetBoard();
    //Load history
    persistenceProvider->loadHistory(history);

    while(!end){

    menu.printStartMenu();

    char input;
    std::cin >> input;
    switch (input)
    {
        case '1':
            startGameAI('x');
            end = true;
            break;
        
        case '2':
            startGamePlayer('x');
            end = true;
            break;

        case '3':
            loadGameAI();
            end = true;
            break;
        
        case '4':
            loadGamePlayer();
            end = true;
            break;

        case '5':
            menu.printHistory(*history);
            break;

        case '6':
            history->clear();
            board->resetBoard();

            persistenceProvider->saveGame(board);
            persistenceProvider->saveHistory(history);
            menu.printDeleted();
            break;

        default:
            menu.printStartMenuInvalidOption();
            break;
        }
    }
    //Reset board since the game was finished
    board->resetBoard();
    persistenceProvider->saveGame(board);

    persistenceProvider->saveHistory(history);

    delete(ai);
    delete(board);
    delete(history);
    std::cin >> useless;
}

void Game::startGameAI(char turn){
    bool end = false;

    //If it is AI:s turn
    if (turn == 'o'){

        //Ai takes its turn
        board->changeBoard(ai->AIMove(), 'o');

        //Checks if someone has won
        if(checkVictory()){
            end = true;
        }
    }

    while(!end){
        //Saves the board before the player takes its turn
        persistenceProvider->saveGame(board);

        //Prints out the board
        board->printBoard();

        //Player x's turn
        takeYourTurn('x');

        //Check if someone has won
        if(checkVictory()){
            end = true;
            break;
        }
        
        //Ai takes its turn
        board->changeBoard(ai->AIMove(), 'o');

        //Check if someone has won
        if(checkVictory()){
            end = true;
            break;
        }
    }

}

void Game::startGamePlayer(char turn){
    bool end = false;
    char playersTurn = turn;

    while(!end){
        //Save the board
        persistenceProvider->saveGame(board);

        //Prints out the board
        board->printBoard();

        //Players turn
        takeYourTurn(playersTurn);

        //Check if someone has won
        if(checkVictory()){
            end = true;
            break;
        }

        //Change players turn
        if(playersTurn == 'x'){
            playersTurn = 'o';
        }
        else{
            playersTurn = 'x';
        }
    }
}

void Game::loadGameAI(){
    //Loads the last game
    persistenceProvider->loadGame(board);

    //Starts the game
    startGameAI(getPlayersStartingTurnAfterLoading());
    
}

void Game::loadGamePlayer(){
    //Loads the last game
    persistenceProvider->loadGame(board);

    //Starts the game
    startGamePlayer(getPlayersStartingTurnAfterLoading());
}

char Game::getPlayersStartingTurnAfterLoading(){
    int numX = 0;
    int numO = 0;

    //Counts how many time each player has played
    for (int i = 0; i < 9; i++){
        if(board->getSpecificChar(i) == 'x'){
            numX++;
        }
        else if(board->getSpecificChar(i) == 'o'){
            numO++;
        }
    }

    //If they have played the same amount of times it means that it is player x turn since they started
    if(numX == numO){
        return 'x';
    }
    else{
        return 'o';
    }

}

void Game::takeYourTurn(char c){
    bool validInput = false;

    while (!validInput){
        int input;
        //Printing to console
        menu.printTakeYourTurn(c);
        std::cin >> input;

        //If the choice is available
        if (board->getSpecificChar(input) == '-'){
            board->changeBoard(input, c);
            validInput = true;
        }
        else{
            menu.printPlaceAlreadyTaken();
        }
    }
}

bool Game::checkVictory(){
    char victory = '-';

    bool movesLeft = false;

    //Checks if all the places in the board has been filled
    for (int i = 0; i < 9; i++){
        if (board->getSpecificChar(i) == '-'){
            movesLeft = true;
        }
    }

    //Check horizontal
    if (board->getSpecificChar(0) == board->getSpecificChar(1) && board->getSpecificChar(1) == board->getSpecificChar(2)){
        victory = board->getSpecificChar(0);
    }
    else if (board->getSpecificChar(3) == board->getSpecificChar(4) && board->getSpecificChar(4) == board->getSpecificChar(5)){
        victory = board->getSpecificChar(3);
    }
    else if (board->getSpecificChar(6) == board->getSpecificChar(7) && board->getSpecificChar(7) == board->getSpecificChar(8)){
        victory = board->getSpecificChar(6);
    }

    //Check vertical
    else if (board->getSpecificChar(0) == board->getSpecificChar(3) && board->getSpecificChar(3) == board->getSpecificChar(6)){
        victory = board->getSpecificChar(0);
    }
    else if (board->getSpecificChar(1) == board->getSpecificChar(4) && board->getSpecificChar(4) == board->getSpecificChar(7)){
        victory = board->getSpecificChar(1);
    }
    else if (board->getSpecificChar(2) == board->getSpecificChar(5) && board->getSpecificChar(5) == board->getSpecificChar(8)){
        victory = board->getSpecificChar(2);
    }

    //Check diagonal
    else if (board->getSpecificChar(0) == board->getSpecificChar(4) && board->getSpecificChar(4) == board->getSpecificChar(8)){
        victory = board->getSpecificChar(0);
    }
    else if (board->getSpecificChar(2) == board->getSpecificChar(4) && board->getSpecificChar(4) == board->getSpecificChar(6)){
        victory = board->getSpecificChar(2);
    }


    //If there is a winner
        if(victory == 'o' || victory == 'x')
        {
            board->printBoard();
            menu.printWinScreen(victory);
            
            history->append(1, victory);
            return true;
        }
        //If there is a draw
        else if (!movesLeft)
        {
            board->printBoard();
            menu.printWinScreen('-');
            history->append(1, '-');
            return true;
        }
        else
        {
            return false;
        }
}