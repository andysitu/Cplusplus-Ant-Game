/*************************************************************
* Group # 4
* Program name: Game.hpp
* Date: 5/4/2019
* Description:
*************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

#include "Helper.hpp"

class Game
{
private:
    Board board;
    void create_board(int y, int x);
    void run_step();
    void run_steps(int num_steps);

    // Array of ant pointers
    Ant ** ants;
    Doodlebug ** doodlebugs;

    Ant * create_ant(int y, int x);
    Doodlebug * create_doodlebug(int y, int x);

    void remove_ant(int y, int x);
    void start_game();
public:
    Game();
};

#endif