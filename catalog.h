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
		bool defautltCompare(Song *a, Song *b);
	public:
		Catalog();
		~Catalog();
		void duplicate(Catalog *dup);
		void addSong(Song *i);
		void sort();
		void shuffle();
		Song getSong(unsigned int i);
		void printSongs();
		void clear();
		unsigned int size();
		void expand(unsigned int size);
};
#endif
