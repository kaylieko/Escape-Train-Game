/*********************************************************************
** Program Filename: Timer.hpp
** Author:Hyejin Ko
** Date: December 6th, 2016
** Description: CS 162 Final 'Snowpiercer' / Timer class declaration
*********************************************************************/


#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream>
#include <ctime>

class Timer
{
	public:
		Timer();		/* default constructor */
		double spentTime();	/* spentTime function prototype */

	private:
		timespec beg_, end_;
};
#endif
