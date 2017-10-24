/*********************************************************************
** Program Filename: Player.cpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS 162 Final 'Snowpiercer' / Player class implementation
*********************************************************************/

#include "Player.hpp"

/********************************************************
 ** Function: Player
 ** Description: constructor
 ** Parameters: None
 ** Return: None
 ********************************************************/

Player::Player(){
	name = "Curtis";
	bagSize = 2;
	section = NULL;
}


/********************************************************
 ** Function: setLocation ()
 ** Description: sets the location
 ** Parameters: Train address
 ********************************************************/

void Player::setSection(Train* train){
	section = train;
}



/********************************************************
 ** Function: getLocation ()
 ** Description: returns the location of the player
 ** Parameters: None
 ********************************************************/
Train* Player::getSection(){
	return section;
}


/********************************************************
 ** Function: getName ()
 ** Description: returns the name of the player
 ** Parameters: None
 ********************************************************/

std::string Player::getName(){
	return name;
}

/********************************************************
 ** Function: addItem () 
 ** Description: adds item to player's bag
 ** Parameters: string anItem(item name)
 ** Return: -1 for bag full, -2 for not full
 ********************************************************/
int Player::addItem (std::string anItem){
	if (bag.size() == bagSize){
		std::cout << "(Backpack is full.)" << std::endl;
		return -1;
	}
	else if (bag.size() < bagSize){
		bag.push_back(anItem);
		std::cout << "You put the '" << anItem << "' in your bag." << std::endl;
		std::cout << "(Now, you have " << bag.size() << " item(s) in your bag.)" << std::endl;	
		return -2;
	}
}

/********************************************************
 ** Function: showItem ()
 ** Description: Display items in player's bag
 ** Parameters: None
 ********************************************************/
void Player::showItems(){
	if (bag.empty()){
		std::cout << "(Your bag is empty.)" << std::endl;
	}
	else {
		std::cout << "(You have " ;
		for (int i = 0; i < bag.size(); i++){
			std::cout << "[" << bag.at(i) << "] " ;
		}
		std::cout << "in your bag.)";
		std::cout << std::endl;
		std::cout << std::endl;	
	}
}

/********************************************************
 ** Function: useItem ()
 ** Description: find an item and erase the item for using
 ** Parameters: string tempItem (item name)
 ** return 1 for found&used item, 2 for empty or not found
 ********************************************************/
int Player::useItem(std::string tempItem){
	if (bag.empty()){
		std::cout << "(Your bag is empty.)" << std::endl;
		return 2;
	}

	//http://www.cplusplus.com/reference/algorithm/find
	//find function: Returns an iterator to the begin element in the range [begin, end)
	//that compares equal to val. If no such element is found, the function returns end.
	else {
    		result = find(bag.begin(), bag.end(), tempItem);
		if (result == bag.end()){
			return 2;
		}
		else {
			std::cout << std::endl;		
			std::cout << "(You found the '" << tempItem << "' in the your bag.)" << std::endl;
			std::cout << "*** The item '" << tempItem << "' has been used. ***" << std::endl;
			bag.erase(result);
			std::cout << std::endl;	
			
			return 1;
		}
    	}
}

/********************************************************
 ** Function: removeItem ()
 ** Description: removes an item from player's bag
 ** Parameters: string rItem
 ********************************************************/
void Player::removeItem(std::string rItem){
	if (bag.empty()){
		std::cout << "(Your bag is empty. Nothing to throw away.)" << std::endl;
	}

	//http://www.cplusplus.com/reference/algorithm/find
	//find function: Returns an iterator to the begin element in the range [begin, end)
	//that compares equal to val. If no such element is found, the function returns end.
	else {
    		result = find(bag.begin(), bag.end(), rItem);
		if (result == bag.end()){
			std::cout << "(Couldn't find the item '"<< rItem << "' in your bag.)" << std::endl;
		}
		else {
			std::cout << "(You found the '" << rItem << "' in the your bag.)" << std::endl;
			std::cout << "*** You threw away the '" << rItem << "' from your bag. ***" << std::endl;
			bag.erase(result);
			std::cout << std::endl;	
		}
	}
}
