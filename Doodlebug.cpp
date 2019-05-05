/*************************************************************
* Group # 4
* Program name: Doodlebug.cpp
* Date: 5/4/2019
* Description:
*************************************************************/

#include "Doodlebug.hpp"

Doodlebug::Doodlebug(int r, int c)
{
    adult_life = 8;
    life = 0;
    row = r;
    col = c;
    type_name = "Doodlebug";
}

// Doodlebug asks to move in char direction
char Doodlebug::move(Board board)
{

    int boardRow = board.get_num_row(),
        boardCol = board.get_num_col();

    int tempDown = row + 1;
    int tempUp = row - 1;
    int tempRight = col + 1;
    int tempLeft = col - 1;

    //Checks if new coordinates are in bounds and if new resulting
    //coordinates contain an ant. If so, ask to move there
    if (tempDown < boardRow)
    {
        if (board.get_type(tempDown, col) == "Ant")
        {
            return 'D';
        }
    }

    else if (tempUp > 0)
    {
        if (board.get_type(tempUp, col) == "Ant")
        {
            return 'U';
        }
    }

    else if (tempRight < boardCol)
    {
        if (board.get_type(row, tempRight) == "Ant")
        {
            return 'R';
        }
    }

    else if (tempLeft > 0)
    {
        if (board.get_type(row, tempLeft) == "Ant")
        {
            return 'L';
        }
    }


    //Randomly pick 1 of 4 cardinal directions
    int direction = Helper::randInt(0, 3);

    //Up for 0
    if (direction == 0)
        return 'U';

    //Right for 1
    else if (direction == 1)
        return 'R';

    //Down for 2
    else if (direction == 2)
        return 'D';

    //Left for 3
    else
        return 'L';
}