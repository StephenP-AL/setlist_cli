/* Catalog.h
 * Defines Catalog class
 */

// Definitions
#ifndef CATALOG_H
#define CATALOG_H

// Headers
#include "song.h"
#include <vector>
using namespace std;

class Catalog
{
	private:
		vector<Song*> cat;
		unsigned int iterator;
	public:
		Catalog();
		~Catalog();
//		Catalog duplicate();
		void addSong(Song *i);
		void sort();
		void shuffle();
//		Song getsong();
		void printSongs();
		void clear();
};
#endif
