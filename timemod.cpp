/* timemod.cpp
 * converts between time units*/

// Definitions


//Headers
#include "timemod.h"
#include <iostream>

using namespace std;

// Default constructor
timestore::timestore()
{
	return;
}

timestore::~timestore()
{
	return;
}

// Parameterized constructors

// Each element specified in parameter
timestore::timestore(unsigned int hr, unsigned int min, unsigned int sec)
{
	Hour = hr + (min / 60) + sectohr(sec);
	Minute = (min % 60) + remmin(sec);
	Second = remsec(sec);
	return;
}

// Elements calculated from seconds in parameter
timestore::timestore(unsigned int sec)
{
	Hour = sectohr(sec);
	Minute = remmin(sec);
	Second = remsec(sec);
	return;
}

void timestore::setHour(unsigned int hr)
{
	Hour = hr;
	return;
}

unsigned int timestore::getHour()
{
	return(Hour);
}

void timestore::setMinute(unsigned int min)
{
	Minute = min;
	return;
}

unsigned int timestore::getMinute()
{
	return(Minute);
}

void timestore::setSecond(unsigned int sec)
{
	Second = sec;
	return;
}

unsigned int timestore::getSecond()
{
	return(Second);
}



unsigned int sectohr(unsigned int seconds)
{
	return (seconds / 3600);
}

unsigned int remmin(unsigned int seconds)
{
	return ((seconds % 3600) / 60);
}

unsigned int remsec(unsigned int seconds)
{
	return (seconds % 60);
}
