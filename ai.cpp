#include "ai.hpp"
#include "board.hpp"


AI::AI(Board *board){
    this->board = board;
}

int AI::AIMove(){
    if (choiceAvailable(4)){
        return 4;
    }
    else{
        return (pointChecker());
    }
}

int AI::pointCalculator(int numX, int numO){
    if (numO == 1 && numX == 0)
        {
            return 2;
        }
        else if (numO == 2 && numX == 0)
        {
            return 4;
        }
        else if (numO == 0 && numX == 2)
        {
            return 3;
        }
        else
        {
            return 0;
        }
}

int AI::pointChecker(){
    int maxPoints = 0;
    int maxNumber = 0;

    //Goes through all the options
    for (int choice = 0; choice < 9; choice++)
    {
        if(choiceAvailable(choice))
        {
            int points = 0;
            int numX = 0;
            int numO = 0;

            //Check horizontal
            for (int x = 0; x < 3; x++)
            {
                if (board->getSpecificChar(choice / 3 * 3 + x) == 'o')
                {
                    numO++;
                }
                else if (board->getSpecificChar(choice / 3 * 3 + x) == 'x')
                {
                    numX++;
                }
            }
            if (pointCalculator(numX, numO) > points)
            {
                points = pointCalculator(numX, numO);
            }

            //Reset values
            numX = 0;
            numO = 0;

            //Check Vertical
            for (int y = 0; y < 3; y++)
            {
                if (board->getSpecificChar(y*3 + choice % 3) == 'o')
                {
                    numO++;
                }
                else if (board->getSpecificChar(y*3 + choice % 3) == 'x')
                {
                    numX++;
                }
            }
            if (pointCalculator(numX, numO) > points)
            {
                points = pointCalculator(numX, numO);
            }

            //Reset values
            numX = 0;
            numO = 0;

            //Check diagonal
            if(choice == 0 || choice == 4 || choice == 8)
            {
                for (int xy = 0; xy < 3; xy++)
                {
                    if (board->getSpecificChar(xy*6) == 'o')
                    {
                        numO++;
                    } 
                    else if (board->getSpecificChar(xy*6) == 'x')
                    {
                        numX++;
                    }
                }
            }
            else if(choice == 2 || choice == 4 || choice == 6)
            {
                for (int xy = 0; xy < 3; xy++)
                {
                    if (board->getSpecificChar(xy * 3 + 2-xy) == 'o')
                    {
                        numO++;
                    } 
                    else if (board->getSpecificChar(xy * 3 + 2-xy) == 'x')
                    {
                        numX++;
                    }
                }
            }
            if (pointCalculator(numX, numO) > points)
            {
                points = pointCalculator(numX, numO);
            }

            if (points > maxPoints)
            {
                maxPoints = points;
                maxNumber = choice;
            }
        }
    }

    //If all the moves are equal, pick the first move available.
    if (maxNumber == 0)
    {
        for (int firstChoice = 0; firstChoice < 9; firstChoice++)
        {
            if (choiceAvailable(firstChoice))
            {
                return firstChoice;
            }
        }
    }
    else
    {
        return maxNumber;
    }
    return 0;
    
}

bool AI::choiceAvailable(int i){
    if (board->getSpecificChar(i) == '-'){
        return true;
    }
    return false;
}