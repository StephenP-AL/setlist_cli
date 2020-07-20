/* Catalog.cpp
 *
 */
// Definitions
// #define DEBUG

// Headers
#include "catalog.h"
#include "song.h"
#include <vector>
#include <algorithm>
#include <random>
Catalog::Catalog()
{
}
Catalog::~Catalog()
{
}
//		Catalog duplicate();


// Adds a Song pointer to the vector
void Catalog::addSong(Song *i)
{
	cat.push_back(i);
	return;
}


// Sort function stub
void Catalog::sort()
{
	cout << "Sort function" << endl;
	return;
}

// Randomizes the vector
void Catalog::shuffle()
{
	// I don't know if this works, but it compiles
	unsigned seed = time(NULL);
	std::shuffle(cat.begin(), cat.end(), std::default_random_engine(seed));
	return;
}

//		Song getsong();

// Prints all songs for testing purposes
void Catalog::printSongs()
{
	
	for(int i = 0; i < cat.size(); ++i )
	{
		
		cout << cat[i]->toString() << endl; 
	}
}

// Clear catalog
void Catalog::clear()
{
	cat.clear();
}

