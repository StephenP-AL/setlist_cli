/* Song.h
*  Defines Song class
*/

// Definitions

#ifndef SONG_H
#define SONG_H

// Headers
#include <string.h>
#include <string>
#include <iostream>
using namespace std;


class Song
{
private:
	std::string Title;
	std::string Composer;
	std::string Key;
	std::string Genre;
	bool Archive;
	int Length;
	int Tempo;
	int Intro;

public:
	Song();
	~Song();
//	Song(std::string title, std::string composer, std::string key, std::string genre, bool archive, int length, int tempo, int intro);
	void setTitle(std::string title);
	std::string getTitle();
		



};
#endif
