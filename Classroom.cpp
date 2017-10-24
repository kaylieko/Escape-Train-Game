/*********************************************************************
** Program Filename: Classroom.cpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / Classroom class implementation
*********************************************************************/

#include "Classroom.hpp"


/*********************************************************
** Function: Constructor
** Description: This function sets preliminary values 
		when the object is created. 
** Parameters: None
********************************************************/

Classroom::Classroom (){
	roomName = "Classroom";
}

/********************************************************
 ** Function: action ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/

void Classroom::action(Player* player){

	Game game;		//create game objectt

	int choice;		//menu choice 
	char tryGame;		//answer for trying a door game	
	char haveId;	
	char useId;

	int gameResult;		//check for win/lose, 1 for win, 2 for lose
	char window;		//answer for breaking a window
	char checkHammer;	//check for hammer
	char useHammer;		//answer for using a hammer
	int itemCheck;		//check if player really has the item to use
	std::string throwItem;  //item to remove

	std::cout << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "		You are in the '" << roomName << "'. " << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << std::endl;

	game.menu();
	std::cin >> choice;
	std::cout << std::endl;
	
	switch (choice){
		case 1:	//front: door, 
			//player can move forward to next section if he wins the door game
			std::cout << "You found the * door *! \n ";
		 	std::cout << "You can go to next section if you win the game against the door. \n";
			std::cout << "Do you want to try? (Y or N): ";
			std::cin >> tryGame;
			std::cout << std::endl;

			if (tryGame == 'Y' || tryGame == 'y'){
				//If the player has an IDcard item,
				//he can skip the door game
				std::cout << "Hint: You can skip the door game if you have an 'IDcard'." << std::endl;
				std::cout << std::endl;				

				player -> showItems();
				std::cout << "Do you have an 'IDcard'? (Y or N): ";
				std::cin >> haveId;
				if (haveId == 'Y'|| haveId == 'y'){
					std::cout << "Do you want to use the 'IDcard'? (Y or N): ";
					std::cin >> useId;
					std::cout << std::endl;
					if (useId == 'Y'|| useId == 'y'){
						itemCheck = player -> useItem("IDcard");
						if (itemCheck == 1){
							std::cout << std::endl;
							player -> setSection(front);
							std::cout << "Now you move forward to < " << player -> getSection()->getRoomName()							      		   			   << " >." << std::endl;
							std::cout << std::endl;
						}
						else if (itemCheck == 2){
							std::cout << std::endl;
							std::cout << "Hey, don't lie... You don't have an 'IDcard' in your bag." << std::endl;
							std::cout << std::endl;
						}
					}
					else {
						std::cout << "Ok, well... let's play the door game then." << std::endl;
						std::cout << std::endl;
						gameResult = game.doorGame();
						if (gameResult == 1){		
							std::cout << std::endl;
							player -> setSection(front);
							std::cout << "Now you move forward to < " << player -> getSection()->getRoomName()							      		  			   << " >." << std::endl;
							std::cout << std::endl;	
						}
						else if (gameResult == 2){
							std::cout << "	Try again next time." << std::endl;
							std::cout << std::endl;				
						}
					}
				}
				else {
					std::cout << "Ok, well... let's play the door game then." << std::endl;
					std::cout << std::endl;
					gameResult = game.doorGame();
					if (gameResult == 1){		
						std::cout << std::endl;
						player -> setSection(front);
						std::cout << "Now you move forward to < " << player -> getSection()->getRoomName()							      		   			   << " >." << std::endl;
						std::cout << std::endl;	
					}
					else if (gameResult == 2){
						std::cout << "	Try again next time." << std::endl;
					}
				}
			}

			else {
				std::cout << "Ok, well... try next time." << std::endl;
			}

			break;		

		case 2:	//back: door to previous room, player moves to Prison
			std::cout << std::endl;		
			player -> setSection(back);
			std::cout << "You see the * door * to Prison."  << std::endl;
			std::cout << "Now you move back to < " 
				  << player -> getSection()->getRoomName()	
				  << " >." << std::endl;
			std::cout << std::endl;
			break;

		case 3:	//left: nothing (wall)
			std::cout << "You see the wall. There's nothing you can do." << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;

			break;


		case 4:	//right:: the player can move directly to Engine (skip the next section;Minister's room)
			//	  through the window using the item 'hammer'
			std::cout << "You see the * window *.\n";
			std::cout << "You can directly go to the < Engine > room from here!\n";
			std::cout << "Do you want to break the window? (Y or N):";
			std::cin >> window;
			std::cout << std::endl;

			if (window == 'Y' || window == 'y'){
				std::cout << "You need a 'hammer' to break the window. " << std::endl;
				std::cout << std::endl;
				player -> showItems();

				std::cout << "Do you have a 'hammer' in your bag? (Y or N) ";	
				std::cin >> checkHammer;
				std::cout << std::endl;				

				if (checkHammer == 'Y'|| checkHammer == 'y'){
					std::cout << "Do you want to use the 'hammer'? (Y or N): ";
					std::cin >> useHammer;

					if (useHammer == 'Y'|| useHammer == 'y'){
						itemCheck = player -> useItem("hammer");
						if (itemCheck == 1){
							player -> setSection(right);
						}
						else if (itemCheck == 2){
							std::cout << std::endl;
							std::cout << "Hey, don't lie... You don't have a 'hammer' in your bag." << std::endl;
							std::cout << std::endl;
						}
					}
					else {
						std::cout << "Ok, well... try next time." << std::endl;				
					}
				}
				
				else {
					std::cout << "Ok, well... You can't break the window then." << std::endl;
					std::cout << "Find a 'hammer' first and try again." << std::endl;
					std::cout << std::endl;				
					
				}
			}

			else {
				std::cout << "Ok, well... try next time." << std::endl;								     			 		 	}
			break;

		case 5:
			player -> showItems();
			break;

		case 6:
			std::cout << "Which item do you want to remove from your bag?: ";
			std::cin >> throwItem;
			player -> removeItem(throwItem);
			std::cout << std::endl;

			break;

		case 7:
			std::cout << getInfo();
			break;

		case 8:		
			std::cout << trainMap();
			break;

		default:
			std::cout << "Invalid input.\n";
			break;
	}
}


/********************************************************
 ** Function: getInfo ()
 ** Description: Display this room information
 ** Parameters: None
 ** Return: returns string type of room info.
 ********************************************************/

std::string Classroom::getInfo(){
	std::string roomInfo;

	roomInfo =  "\n|---------------------{Room Information}----------------------|\n";			
	roomInfo += "|      You traveled through several luxurious cars            |\n";
	roomInfo += "|      and arrive at a < Classroom >,                         |\n";
	roomInfo += "|      where the teacher expounds                             |\n";
	roomInfo += "|      to the children and the rebels                         |\n";
	roomInfo += "|      on the greatness of Wilford and the sacred engine.     |\n";
	roomInfo += "|-------------------------------------------------------------|\n\n";

 	return roomInfo;
}


/********************************************************
 ** Function: trainMap ()
 ** Description: Display map of the train and current room
 ** Parameters: None
 ** Return: returns string type of Train map.
 ********************************************************/

std::string Classroom::trainMap(){
	std::string map;

	map = "\n[Tail Section]--[Guards Area]--[Prison]--[#Classroom#]--[Minister's Room]--[Engine]\n\n";

	return map;
}	
