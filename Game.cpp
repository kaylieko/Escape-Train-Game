/*********************************************************************
** Program Filename: Game.cpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS 162 Final 'Snowpiercer' / Game class implementation
*********************************************************************/

#include "Game.hpp"


/********************************************************
 ** Function: menu
 ** Description: display menu in each room
 ** Parameters: None
 ** Return: None
********************************************************/

void Game::menu(){
	std::cout << "---------------------{ Action Menu }-----------------------" << std::endl;
	std::cout << "		1. Walk to the front." << std::endl;
	std::cout << "		2. Walk to the back." << std::endl;
	std::cout << "		3. Walk to the left." << std::endl;
	std::cout << "		4. Walk to the right." << std::endl;
	std::cout << "		5. Check item(s) in your backpack." << std::endl;
	std::cout << "		6. Remove an item from your backpack." << std::endl;	
	std::cout << "		7. Get the room information." << std::endl;
	std::cout << "		8. View the map of Snowpiercer." << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "		Your choice: " ;
}



/********************************************************
 ** Function: doorGame
 ** Description: Rock-Paper-Scissors Game 
		 for GuardsArea, Prison, Classroom, MinisterRoom
 ** Parameters: None
 ** Return: result of the game (int type)
	    1 for win, 2 for lose
 ********************************************************/

int Game::doorGame(){

   	srand(time(NULL));
	int input;
        int computer = (rand() % 3) + 1;	// 1 for rock, 2 for paper, 3 for scissors
	
	do {
		std::cout << "** Let's play Rock-Paper-Scissors **" << std::endl ;
		std::cout << "1) Rock" << std::endl;
		std::cout << "2) Paper" << std::endl;
		std::cout << "3) Scissors"<< std::endl;
		std::cout << "4) Quit" << std::endl;
		std::cout << "Enter your choice: " ;
        	std::cin >> input; 
 		std::cout << std::endl;

        	if((computer == 1) && (input == 1)){
	
			std::cout << "	(You)Rock vs. (Door)Rock" << std::endl;
			std::cout << "	     Draw! Let's play again." << std::endl;
			std::cout << std::endl;
			continue;	
        	}

	
        	else if((computer == 2) && (input == 2)){
	
			std::cout << "	(You)Paper vs. (Door)Paper" << std::endl;
			std::cout << "	     Draw! Let's play again." << std::endl;
			std::cout << std::endl;
			continue;	
        	}

	
        	else if((computer == 3) && (input == 3)){
	
			std::cout << "	(You)Scissors vs. (Door)Scissors" << std::endl;
			std::cout << "	     Draw! Let's play again." << std::endl;
			std::cout << std::endl;
			continue;	 
        	}


      		else if((computer == 1) && (input == 2)){
			std::cout << "	(You)Paper vs. (Door)Rock" << std::endl;	
			std::cout << "		You won!" << std::endl;
			return 1;
        	}

        	else if((computer == 1) && (input == 3)){
			std::cout << "	(You)Scissors vs. (Door)Rock" << std::endl;	
			std::cout << "		You lost!" << std::endl;
			return 2;
        	}

        	else if((computer == 2) && (input == 3)){
			std::cout << "	(You)Scissors vs. (Door)Paper" << std::endl;	
			std::cout << "		You won!" << std::endl;
			return 1;
        	}

        	else if((computer == 2) && (input == 1)){
			std::cout << "	(You)Rock vs. (Door)Paper" << std::endl;	
			std::cout << "		You lost!" << std::endl;
			return 2;
        	}

        	else if((computer == 3) && (input == 1)){
			std::cout << "	(You)Rock vs. (Door)Scissors" << std::endl;	
			std::cout << "		You won!" << std::endl;
     			return 1;
        	}

        	else if((computer == 3) && (input == 2)){
			std::cout << "	(You)Paper vs. (Door)Scissors" << std::endl;	
			std::cout << "		You lost!" << std::endl;
			return 2;
        	}
	}while(input != 4);
	
}

