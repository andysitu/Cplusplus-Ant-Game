/*************************************************************
* Group # 4
* Program name: Game.cpp
* Date: 5/4/2019
* Description:
*************************************************************/

#include "Game.hpp"

/*************************************************************
* 
*************************************************************/
Game::Game()
{
    Helper::set_srand();
    start_game();
}


/*************************************************************
* Starts the game itself, asking user for board size
* and # critters and then complets the game
*************************************************************/
void Game::start_game()
{
    std::cout << "CS 162 Group Project" << std::endl;
    std::cout << "What size board would you like?" << std::endl;
    std::cout << "Please enter an integer for row size." << std::endl;

    int row = Helper::getIntInput(10, 100);

    std::cout << "Please enter an integer for col size." << std::endl;
    int col = Helper::getIntInput(10, 100);

    board.create_board(row, col);

    bool correct_num_bugs = false;
    int ants_input;
    int doodlebugs_input;

    while (!correct_num_bugs) { // Make sure that # bugs does not exceed board
        std::cout << "How many ants would you like?" << std::endl;
        ants_input = Helper::getIntInput(10, 100);

        std::cout << "How many doodlebugs would you like?" << std::endl;
        doodlebugs_input = Helper::getIntInput(10, 100);

        if ((doodlebugs_input * ants_input) <= (row * col)) {
            correct_num_bugs = true;
        }
        else {
            std::cout << "You wanted more bugs than there are board spaces available." << std::endl;
            std::cout << "Please enter the values again." << std::endl;
        }
    }

    ants_array_size = ants_input * 2;
    doodlebug_array_size = doodlebugs_input * 2;

    ants = new Ant*[ants_array_size];
    doodlebugs = new Doodlebug*[doodlebug_array_size];

    for (int i = 0; i < ants_input; i++) {
        bool found_empty_spot = false;
        while (!found_empty_spot) {
            int random_row = Helper::randInt(0, row - 1),
                random_col = Helper::randInt(0, col - 1);
            if (board.get_type(random_row, random_col) == "empty") {
                create_ant(random_row, random_col);
                found_empty_spot = true;
            }
        }
    }
    
    for (int i = 0; i < doodlebugs_input; i++) {
        bool found_empty_spot = false;
        while (!found_empty_spot) {
            int random_row = Helper::randInt(0, row - 1),
                random_col = Helper::randInt(0, col - 1);
            if (board.get_type(random_row, random_col) == "empty") {
                create_doodlebug(random_row, random_col);
                found_empty_spot = true;
            }
        }
    }

    board.print_board();
}

void Game::create_ant(int row, int col)
{
    Ant * a =  new Ant( row, col);
    board.add_critter(row, col, a);

    num_ants++;

    if (num_ants > ants_array_size) {
        int old_arr_size = ants_array_size;
        ants_array_size = num_ants * 2;
        Ant ** new_ants = new Ant*[ants_array_size];
        for (int i = 0; i < old_arr_size; i++) {
            new_ants[i] = ants[i];
        }
        delete[] ants;
        ants = nullptr;

        ants = new_ants;
    }
    ants[num_ants] = a;
}

void Game::create_doodlebug(int row, int col)
{
    Doodlebug * d = new Doodlebug(row, col);
    board.add_critter(row, col, d);

    num_doodlebugs++;

    if (num_doodlebugs > doodlebug_array_size) {
        int old_arr_size = doodlebug_array_size;
        doodlebug_array_size = num_doodlebugs * 2;
        Doodlebug ** new_doodlebugs = new Doodlebug*[doodlebug_array_size];
        for (int i = 0; i < old_arr_size; i++) {
            new_doodlebugs[i] = doodlebugs[i];
        }
        delete[] doodlebugs;
        doodlebugs = nullptr;

        doodlebugs = new_doodlebugs;
    }
    doodlebugs[num_doodlebugs] = d;
}