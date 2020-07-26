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
	Catalog::clear();
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

// Returns a copy of Song stored at pointer index i
Song Catalog::getSong(unsigned int i)
{
	Song ret;
	if(cat.size() < i )
	{
		return(ret); 
	}
	ret.setTitle(cat[i]->getTitle());
	ret.setComposer(cat[i]->getComposer());
	ret.setKey(cat[i]->getKey());
	ret.setGenre(cat[i]->getGenre());
	ret.setLength(cat[i]->getLength());
	ret.setTempo(cat[i]->getTempo());
	ret.setIntro(cat[i]->getIntro());
	ret.setArchive(cat[i]->isArchive());

	return(ret);
}

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
	for(int i  = 0; i <cat.size(); i++ )
	{
		delete cat[i]; 
	}
	cat.clear();
	cat.shrink_to_fit();
}

// Size of the catalog
unsigned int Catalog::size()
{
	return(cat.size());
}

// Expands vecotr by the specified size 
void Catalog::expand(unsigned int size)
{
	cat.reserve(cat.size() + size);
	return;
}
