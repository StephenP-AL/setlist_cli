/*
 * setlist.cpp
 */

#include "setlist.h"
#include "songselector.h"
#include "song.h"
#include "catalog.h"

// Constructors
Setlist::Setlist()
{
	intermission = new Song;
}

Setlist::~Setlist()
{
	delete intermission;
}

Setlist::Setlist(unsigned int l, unsigned int c, unsigned int bl, SongSelector select)
{

}
Setlist::Setlist(unsigned int l, unsigned int c, unsigned int bl, Catalog* cat)
{
}

// Populators
void Setlist::populate(SongSelector select)
{
	return;
}
void Setlist::populate(Catalog* cat)
{
	return;
}

unsigned int Setlist::currentLength()
{
	return(1);
}

// Sets and gets
void Setlist::setGenreRestrict(std::string in)
{
	return;
}

void Setlist::setLength(unsigned int l)
{
	return;
}

unsigned int Setlist::getLength()
{
	return(1);
}

void Setlist::setBreakCount(unsigned int c)
{
	return;
}

unsigned int Setlist::getBreakCount()
{
	return(1);
}

void Setlist::setBreakLength(unsigned int bl)
{
	return;
}

unsigned int Setlist::getBreakLength()
{
	return(1);
}

