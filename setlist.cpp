/*
 * setlist.cpp
 */
#define DEBUG

#include "setlist.h"
#include "songselector.h"
#include "song.h"
#include "catalog.h"

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

Setlist::Setlist(unsigned int l, unsigned int c, unsigned int bl, SongSelector select)
{
	Length = l;
	BreakCount = c;
	BreakLength = bl;
	intermission = new Song;
	intermission->setLength(bl);
	intermission->setTempo(-1);
	intermission->setTitle("Intermission");
}
Setlist::Setlist(unsigned int l, unsigned int c, unsigned int bl, Catalog* cat)
{
	Length = l;
	BreakCount = c;
	BreakLength = bl;
	intermission = new Song;
	intermission->setLength(bl);
	intermission->setTempo(-1);
	intermission->setTitle("Intermission");
}

// Populators
void Setlist::populate(SongSelector select)
{
	bool* breakState = new bool[BreakCount];
	unsigned int playSegment = Length / (BreakCount + 1);
	unsigned int index;
	Song* prev = NULL;
//	std::cout << this->currentLength() << " | " << Length << '\n';
	while(this->currentLength() < Length )
	{
	
		// Adapted from java, not sure if will work
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
			 if(genreCompare(GenreRestrict[i], next->getGenre() ))
			 {
				reject = true;
				break; 
			 }
			 
		}
		if(!reject )
		{
			index++;
			this->addSong(next);
			next = prev;
	 	}
	 

	}
	
	return;
}
void Setlist::populate(Catalog* cat)
{
	return;
}

bool genreCompare(std::string a, std::string b)
{
	return false;
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

