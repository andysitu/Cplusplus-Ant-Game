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
char Doodlebug::check_move(Board board)
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
        if (board.get_type(row, col, 'D').compare("Ant") == 0)
        {
            return 'D';
        }
    }

    else if (tempUp > 0)
    {
        if (board.get_type(row, col, 'U').compare("Ant") == 0)
        {
            return 'U';
        }
    }

    else if (tempRight < boardCol)
    {
        if (board.get_type(row, col, 'R') == "Ant")
        {
            return 'R';
        }
    }

    else if (tempLeft > 0)
    {
        if (board.get_type(row, col, 'L') == "Ant")
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


/*************************************************************
* Moves Doodlebug and checks if the location had an ant.
* If so, it has eaten
*************************************************************/
void Doodlebug::move(int new_row, int new_col, std::string type)
{
    if (type.compare("empty") == 0)
    {
        set_loc(new_row, new_col);
    }
    else if (type.compare("Ant") == 0)
    {
        set_loc(new_row, new_col);
        ate();
    }
}

bool Doodlebug::will_starve()
{
    if (steps_eaten >= 3)
        return true;
    return false;
}