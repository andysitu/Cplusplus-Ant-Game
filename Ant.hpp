/*************************************************************
* Group # 4
* Program name: Ant.hpp
* Date: 5/4/2019
* Description:
*************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant: public Critter
{
public:
    virtual char move(Board b);
};

#endif