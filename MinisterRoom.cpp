/*********************************************************************
** Program Filename: MinisterRoom.cpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / MinisterRoom class implementation
*********************************************************************/


#include "MinisterRoom.hpp"


/*********************************************************
** Function: Constructor
** Description: This function sets preliminary values 
		when the object is created. 
** Parameters: None
********************************************************/

MinisterRoom::MinisterRoom (){
	roomName = "Minister’s Room";
	item = "key";
}


/********************************************************
 ** Function: action ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/

void MinisterRoom::action(Player* player){

	Game game;		//create game object
	
	int bagFull;		//check if the bag is full
	int choice;		//menu choice 
	char tryGame;		//answer for trying a door game		
	int gameResult;		//check for win/lose, 1 for win, 2 for lose
	char pickUp;		//answer for picking up item
	std::string throwItem;  //item to remove

	std::cout << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "		You are in the '" << roomName << "'." << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << std::endl;

	game.menu();		//call the menu function
	std::cin >> choice;
	std::cout << std::endl;


	switch (choice){
		case 1:	//front: door, 
			//player can move forward to next section if he wins the door game

			std::cout << "You found the * door * , and Minister Mason is there! \n ";
			std::cout << "You can go to the Engine if you win against Mason. \n"; 
			std::cout << "Do you want to try? (Y or N): ";
			std::cin >> tryGame;
			std::cout << std::endl;

			if (tryGame == 'Y' || tryGame == 'y'){
				gameResult = game.doorGame();
				if (gameResult == 1){		
					std::cout << std::endl;
					player -> setSection(front);
					std::cout << "Now you move forward to < " << player -> getSection()->getRoomName()							      		    			   << " >." << std::endl;
					std::cout << std::endl;
				}
				else if (gameResult == 2){
					std::cout << "	Try again next time." << std::endl;
					std::cout << std::endl;				
				}
			}
			else {
				std::cout << "Ok, well... try next time." << std::endl;
			}
			break;

		case 2:	//back: door to previous room, player moves to Classroom
			std::cout << std::endl;		
			player -> setSection(back);
			std::cout << "You see the * door * to Classroom."  << std::endl;
			std::cout << "Now you move back to < " 
			          << player -> getSection()->getRoomName()	
				  << " >." << std::endl;
			std::cout << std::endl;
			
			break;

		case 3:	//left: item 'key' can be found
			if (item == ""){
				std::cout << "You already picked up the 'IDcard'. " << std::endl;
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


		case 4:	//right: nothing(wall)
			std::cout << "You see the wall. There's nothing you can do." << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;

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
	
std::string MinisterRoom::getInfo(){
	std::string roomInfo;

	roomInfo =  "\n|---------------------{Room Information}----------------------|\n";				
	roomInfo += "|      At the front of the train, the survivors live well,    |\n"; 
	roomInfo += "|      with an aquarium, a sauna, party rooms and             |\n";
	roomInfo += "|      a swimming pool room that takes up an entire care.     |\n";
	roomInfo += "|                                                             |\n";
	roomInfo += "|      At the gate to the engine,                             |\n";
	roomInfo += "|      You finally meet Minister Mason                        |\n"; 
	roomInfo += "|      the second in command of the train                     |\n";
	roomInfo += "|      She may hide something special in her room.            |\n";
	roomInfo += "|-------------------------------------------------------------|\n\n";
	
 	return roomInfo;
}

/********************************************************
 ** Function: trainMap ()
 ** Description: Display map of the train and current room
 ** Parameters: None
 ** Return: returns string type of Train map.
 ********************************************************/

std::string MinisterRoom::trainMap(){
	std::string map;

	map = "\n[Tail Section]--[Guards Area]--[Prison]--[Classroom]--[#Minister's Room#]--[Engine]\n\n";

	return map;
}	
