#pragma once

class Board{
    private:
        char board[9];
    
    public:
        void setBoard(Board);
        void changeBoard(int i, char character);
        void resetBoard();
        void printBoard();
        char getSpecificChar(int i);
        char* getBoard();

};