/* timemod.cpp
 * converts between time units*/

// Definitions


//Headers
#include "timemod.h"
#include <iostream>

using namespace std;



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
