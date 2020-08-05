/* songselector.h
 * Defines songselector class
 */

// Definitions
#ifndef SONGSELECTOR_H
#define SONGSELECTOR_H

// Headers
#include "song.h"
#include <list>
#include "catalog.h"
using namespace std;

class SongSelector
{
	private:
		std::list<Song*> sslist;
		std::list<Song*>::iterator it;
	public:
		SongSelector();
		~SongSelector();
		SongSelector(Catalog *cat);
		void build(Catalog *cat);
		
};
#endif
