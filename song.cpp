/* Song.cpp
 *
 */
// Definitions
// #define DEBUG

// Headers
#include "song.h"
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string.h>
//using namespace std;

// Constructors

Song::Song()
{
//	Archive = false;
	Title = "";
	Composer = "";
}

Song::~Song()
{}
/*Song::Song(std::string title, std::string composer, std::string key, std::string genre, bool archive, int length, int tempo, int intro)
{
	Title = title;
	Composer = composer;
	Key = key;
	Genre = genre;
	Archive = archive;
	Length = length;
	Tempo = tempo;
	Intro = intro;
}*/

// Gets and Sets
void Song::setTitle(std::string title)
{
	Title = title;
#ifdef DEBUG
	cout << "Title set to '" << Title << "'" << endl;
#endif
	
	return;
}

const std::string Song::getTitle()
{
	return (Title);
}

void Song::setComposer(std::string composer)
{
	Composer = composer;
#ifdef DEBUG
	printf("%s","---DEBUG--- Composer set to:");
	cout << composer << endl; 
#endif
	return;
}

std::string Song::getComposer()
{
	return (Composer);
}

void Song::setKey(std::string key)
{
	Key = key;
#ifdef DEBUG
	printf("%s","---DEBUG--- Key set to:");
	cout << key << endl;
#endif
	return;
}

std::string Song::getKey()
{
	return (Key);
}

void Song::setGenre(std::string genre)
{
	Genre = genre;
	return;
}

std::string Song::getGenre()
{
	return(Genre);
}
void Song::setArchive(bool archive)
{
	Archive = archive;
	return;
}

void Song::toggleArchive()
{
	if(Archive )
	{
		Archive = false; 
	}
	else
	{
		Archive = true; 
	}
	return;	
}

bool Song::isArchive()
{
	return (Archive);
}

void Song::setLength(unsigned int length)
{
	Length = length;
	return;
}

unsigned int Song::getLength()
{
	return (Length);
}

void Song::setTempo(int tempo)
{
	Tempo = tempo;
	return;
}

int Song::getTempo()
{
	return (Tempo);
}

void Song::setIntro(unsigned int intro)
{
	Intro = intro;
	return;
}

unsigned int Song::getIntro()
{
	return(Intro);
}

std::string Song::toString()
{
	std::string a = " | ";
	std::string arc = "Archive: False";
	if(Archive )
	{
		arc = "Archive: True"; 
	}
	
	return(Title + a + Composer + a + Key + a + Genre + a + arc + a + "Length:" + std::to_string(Length) + a + "Tempo:" + std::to_string(Tempo) + a + "Intro:" + std::to_string(Intro) );
}
