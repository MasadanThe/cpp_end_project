#include "board.hpp"
#include "persistenceProvider.hpp"

#include <fstream>
#include <iostream>
#include <sstream>



void PersistenceProvider::loadGame(Board *board){
    std::ifstream inputFile("savedGame.txt");
    std::string line;
    int i = 0;

    while(std::getline(inputFile, line)){

        board->changeBoard(i, line[0]);
        i++;
    }
    inputFile.close();
}

void PersistenceProvider::saveGame(Board *board){
    std::ofstream outputFile("savedGame.txt");
    for (int i = 0; i < 9; i++){

        outputFile << board->getSpecificChar(i) << std::endl;
    }

    outputFile.close();
}

void PersistenceProvider::loadHistory(std::string *history){
    std::ifstream inputFile("savedHistory.txt");
    std::string line;

    while(std::getline(inputFile, line)){
        history->append(line);
    }
    inputFile.close();
}

void PersistenceProvider::saveHistory(std::string *history){
    std::ofstream outputFile("savedHistory.txt");
    for (int i = 0; i < history->size(); i++){
        outputFile << history->at(i) << std::endl;
    }

    outputFile.close();
}