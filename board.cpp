#include "board.hpp"
#include <iostream>

void Board::resetBoard(){
    for (int i = 0; i < 9; i++){
        board[i] = '-';
    }
}

void Board::changeBoard(int i, char character){
    board[i] = character;
}

char Board::getSpecificChar(int i){
    return board[i];
}

void Board::setBoard(Board board){
    board = board;
}

char* Board::getBoard(){
    return board;
}

void Board::printBoard(){
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++){
            std::cout << board[(x+y*3)];

        }
        std::cout << std::endl;
    }
}