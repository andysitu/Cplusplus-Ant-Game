/*************************************************************
*  Author: David Martinez, Andy Situ
*  Date: 5/4/19
*  Description: This is the header file for the critter base class for CS162's group project.
*  This file lists the member variables and function prototypes for used for the predator-prey
*  game.
*************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <string>
#include "Board.hpp"
#include "Helper.hpp"

class Board;

class Critter
{
protected:
    int adult_life; // Num steps required to be an adult;
    int row;
    int col;
    std::string type_name;
    int life; // num steps it has survived
public:
    virtual char move(Board b) = 0;
    virtual char breed(Board b);

    std::string get_type() { return type_name; }

    int getRow();                 // Returns critter's row as int
    int getCol();                 // Returns critter's column as int
    void setRow(int);                  // Sets critter's row to int
    void setCol(int);                  // Sets critter's column to int

    void age() { life++; } // Increase life by 1
};

#endif