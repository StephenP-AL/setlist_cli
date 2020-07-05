/* Song.cpp
 *
 */
// Definitions
#define DEBUG

// Headers
#include "song.h"
#include <string.h>
#include <iostream>
#include <string.h>
using namespace std;

Song::Song(){
//	Archive = false;
}

//Song::~Song()
//{}
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

void Song::setTitle(string title)
{
#ifdef DEBUG
	printf("%s%s\n","---DEBUG---",title);
#endif
	
	Title = title;
	return;
}
std::string Song::getTitle()
{
	return (Title);
}

