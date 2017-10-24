/*********************************************************************
** Program Filename: Engine.hpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / Engine class declaration
*********************************************************************/
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Train.hpp"
#include "Game.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>

class Engine : public Train
{
	public:
		Engine();		/* Default Contructor */
		void action(Player*);	/* action function prototype */
		std::string getInfo();	/* getInfo function prototype */
		std::string trainMap(); /* trainMap function prototype */
};
#endif

