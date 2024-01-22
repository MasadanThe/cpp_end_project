#include "menu.hpp"
#include <iostream>

void Menu::printTakeYourTurn(char character){
    std::cout << "Write 0 - 8 to where you want to place your " << character << std::endl;
}

void Menu::printWinScreen(char character){
    if (character == '-'){
        std::cout << "There was a draw!" << std::endl;
    }

    else{
    std::cout << "Player " << character << " won!" << std::endl;
    }
}

void Menu::printPlaceAlreadyTaken(){
    std::cout << "That place is already taken, please try again" << std::endl;
}

void Menu::printStartMenu(){
    std::cout 
    << "Choose what you want to do!" 
    << std::endl 
    << "1. Start game vs AI." 
    << std::endl 
    << "2. Start game vs another player." 
    << std::endl 
    << "3. Load previous game with AI."
    << std::endl
    << "4. Load previous game with another player."
    << std::endl
    << "5. See game history."
    << std::endl
    << "6. Delete previous game and history."
    << std::endl;
}

void Menu::printStartMenuInvalidOption(){
    std::cout << "Sorry that option is invalid, please try again!" << std::endl;
}

void Menu::printHistory(std::string history){

    for (int i = 0; i < history.size(); i++){
        std::cout << "Winner: " << history.at(i) << std::endl;
    }
}

void Menu::printDeleted(){
    std::cout << "Your previous game and all history has been deleted!" << std::endl;
}