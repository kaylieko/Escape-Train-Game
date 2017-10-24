/*********************************************************************
** Program Filename: Prison.hpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / Prison class declaration
*********************************************************************/

#ifndef PRISON_HPP
#define PRISON_HPP

#include "Train.hpp"
#include "Game.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>

class Prison : public Train
{
	public:
		Prison();		/* Default Contructor */
		void action(Player*);	/* action function prototype */
		std::string getInfo();	/* getInfo function prototype */
		std::string trainMap(); /* trainMap function prototype */
};
#endif

