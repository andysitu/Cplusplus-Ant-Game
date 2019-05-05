/*************************************************************
* Group # 4
* Program name: Board.cpp
* Date: 5/4/2019
* Description:
*************************************************************/

#include "Board.hpp"

void Board::create_board(int row, int col)
{
    num_col = col;
    num_row = row;
    board = new Critter**[row];
    for (int i = 0; i < row; i++) {
        board[i] = new Critter*[col]{nullptr};
    }
}