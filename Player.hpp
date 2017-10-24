/*********************************************************************
** Program Filename: Player.hpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS 162 Final 'Snowpiercer' / Player class declaration
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Train;

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

class Player
{
	protected:
		std::string name;		/* player name data member */
		int bagSize;			/* Bag size limit */	
		std::vector<std::string> bag;	/* string vector declaration */
		Train *section;			
		std::vector<std::string>::iterator result;	/* iterating over a vector of strings */
	
	public:
		Player(); 			/* default constructor */
		std::string getName();  	/* getName function prototype */

		int addItem(std::string);	/* addItem function prototype */		
		void showItems();		/* showItems function prototype */
		int useItem(std::string);  	/* useItem function prototype */
		void removeItem(std::string);	/* removeItem function prototype */

		void setSection(Train*);
		Train* getSection();	
};
#endif


