/*********************************************************************
** Program Filename: Engine.cpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / Engine class implementation
*********************************************************************/

#include "Engine.hpp"


/*********************************************************
** Function: Constructor
** Description: This function sets preliminary values 
		when the object is created. 
** Parameters: None
********************************************************/


Engine::Engine (){
	roomName = "Engine";
}


/********************************************************
 ** Function: action ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/

void Engine::action(Player* player){

	Game game;		//create game object
	
	int choice;		//menu choice variable
	
	char key;		//answer for having a key or not
	char useKey;		//answer for if the user use a key or not
	char window;		//answer for using a window
	char haveRope;		//check for having a rope or not
	char useRope;		//answer for using a rope or not
	int itemCheck;		//check if player really has the item to use
	std::string throwItem;	//item to remove

	std::cout << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "		You are in the '" << roomName << "'." << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << std::endl;

	game.menu();
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice){
		case 1:	//front: the player can stop the train (win the game)
			//	 if he has/uses a key
			std::cout << std::endl;
			std::cout << "You found the * engine *! \n\n";
			std::cout << "You need a 'key' to stop the train. \n";
			std::cout << std::endl;
			
			player->showItems();
			std::cout << "Do you have a 'key'? (Y or N): ";
			std::cin >> key;

			if (key == 'Y' || key == 'y'){
				std::cout << "Do you want to use a 'key'? (Y or N): ";
				std::cin >> useKey;
				if (useKey == 'Y' || useKey == 'y'){
					itemCheck = player -> useItem("key");
					//if he has/uses a key the game ends
					if (itemCheck == 1){
						stopTrain = true;
					}
					else if (itemCheck == 2){
						std::cout << std::endl;
						std::cout << "Hey, don't lie... You don't have a 'key' in your bag." << std::endl;
						std::cout << std::endl;
					}
				}
				else {
					std::cout << "Ok, well... try next time." << std::endl;
				}
			}	
			else {
				std::cout << "You need to find a 'key', hurry up! \n";
			}
			break;		

		case 2: //back: door to previous room, player moves to Minister's room
			std::cout << std::endl;		
			player -> setSection(back);
			std::cout << "You see the * door * to Minister Mason's Room."  << std::endl;
			std::cout << "Now you move back to < " << player -> getSection()->getRoomName()					 			    		   			   << " >." << std::endl;
			std::cout << std::endl;
			

			break;

	
		case 3:	//left: nothing(wall)
			std::cout << "You see the wall. There's nothing you can do." << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;

			break;
	
		case 4:	//right:: the player can move directly to Classroom (skip the next section;Minister's room)
			//	  through the window using the item 'rope'
			std::cout << std::endl;			
			std::cout << "You see the * window *. \n";
			std::cout << "Do you want to go back to the < Classroom >? (Y or N):";
			std::cin >> window;
			std::cout << std::endl;

			if (window == 'Y' || window == 'y'){
				std::cout << "You need a 'rope' to accross window. " << std::endl;
				std::cout << std::endl;
				player -> showItems();
				std::cout << "Do you have a 'rope' in your bag? (Y or N) ";	
				std::cin >> haveRope;
				std::cout << std::endl;

				if (haveRope == 'Y'|| haveRope == 'y'){
					std::cout << "Do you want to use the 'rope'? (Y or N): ";
					std::cin >> useRope;
					if (useRope == 'Y'|| useRope == 'y'){
						itemCheck = player -> useItem("rope");
						if (itemCheck == 1){
							std::cout << std::endl;		
							player -> setSection(right);
							std::cout << "Now you move to < " 
								  << player -> getSection()->getRoomName()
					 			  << " >." << std::endl;
						}
						else if (itemCheck == 2){
							std::cout << std::endl;
							std::cout << "Hey, don't lie... You don't have a 'rope' in your bag." << std::endl;
							std::cout << std::endl;
						}
					}

					else {
						std::cout << "Ok, well... try next time." << std::endl;
						std::cout << std::endl;
						
					}
				}
				else {
					std::cout << "Ok, well... find a 'rope' or try next time." << std::endl;
					std::cout << std::endl;
				}
			}		
			else {
				std::cout << "Ok, well... try next time." << std::endl;	
				std::cout << std::endl;
											     			 						}
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
			std::cout << std::endl;
			
			break;
	}

}


/********************************************************
 ** Function: getInfo ()
 ** Description: Display this room information
 ** Parameters: None
 ** Return: returns string type of room info.
 ********************************************************/

std::string Engine::getInfo(){
	std::string roomInfo;

	roomInfo =  "\n|---------------------{Room Information}----------------------|\n";			
 	roomInfo += "|     You are walking through a narrow walkway,               |\n"; 
	roomInfo += "|     on either side of which are a lot of blinking machines  |\n"; 
	roomInfo += "|     behind glass windows                                    |\n"; 
	roomInfo += "|     with a bolted door that serves as an exit.              |\n";
	roomInfo += "|     This room is the sanctum sanctorum of the train.        |\n";
	roomInfo += "|                                                             |\n";
	roomInfo += "|     You don't have much time left,                          |\n";
	roomInfo += "|     hurry up to stop the train!                             |\n";
	roomInfo += "|     You will need a special item to stop the train though...|\n";
	roomInfo += "|-------------------------------------------------------------|\n\n";


	return roomInfo;
}

/********************************************************
 ** Function: trainMap ()
 ** Description: Display map of the train and current room
 ** Parameters: None
 ** Return: returns string type of Train map.
 ********************************************************/

std::string Engine::trainMap(){
	std::string map;

	map = "\n[Tail Section]--[Guards Area]--[Prison]--[Classroom]--[Minister's Room]--[#Engine#]\n\n";

	return map;
}	
