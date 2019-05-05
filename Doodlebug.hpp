/*************************************************************
* Group # 4
* Program name: Doodlebug.hpp
* Date: 5/4/2019
* Description:
*************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"
#include "Helper.hpp"
#include "Board.hpp"

class Doodlebug: public Critter
{
private:
    int steps_eaten = 0;
public:
    Doodlebug(int r, int c);
    bool will_starve(); // checks if DoodleBug will starve, returns true if so
    virtual char move(Board);
};

#endif