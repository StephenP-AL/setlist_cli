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
			string genrea = catalogSortFormat(a->getGenre());
			string genreb = catalogSortFormat(b->getGenre());
			string compa = catalogSortFormat(a->getComposer());
			string compb = catalogSortFormat(b->getComposer());
			string titlea = catalogSortFormat(a->getTitle());
			string titleb = catalogSortFormat(b->getTitle());
			if(genrea.compare(genreb) != 0 )
			{
				cout << genrea << " | " << genreb << " " << (genrea.compare(genreb) < 0) << endl;

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
			string compa = catalogSortFormat(a->getComposer());
			string compb = catalogSortFormat(b->getComposer());
			string titlea = catalogSortFormat(a->getTitle());
			string titleb = catalogSortFormat(b->getTitle());
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
			string titlea = catalogSortFormat(a->getTitle());
			string titleb = catalogSortFormat(b->getTitle());
			return(titlea.compare(titleb) < 0);
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
