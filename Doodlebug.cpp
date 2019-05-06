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


    //Checks for ants
    if (!board.out_of_bounds(row, col, 'D'))
        if (board.get_type(row, col, 'D').compare("Ant") == 0)
        {
            std::cout << "ANT";
            return 'D';
        }
    if (!board.out_of_bounds(row, col, 'U'))
        if (board.get_type(row, col, 'U').compare("Ant") == 0)
        {
            std::cout << "ANT";
            return 'U';
        }
    if (!board.out_of_bounds(row, col, 'R'))
        if (board.get_type(row, col, 'R').compare("Ant") == 0)
        {
            std::cout << "ANT";
            return 'R';
        }
    if (!board.out_of_bounds(row, col, 'L'))
        if (board.get_type(row, col, 'L').compare("Ant") == 0)
        {
            std::cout << "ANT";
            return 'L';
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
void Doodlebug::move(int new_row, int new_col, std::string prev_cell_type)
{
    if (prev_cell_type.compare("empty") == 0)
    {
        set_loc(new_row, new_col);
    }
    else if (prev_cell_type.compare("Ant") == 0)
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