/*********************************************************************
** Program Filename: GuardsArea.cpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / GuardsArea class implementation
*********************************************************************/


#include "GuardsArea.hpp"

/*********************************************************
** Function: Constructor
** Description: This function sets preliminary values 
		when the object is created. 
** Parameters: None
********************************************************/
GuardsArea::GuardsArea(){
	roomName = "Guards Area";
	item = "rope";
}



/********************************************************
 ** Function: action ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/
void GuardsArea::action(Player* player){

	Game game;		//create game object
	
	int bagFull;
	int choice;		//menu choice
	char tryGame;		//answer for trying game
	int gameResult;		//get game result 1 for win, 2 for lose
	
	char pickUp;		//y for picking up the item
	std::string throwItem;	//user input string to remove an item from player's bag

	std::cout << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "		You are in the '" << roomName << "'. "  << std::endl;
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
				gameResult = game.doorGame();
				if (gameResult == 1){
					std::cout << std::endl;					
					player -> setSection(front);
					std::cout << "Now you move forward to < "
	 					  << player -> getSection()->getRoomName()			
				      		  << " >." << std::endl;
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

		case 2:	//back: door to Tail Section, player moves to Tail Section
			std::cout << std::endl;
			player -> setSection(back);
			std::cout << "You see the * door * to Tail Section."  << std::endl;
			std::cout << "Now you move back to < " << player -> getSection()->getRoomName()					 			    		    			   << " >." << std::endl;
			std::cout << std::endl;
			break;

		case 3:	//left: nothing(wall)
			std::cout << "You see the wall. There's nothing you can do." << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;

			break;

		case 4:	//right: item 'rope' can be found
			if (item == ""){
				std::cout << "You already picked up the 'rope'. " << std::endl;
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

std::string GuardsArea::getInfo(){
	std::string roomInfo;

	roomInfo =  "\n|------------------{Room Information}----------------|\n";
	roomInfo += "|	The < Guards Area> includes sections 	     |\n";
	roomInfo += "|	where the protein blocks are made,           |\n";
	roomInfo += "|	as well as the water supply  	             |\n";
	roomInfo += "|	for the tail section of the train.	     |\n";
	roomInfo += "|	There is a large area of this section	     |\n";
	roomInfo += "|	that is completely abandoned. 		     |\n";
	roomInfo += "|----------------------------------------------------|\n\n";

 	return roomInfo;
}

/********************************************************
 ** Function: trainMap ()
 ** Description: Display map of the train and current room
 ** Parameters: None
 ** Return: returns string type of Train map.
 ********************************************************/

std::string GuardsArea::trainMap(){
	std::string map;

	map = "\n[Tail Section]--[#Guards Area#]--[Prison]--[Classroom]--[Minister's Room]--[Engine]\n\n";

	return map;
}	


