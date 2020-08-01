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
//	Catalog::clear();
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


// Sort function 
void Catalog::sort_composer()
{
	std::sort(cat.begin(), cat.end(), [](Song* a, Song* b)
		{
			string compa = a->getComposer();
			string compb = b->getComposer();
			string titlea = a->getTitle();
			string titleb = b->getTitle();

			for(int i = 0; i < compa.length(); i++ )
			{
				compa[i] = toupper(compa[i]); 
			}
			for(int i = 0; i < compb.length(); i++ )
			{
				compb[i] = toupper(compb[i]); 
			}
 			for(int i = 0; i < titlea.length(); i++ )
			{
				titlea[i] = toupper(titlea[i]); 
			}
			for(int i = 0; i < titleb.length(); i++ )
			{
				titleb[i] = toupper(titleb[i]); 
			}
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
	cout << "clear\n";
	for(int i  = 0; i < cat.size(); i++ )
	{
		cout << i << endl;
		delete cat[i]; 
		cout << i << endl;
	}
//	cat.clear();
//	cat.resize(1);
//	cat.shrink_to_fit();
	
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
