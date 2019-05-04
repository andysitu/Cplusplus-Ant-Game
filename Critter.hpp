/*************************************************************
* Group # 4
* Program name: Critter.hpp
* Date: 5/4/2019
* Description:
*************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <string>
#include "Board.hpp"

class Board;

class Critter
{
private:
    int x;
    int y;
    std::string type_name;
    int life; // num steps it has survived
public:
    Critter();
    virtual char move(Board b) = 0;
    virtual char breed(board b) = 0;
};

#endif