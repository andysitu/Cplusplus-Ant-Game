/*************************************************************
* Group # 4
* Program name: Board.hpp
* Date: 5/4/2019
* Description:
*************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Critter.hpp"
#include <string>

class Critter;

class Board
{
private:
    Critter *** board = nullptr;
    int num_row;
    int num_col;
public:
    void print_board();
    int add_critter(int y, int x, Critter *);
    int move_critter(int y, int x, char direction);
    int remove_critter(int y, int x);

    bool out_of_bounds(int row, int col, char direction);
    std::string get_type(int row, int col);

    void create_board(int y, int x);
};

#endif