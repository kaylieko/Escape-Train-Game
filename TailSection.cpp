/*********************************************************************
** Program Filename: TailSection.cpp
** Author: Hyejin Ko
** Date: December 6th, 2016
** Description: CS 162 Final 'Snowpiercer' / TailSection class implementation
*********************************************************************/

#include "TailSection.hpp"

/*********************************************************
** Function: Constructor
** Description: This function sets preliminary values 
		when the object is created. 
** Parameters: None
********************************************************/

TailSection::TailSection() {
	roomName = "Tail Section";
	item = "hammer";
}


/********************************************************
 ** Function: action ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/
void TailSection::action(Player* player){

	Game game;		//create game object

	int bagFull;
	int choice;		//menu choice variable
	char pickUp;		//answer for picking up item
	std::string throwItem;

	std::cout << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "	 	You are in the '" << roomName << "'. " << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << std::endl;
	
	game.menu();	
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice){
		case 1:	//front: door, player can move forward to next section
			std::cout << std::endl;
			std::cout << "You found the * door *. "<< std::endl;
			player -> setSection(front);
								
			std::cout << "Now you move forward to < " << player -> getSection()->getRoomName()
				  << " >." << std::endl;
			std::cout << std::endl;	
			break;
	
		case 2:	//back: nothing (wall)
			std::cout << "You see the wall. There's nothing you can do." << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			

			break;

		case 3:	//left: item 'hammer' could be found
			if (item == ""){
				std::cout << "You already picked up the 'hammer'. " << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;				
			}
			else {

				std::cout << "You found the '"<< item << "'. Do you want to pick it up? (Y or N): ";
				std::cin >> pickUp;
			
				if (pickUp == 'Y' || pickUp == 'y'){

					bagFull = player->addItem(item);		//call addItem function
					
					if (bagFull == -1){
						std::cout << "--> You couldn't pick up the '" << item  <<"'."<< std::endl;
						std::cout << std::endl;
					}

					else if (bagFull == -2){
						item.clear();			//remove the item from this room
						std::cout << std::endl;
					}
				}

				else {
					std::cout << "--> You didn't pick up the '" << item  <<"'."<< std::endl;
				}
			}
			break;
					
		case 4:	//right: nothing (wall)
			std::cout << "You see the wall. There's nothing you can do."  << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;

			break;

		case 5:	//call the showItem function
			player -> showItems();
			break;

		case 6:	//call the removeItem function
			std::cout << "Which item do you want to remove from your bag?: ";
			std::cin >> throwItem;
			player -> removeItem(throwItem);
			std::cout << std::endl;
			break;

		case 7:	//call the getInfo function
			std::cout << getInfo();
			break;

		case 8:	//call the trainMap function	
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
std::string TailSection::getInfo(){
	std::string roomInfo;
	
	roomInfo =  "\n|--------------------{Room Information}---------------------|\n";	
	roomInfo += "|   In the < Tail section >,                                |\n"; 
	roomInfo += "|   the food are protein blocks, the composition of         |\n"; 
	roomInfo += "|   which is unknown to those who have to eat them.         |\n";
	roomInfo += "|   Children are taken from the tail section                |\n";
	roomInfo += "|   and brought to the front, never to be seen again.       |\n";
	roomInfo += "|   Punishment involves having an arm stuck outside         |\n";
	roomInfo += "|   completely frozen, and then shattered with a hammer.    |\n";
	roomInfo += "|   Conspiring with your mentor Gilliam,                    |\n";
	roomInfo += "|   you,Curtis Everett,lead the tail passengers             |\n"; 
	roomInfo += "|   in a revolt that your plans will take them              |\n";
	roomInfo += "|   all the way up to the engine.                           |\n";
	roomInfo += "|   Now, let's get out of this section first!               |\n";
	roomInfo += "|-----------------------------------------------------------|\n\n";
	
	return roomInfo;
}

/********************************************************
 ** Function: trainMap ()
 ** Description: Display map of the train and current room
 ** Parameters: None
 ** Return: returns string type of Train map.
 ********************************************************/
std::string TailSection::trainMap(){
	std::string map;

	map = "\n[#Tail Section#]--[Guards Area]--[Prison]--[Classroom]--[Minister's Room]--[Engine]\n\n";

	return map;
}	
