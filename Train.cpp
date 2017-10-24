/*********************************************************************
** Program Filename: Train.cpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS 162 Final 'Snowpiercer' / Train class implementation
*********************************************************************/


#include "Train.hpp"

/********************************************************
 ** Function: Train
 ** Description: constructor
 ** Parameters: string tempRoom
 ********************************************************/
Train::Train () {
	roomName = " ";
	item = " ";
	front = NULL;
	back = NULL;
	left = NULL;
	right = NULL;
	stopTrain = false;
}

Train::~Train(){
}

/*********************************************************
** Function: setRoomName
** Description: set the room name 
** Paramaters: string tempName
** Return: None
**********************************************************/
void Train::setRoomName (std::string tempName){
	roomName = tempName;
}


/*********************************************************
** Function: getRoomName
** Description: return the name of the room
** Return: return the name (string type) of the room
**********************************************************/
std::string Train::getRoomName(){
	return roomName;
}


/*********************************************************
** Function: setFront
** Description: set the front side 
** Paramaters: f pointer
** Return: None
**********************************************************/
void Train::setFront(Train* f){
	front = f;
}

/*********************************************************
** Function: setBack
** Description: set the back side 
** Paramaters: b pointer
** Return: None
**********************************************************/
void Train::setBack(Train* b){
	back = b;
}


/*********************************************************
** Function: setLeft
** Description: set the left side 
** Paramaters: l pointer
** Return: None
**********************************************************/
void Train::setLeft(Train* l){
	left = l;
}


/*********************************************************
** Function: setRight
** Description: set the right side 
** Paramaters: r pointer
** Return: None
**********************************************************/
void Train::setRight(Train* r){
	right = r;
}


/*********************************************************
** Function: getFront
** Description: return the front of the room
** Return: return the front side 
**********************************************************/
Train* Train::getFront(){
	return front;
}


/*********************************************************
** Function: getBack
** Description: return the back of the room
** Return: return the back side 
**********************************************************/
Train* Train::getBack(){
	return back;
}


/*********************************************************
** Function: getLeft
** Description: return the left of the room
** Return: return the left side 
**********************************************************/

Train* Train::getLeft(){
	return left;
}


/*********************************************************
** Function: getRight
** Description: return the right of the room
** Return: return the right side 
**********************************************************/
Train* Train::getRight(){
	return right;
}


/*********************************************************
** Function: getStopTrain
** Description: return true for stopping a train
** Return: return true/false
**********************************************************/


bool Train::getStopTrain(){
	if(stopTrain)
		return true;
	else
		return false;
}

