/*************************************************************
* Group # 4
* Program name: Doodlebug.hpp
* Date: 5/4/2019
* Description:
*************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug: public Critter
{
private:
    int steps_eaten = 0;
public:
    bool will_starve(); // checks if DoodleBug will starve, returns true if so
    virtual char move(Board b);
};

#endif