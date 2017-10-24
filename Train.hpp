/*********************************************************************
** Program Filename: Train.hpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS 162 Final 'Snowpiercer' / Train class declaration
*********************************************************************/
#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "Player.hpp"

class Train {
	protected:
		std::string roomName;
		std::string item;
		Train* front;
		Train* back;
		Train* left;
		Train* right;

		bool stopTrain;
		//Train *section;

	public:
		Train();				/* Default Constructor */
		~Train();				/* Deconstructor */
		virtual void action(Player*) = 0;	/* pure virtual function */
		void setRoomName(std::string);		/* setter for room name */
		std::string getRoomName();		/* getter for room name */

		void setFront(Train*);			/* set pointer for front */
		void setBack(Train*);			/* set pointer for back */
		void setLeft(Train*);			/* set pointer for left */
		void setRight(Train*);			/* set pointer for right */

		Train* getFront();
		Train* getBack();
		Train* getLeft();
		Train* getRight();

		bool getStopTrain();			/* getStopTrain function prototype */
};
#endif	



