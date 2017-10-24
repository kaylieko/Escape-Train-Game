/*********************************************************************
** Program Filename: GuardsArea.hpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / GuardsArea class declaration
*********************************************************************/

#ifndef GUARDSAREA_HPP
#define GUARDSAREA_HPP

#include "Train.hpp"
#include "Game.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>

class GuardsArea : public Train
{
	public:
		GuardsArea();		/* Default Contructor */
		void action(Player*);	/* action function prototype */
		std::string getInfo();	/* getInfo function prototype */
		std::string trainMap(); /* trainMap function prototype */
};
#endif

