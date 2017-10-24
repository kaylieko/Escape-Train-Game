/*********************************************************************
** Program Filename: Timer.cpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS 162 Final 'Snowpiercer' / Timer class implementation
*********************************************************************/


#include "Timer.hpp"

#include <ctime>
#include <iostream>

/********************************************************
 ** Function: Timer
 ** Description: constructor
 ** Parameters: None
 ** Return: None
 ** Description: retrieve the time of the specified System-wide realtime clock 
 ********************************************************/

Timer::Timer(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &beg_); 	
}


/********************************************************
 ** Function: spentTime ()
 ** Description: measuring real time spent for c++03
 ** Parameters: None
 ** Return: None
 ** Reference: http://stackoverflow.com/questions/728068/how-to-calculate-a-time-difference-in-c
 ********************************************************/
double Timer::spentTime(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_);
	return (end_.tv_sec - beg_.tv_sec + (end_.tv_nsec - beg_.tv_nsec) / 10000000.)*60;
}

