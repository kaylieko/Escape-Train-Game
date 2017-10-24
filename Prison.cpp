/*********************************************************************
** Program Filename: Prison.cpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS162 Final 'Snowpiercer' / Prison class implementation
*********************************************************************/

#include "Prison.hpp"
/*********************************************************
** Function: Constructor
** Description: This function sets preliminary values 
		when the object is created. 
** Parameters: None
********************************************************/

Prison::Prison (){
	roomName = "Prison Section";
	item = "IDcard";
}


/********************************************************
 ** Function: action ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/

void Prison::action(Player* player){

	Game game;

	int bagFull;

	int choice;
	char tryGame;
	int gameResult;
	char pickUp;
	std::string throwItem;

	std::cout << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "		You are in the '" << roomName << "'." << std::endl;
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
					std::cout << "Now you move forward to < " << player -> getSection()->getRoomName()							      		   			   << " >." << std::endl;
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

		case 2: //back: door to previous room, player moves to Guards Area
			std::cout << std::endl;
			player -> setSection(back);
			std::cout << "You see the * door * to Guards Area."  << std::endl;
			std::cout << "Now you move back to < " << player -> getSection()->getRoomName()					 			    		    			   << " >." << std::endl;
			std::cout << std::endl;
			break;

	
		case 3: //left: item 'IDcard' can be found
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

std::string Prison::getInfo(){
	std::string roomInfo;
	
	roomInfo =  "\n|---------------------{Room Information}----------------------|\n";	
	roomInfo += "|	 Overpowering the guards, 	           	      |\n";
	roomInfo += "|	 they release security expert Minsu 	              |\n";
	roomInfo += "|	 and his daughter Yona from the prison car            |\n";
	roomInfo += "| 	 so as to disable the locks between cars.             |\n";
	roomInfo += "|	 They take the car where insects are ground up        |\n";
	roomInfo += "|	 to make their protein bars,		              |\n";
	roomInfo += "|	 and Gilliam suggests that 		              |\n";
	roomInfo += "|	 if they take the subsequent water supply car,        |\n";
	roomInfo += "|	 they will control any negotiation with Wilford.      |\n";
	roomInfo += "|	 Instead, they are ambushed by a mass of masked men   |\n";
	roomInfo += "|	 with hatchets led by Mason.  	                      |\n";
	roomInfo += "|	 After a bloody battle,		                      |\n";
	roomInfo += "|	 Curtis sacrifices his second-in-command Edgar        |\n";
	roomInfo += "|	 to win the fight.              		      |\n";
	roomInfo += "|-------------------------------------------------------------|\n\n";

 	return roomInfo;
}


/********************************************************
 ** Function: trainMap ()
 ** Description: Display map of the train and current room
 ** Parameters: None
 ** Return: returns string type of Train map.
 ********************************************************/


std::string Prison::trainMap(){
	std::string map;

	map = "\n[Tail Section]--[Guards Area]--[#Prison#]--[Classroom]--[Minister's Room]--[Engine]\n\n";

	return map;
}	
