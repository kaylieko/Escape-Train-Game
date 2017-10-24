/*********************************************************************
** Program Filename: TailSection.hpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / TailSection class declaration
*********************************************************************/

#ifndef TAILSECTION_HPP
#define TAILSECTION_HPP

#include "Train.hpp"
#include "Game.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>

class TailSection : public Train
{
	public:
		TailSection();		/* Default Constructor */
		void action(Player*);	/* action function prototype */
		std::string getInfo();	/* getInfo function prototype */
		std::string trainMap(); /* trainMap function prototype */
};
#endif

