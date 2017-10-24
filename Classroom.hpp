/*********************************************************************
** Program Filename: Classroom.hpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / Classroom class declaration
*********************************************************************/

#ifndef CLASSROOM_HPP
#define CLASSROM_HPP

#include "Train.hpp"
#include "Game.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>

class Classroom : public Train
{
	public:
		Classroom();		/* Default Contructor */
		void action(Player*);	/* action function prototype */
		std::string getInfo();	/* getInfo function prototype */
		std::string trainMap(); /* trainMap function prototype */
};
#endif

