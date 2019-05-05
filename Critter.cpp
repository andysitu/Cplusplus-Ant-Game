/*************************************************************
* Group # 4
* Program name: Critter.cpp
* Date: 5/4/2019
* Description: This is the source file for the ant class for CS162's group project. The ant 
*  class is derived from the critter base class detailed in "critter.hpp".
*  This file implements the member variables and functions for used for the predator-prey
*  game used for ants.
*************************************************************/

#include "Critter.hpp"

/*************************************************************
* Returns a direction if the bug can breed a new bug and place
*   it to that direction, which will be empty. Otherwise,
*   if it's full or if bug is not an adult yet, it will
*   return ' '
*************************************************************/
char Critter::breed(Board board)
{
    int boardRow = board.get_num_row(),
        boardCol = board.get_num_col();
    // Direction to breed in, no direction = ' '
    char result = ' ';

    if ((adult_life % life) != 0)
        return result;

    // Checked directions U, R, D, L
    bool checked[4] = { false, false, false, false };
    bool allChecked = false;

    //Check all directions before returning default value
    while (checked[0] == true && checked[1] == true && checked[2] == true && checked[3] == true)
    {
        //Choose random move direction
        int breedDir = Helper::randInt(0, 3);

        //Direction up chosen
        if (breedDir == 0)
        {
            checked[0] = true; //Mark the direction as checked
            int tempRow = row + 1; //Adjust coordinate for new spot
            if (tempRow < boardRow) //Check if coordinate within bounds
            {
                //Check if spot empty
                if (board.get_type(tempRow, col) == "empty")
                {
                    //Set return direction
                    result = 'U';
                    return result;
                }
            }
        }

        //Direction right chosen
        else if (breedDir == 1)
        {
            checked[1] = true;
            int tempCol = col + 1;
            if (tempCol < boardCol)
            {
                if (board.get_type(row, tempCol) == "empty")
                {
                    result = 'R';
                    return result;
                }
            }
        }

        //Direction down chosen
        else if (breedDir == 2)
        {
            checked[2] = true;
            int tempRow = row - 1;
            if (tempRow >= 0)
            {
                if (board.get_type(tempRow, col) == "empty")
                {
                    result = 'D';
                    return result;
                }
            }
        }

        //Direction left chosen
        else if (breedDir == 3)
        {
            checked[3] = true;
            int tempCol = col - 1;
            if (tempCol >= 0)
            {
                if (board.get_type(row, tempCol) == "empty")
                {
                    result = 'L';
                    return result;
                }
            }
        }
    }
    return result;
}


// Returns critter's row as int
int Critter::getRow()
{
    return row;
}

// Returns critter's column as int
int Critter::getCol()
{
    return col;
}

// Sets critter's row to int r
void Critter::setRow(int r)
{
    row = r;
}

// Sets critter's column to int c
void Critter::setCol(int c)
{
    col = c;
}
