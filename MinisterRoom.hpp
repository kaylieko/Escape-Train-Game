/*********************************************************************
** Program Filename: MinisterRoom.hpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / MinisterRoom class declaration
*********************************************************************/
#ifndef MINISTERROOM_HPP
#define MINISTERROOM_HPP

#include "Train.hpp"
#include "Game.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>

class MinisterRoom : public Train
{
	public:
		MinisterRoom();		/* Default Contructor */
		void action(Player*);	/* action function prototype */
		std::string getInfo();	/* getInfo function prototype */
		std::string trainMap(); /* trainMap function prototype */
};
#endif

