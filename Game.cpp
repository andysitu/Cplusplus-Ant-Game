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

    int num_ants;
    int num_doodlebugs;

    while (!correct_num_bugs) { // Make sure that # bugs does not exceed board
        std::cout << "How many ants would you like?" << std::endl;
        num_ants = Helper::getIntInput(10, 100);

        std::cout << "How many doodlebugs would you like?" << std::endl;
        num_doodlebugs = Helper::getIntInput(10, 100);

        if ((num_doodlebugs * num_ants) <= (row * col)) {
            correct_num_bugs = true;
        }
        else {
            std::cout << "You wanted more bugs than there are board spaces available." << std::endl;
            std::cout << "Please enter the values again." << std::endl;
        }
    }

    // Randomly place bugs until they're completely placed on board
    int ants_placed = 0,
        doodlebugs_placed = 0;

    for (int i = 0; i < num_ants; i++) {
        bool found_empty_spot = false;
        while (!found_empty_spot) {
            int random_row = Helper::randInt(0, row - 1),
                random_col = Helper::randInt(0, col - 1);
            if (board.get_type(random_col, random_col) == "empty") {
                Ant * a = create_ant(random_col, random_col);
                board.add_critter(random_row, random_col, a);
                found_empty_spot = true;
            }
        }
    }

    for (int i = 0; i < num_doodlebugs; i++) {
        bool found_empty_spot = false;
        while (!found_empty_spot) {
            int random_row = Helper::randInt(0, row - 1),
                random_col = Helper::randInt(0, col - 1);
            if (board.get_type(random_col, random_col) == "empty") {
                Doodlebug * d = create_doodlebug(random_col, random_col);
                board.add_critter(random_row, random_col, d);
                found_empty_spot = true;
            }
        }
    }

    board.print_board();
}

Ant * Game::create_ant(int row, int col)
{
   return new Ant( row, col);
}

Doodlebug * Game::create_doodlebug(int row, int col)
{
    return new Doodlebug(row, col);
}