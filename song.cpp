/* Song.cpp
 *
 */
// Definitions
// #define DEBUG

// Headers
#include "song.h"
#include <string.h>
#include <iostream>
#include <string.h>
using namespace std;

// Constructors

Song::Song(){
//	Archive = false;
	Title = "";
	Composer = "";
}

Song::~Song()
{}
/*Song::Song(string title, string composer, string key, string genre, bool archive, int length, int tempo, int intro)
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
void Song::setTitle(string title)
{
	Title = title;
#ifdef DEBUG
	cout << "Title set to '" << Title << "'" << endl;
#endif
	
	return;
}

std::string Song::getTitle()
{
	return (Title);
}

void Song::setComposer(string composer)
{
	Composer = composer;
#ifdef DEBUG
	printf("%s","---DEBUG--- Composer set to:");
	cout << composer << endl; 
#endif
	return;
}

string Song::getComposer()
{
	return (Composer);
}

void Song::setKey(string key)
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
