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
//
//using namespace std;
Catalog::Catalog()
{
	clearOnExit = true;
}
Catalog::~Catalog()
{
	// FIX THIS
	if(clearOnExit )
	{
		Catalog::clear();
	}
}
void Catalog::duplicate(Catalog *dup)
{
	dup->expand(cat.size());
	for(unsigned int i = 0; i < cat.size(); i++ )
	{
		Song *add = new Song;
		
		add->setTitle(cat[i]->getTitle());
		add->setComposer(cat[i]->getComposer());
		add->setKey(cat[i]->getKey());
		add->setGenre(cat[i]->getGenre());
		add->setLength(cat[i]->getLength());
		add->setTempo(cat[i]->getTempo());
		add->setIntro(cat[i]->getIntro());
		add->setArchive(cat[i]->isArchive());
		// Template below
	//	add->set<++>(cat[i]->get<++>());
		dup->addSong(add); 
	}
	return;
}	

// Adds a Song pointer to the vector
void Catalog::addSong(Song *i)
{
	cat.push_back(i);
	return;
}

// Removes spaces and capitalizes string
std::string catalogSortFormat(std::string instring)
{
//	instring.erase(remove_if(instring.begin(), instring.end(), isspace), instring.end());
	int j = 0;
	for(int i = 0; i < instring.length(); i++ )
	{
		if(isspace(instring[i]) )
		{
			continue; 
		}
		else
		{
			instring[j] = toupper(instring[i]);
			j++;
		}
		
	}
	instring.resize(j);
	return instring;
}	

// Sort by genre then composer then title
void Catalog::sort_genre()
{
	std::sort(cat.begin(), cat.end(), [](Song* a, Song* b)
		{
			std::string genrea = catalogSortFormat(a->getGenre());
			std::string genreb = catalogSortFormat(b->getGenre());
			std::string compa = catalogSortFormat(a->getComposer());
			std::string compb = catalogSortFormat(b->getComposer());
			std::string titlea = catalogSortFormat(a->getTitle());
			std::string titleb = catalogSortFormat(b->getTitle());
			if(genrea.compare(genreb) != 0 )
			{
				return(genrea.compare(genreb) < 0); 
			}
			else if(compa.compare(compb) == 0 )
			{
				return(titlea.compare(titleb) < 0);
			}
			else
			{
				return(compa.compare(compb) < 0 );
			}
		} );

	return;
}

// Sort by composer then title
void Catalog::sort_composer()
{
	std::sort(cat.begin(), cat.end(), [](Song* a, Song* b)
		{
			std::string compa = catalogSortFormat(a->getComposer());
			std::string compb = catalogSortFormat(b->getComposer());
			std::string titlea = catalogSortFormat(a->getTitle());
			std::string titleb = catalogSortFormat(b->getTitle());
			if(compa.compare(compb) == 0 )
			{
				return(titlea.compare(titleb) < 0);
			}
			else
			{
				return(compa.compare(compb) < 0 );
			}
			
		} );

	return;
}

// Sort by title
void Catalog::sort_title()
{
	std::sort(cat.begin(), cat.end(), [](Song* a, Song* b)
		{
			std::string titlea = catalogSortFormat(a->getTitle());
			std::string titleb = catalogSortFormat(b->getTitle());
			return(titlea.compare(titleb) < 0);
		} );
	return;
}
// Randomizes the vector
void Catalog::shuffle()
{
	unsigned seed = time(NULL);
	std::shuffle(cat.begin(), cat.end(), std::default_random_engine(seed));
	return;
}


Song* Catalog::getSongptr(unsigned int i)
{
	return(cat[i]);
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
		
		std::cout << cat[i]->toString() << std::endl; 
	}
}

// Clear catalog
void Catalog::clear()
{
	for(int i  = 0; i < cat.size(); i++ )
	{
		delete cat[i]; 
	}
	cat.clear();
	cat.resize(1);
	cat.shrink_to_fit();
	
	return;
}

// Size of the catalog
unsigned int Catalog::size()
{
	return(cat.size());
}

// Expands vector by the specified size 
void Catalog::expand(unsigned int size)
{
	cat.reserve(cat.size() + size);
	return;
}

//FIX THIS
void Catalog::noClearOnExit()
{
	clearOnExit = false;
}
