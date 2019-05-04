/*************************************************************
* Group # 4
* Program name: Board.hpp
* Date: 5/4/2019
* Description:
*************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Critter.hpp"

class Critter;

class Board
{
private:
    Critter *** board = nullptr;
public:
    Board(int y_size, int x_size);
    void print_board();
    int add_critter(int y, int x, Critter *);
    int move_critter(int y, int x, char direction);
    int remove_critter(int y, int x);
};

#endif