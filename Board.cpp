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

void Board::print_board()
{
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            std::string type = get_type(i, j);
            if (type == "Ant")
                std::cout << "O";
            else if (type == "Doodlebug")
                std::cout << "X";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

std::string Board::get_type(int row, int col)
{
    Critter * piece = board[row][col];
    if (!piece) { // nullptr / Empty piece
        return "empty";
    }
    else {
        return piece->get_type();
    }
}