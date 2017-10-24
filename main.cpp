/*********************************************************************
** Program Filename: main.cpp
** Author: Hyejin Ko
** Date: December 6th, 2016
** Description: CS 162 Final 'Snowpiercer' 
** Goal of the game: Find the key and the engine will stop, 
		     which will allow the user to win.
*********************************************************************/


#include "Train.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "TailSection.hpp"
#include "GuardsArea.hpp"
#include "Prison.hpp"
#include "Classroom.hpp"
#include "MinisterRoom.hpp"
#include "Engine.hpp"
#include "Timer.hpp"

#include <ctime>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

 int main()
{
	/* create the player */
	Player *player;
	player = new Player(); 

	/* create each section */
	Train *tailS;
	Train *guards;
	Train *prison;
	Train *classroom;
	Train *minister;
	Train *engine;
	
	tailS = new TailSection(); 
	guards  = new GuardsArea(); 
	prison = new Prison(); 
	classroom = new Classroom();
	minister = new MinisterRoom(); 
	engine = new Engine();     
	
	/* set the pointers for each section
	 so that it points to the correct place */
	tailS -> setFront(guards);
	guards -> setFront(prison);
	guards -> setBack(tailS);
	prison -> setFront(classroom);
	prison -> setBack(guards);
	classroom -> setFront(minister);
	classroom -> setBack(prison);
	classroom -> setRight(engine);
	minister -> setFront(engine);
	minister -> setBack(classroom);
	engine -> setBack(minister);
	engine -> setRight(classroom);

	/* set the player's starting location
	   in Tail Section */
	Train *location; 
	player->setSection(tailS);
	

	/* create timer object */
	Timer tmr;	
	
	int choice;	//menu choice


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "+++++++++++++++++++ GAME MENU ++++++++++++++++++" << std::endl; 
	std::cout << "|		   1. New Game                 |"<< std::endl; 
 	std::cout << "|		   2. Quit  		       |"<< std::endl; 
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
 	std::cout << "What do you want to do: "; 
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) 
	{ 
		case 1: 
					
			std::cout << "< Welcome to the Snow Piercer! >" << std::endl;
                        std::cout << "Set in a future where a failed climate-change experiment kills \n";
			std::cout << "all life on the planet except for a lucky few,including yourself, \n";
			std::cout << "who boarded the Snowpiercer, a train that travels around the globe,\n";
			std::cout << "where a class system emerges. \n";
			std::cout << "You, Curtis Everett, a member of the lower-class tail section passengers \n";
			std::cout << "as they lead a revolution against the elite of the front of the train.\n\n";

			/* goal of the game */
			std::cout << "You plan to stop the train as you observed signs the world outside is thawing.\n";
			std::cout << "You need to find the special item first to stop the train.\n";
			std::cout << "You have [300 sec.(5min.)] to stop the train.\n\n";

			std::cout << "Let's begin the story. Good luck! \n\n";
			
			/* sets and starts the timer */
			double t;
			double sum;
			sum = 0;
			t = tmr.spentTime();
				
			/* This while loop prompts the user to move around the train for 180 sec.*/
			while((player->getSection() != NULL) && sum < 300.0){
				
       				location = player -> getSection();
				location -> action(player); 
		
				/* check if the user stopped the engine */
				if (location -> getStopTrain()) {
					std::cout << std::endl;
					std::cout << ":) Yay! You stopped the train, Great job Curtis!!" << std::endl;
					std::cout << std::fixed;
					std::cout << "(You spent ["<< std::setprecision(2) <<  sum << " seconds])" << std::endl;
					std::cout << "\n	   		-- Victory --" << std::endl;
					std::cout << std::endl;
					break;
				}
				
				/* spent time calculate */
				t = tmr.spentTime();
				sum += t;
			}

			/* game over if the player spends more than 100sec. */					
			if (sum > 300.0){
				std::cout << std::endl;
				std::cout << ":( Oops! Failed. Ran out of Time...." << std::endl;
				std::cout << "(You spent more than 300 seconds on the Train) " << std::endl;

				std::cout <<"\n	  	  	-- Game Over --" << std::endl;
				std::cout << std::endl;
			}

			break;

		
		case 2: 
			std::cout << "Bye Bye!" << std::endl; 
			break;
	}

	delete player;
	delete tailS;
	delete guards;
	delete prison;
	delete classroom;
	delete minister;
	delete engine;

	return 0;
}

