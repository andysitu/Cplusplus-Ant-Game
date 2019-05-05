/*************************************************************
* Group # 4
* Program name: Board.cpp
* Date: 5/4/2019
* Description:
*************************************************************/

#include "Board.hpp"

void Board::create_board(int y, int x)
{
    board = new Critter**[y];
    for (int i = 0; i < y; i++) {
        board[i] = new Critter*[x] {nullptr};
    }
}