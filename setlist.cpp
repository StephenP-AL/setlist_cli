/*
 * setlist.cpp
 */
#define DEBUG
#define DEBUG1

#include "setlist.h"
#include "songselector.h"
#include "song.h"
#include "catalog.h"
#include <iostream>
#include <sstream>

// Constructors
Setlist::Setlist()
{
	intermission = new Song;
	Length = 0;
	BreakCount = 0;
	BreakLength = 0;
	intermission = new Song;
	intermission->setLength(0);
	intermission->setTempo(-1);
	intermission->setTitle("Intermission");
}

Setlist::~Setlist()
{
	delete intermission;
	this->noClearOnExit();//FIX THIS
}

Setlist::Setlist(unsigned int length, unsigned int breakcount, unsigned int breaklength, 
				std::string genrerestrict, SongSelector select)
{
	Length = length;
	BreakCount = breakcount;
	BreakLength = breaklength;
	setGenreRestrict(genrerestrict);
	intermission = new Song;
	intermission->setLength(breaklength);
	intermission->setTempo(-1);
	intermission->setTitle("Intermission");
	this->populate(select);
}
Setlist::Setlist(unsigned int length, unsigned int breakcount, unsigned int breaklength, 
				std::string genrerestrict, Catalog* cat)
{
	Length = length;
	BreakCount = breakcount;
	BreakLength = breaklength;
	setGenreRestrict(genrerestrict);
	intermission = new Song;
	intermission->setLength(breaklength);
	intermission->setTempo(-1);
	intermission->setTitle("Intermission");
	this->populate(cat);
}

// Populators
void Setlist::populate(SongSelector select)
{
	bool* breakState = new bool[BreakCount];
	unsigned int playSegment = Length / (BreakCount + 1);
	unsigned int index;
	Song* prev = NULL;
	while(this->currentLength() < Length )
	{
		for(int i = 0; i < BreakCount; i++ )
		{
			if(!*(breakState + i) && (currentLength() > (playSegment * (i + 1) - (BreakLength / 2))))
			{
				 this->addSong(intermission);
				 *(breakState + i) = true;
			}
		}
	       	// Code for adding songs from Songselector
		Song* next;
		next = select.nextSong(prev,index);
		bool reject = false;
		for(int i = 0; i < GenreRestrict.size(); i++ )
		{

			
			 if(!genreCompare(GenreRestrict[i], next->getGenre() ))
			 {
#ifdef DEBUG
				 printf("%s","---DEBUG---SETLIST rejected: incorrect genre: " );
				 std::cout << next->getGenre() << std::endl;
#endif
				 
				reject = true;
				break; 
			 }
		}
		if(!reject )
		{
			index++;
			this->addSong(next);
			prev = next;
	 	}
	 

	}
	
	return;
}
void Setlist::populate(Catalog* cat)
{
	SongSelector select(cat);
	this->populate(select);
	return;
}

bool genreCompare(std::string a, std::string b)
{
	return true;
	if(catalogSortFormat(a).compare(catalogSortFormat(b)) == 0 )
	{
		return true; 
	}
	else	
	{
		return false;
	}
}

unsigned int Setlist::currentLength()
{
	int total = 0;
	for(int i = 0; i < this->size(); i++)
	{
		total += this->getSongptr(i)->getLength();
	}
	
	return(total);
}

// Sets and gets
void Setlist::setGenreRestrict(std::string in)
{
	GenreRestrict.clear();
	stringstream stream(in);
	while(stream.good() )
	{
		std::string a;
	       	getline(stream, a, ',');	
		GenreRestrict.push_back(a);
	}
#ifdef DEBUG
	std::cout << "---DEBUG--- Setlist GenreRestrict contents\n";
	for(int i = 0; i < GenreRestrict.size(); i++ )
	{
		std::cout << GenreRestrict[i] << std::endl; 
	}
	
#endif
	
	return;
}

void Setlist::setLength(unsigned int l)
{
	Length = l;
	return;
}

unsigned int Setlist::getLength()
{
	return(Length);
}

void Setlist::setBreakCount(unsigned int c)
{
	BreakCount = c;
	return;
}

unsigned int Setlist::getBreakCount()
{
	return(BreakCount);
}

void Setlist::setBreakLength(unsigned int bl)
{
	BreakLength = bl;
	intermission->setLength(bl);
	return;
}

unsigned int Setlist::getBreakLength()
{
	return(BreakLength);
}

