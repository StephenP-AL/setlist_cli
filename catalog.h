/* Catalog.h
 * Defines Catalog class
 */



/**********************************************************
 * NEED TO FIX:
 * clearOnExit is a bad solution because I don't know how to 
 * properly override the parent class deconstructor.
 * I need subclass setlist to not delete all pointers in the vector
 * but parent class should.
************************************************************/

// Definitions
#ifndef CATALOG_H
#define CATALOG_H

// Headers
#include "song.h"
#include <vector>
// using namespace std;

class Catalog
{
	private:
		bool clearOnExit; // FIX THIS
		std::vector<Song*> cat;
		unsigned int iterator;
	public:
		Catalog();
		~Catalog();
		void duplicate(Catalog *dup);
		void addSong(Song *i);
		void sort_composer();
		void sort_genre();
		void sort_title();
		void shuffle();
		Song getSong(unsigned int i);
		Song* getSongptr(unsigned int i);
		void printSongs();
		void clear();
		unsigned int size();
		void expand(unsigned int size);
		void noClearOnExit(); // FIX THIS
};
std::string catalogSortFormat(std::string instring);
#endif
