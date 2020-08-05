/* songselector.cpp
 *
 */
// Definitions
// #define DEBUG

// Headers
#include "catalog.h"
#include "song.h"
#include <list>
#include <vector>
#include "songselector.h"
#include <algorithm>
#include <random>

SongSelector::SongSelector()
{
	return;
}
SongSelector::~SongSelector()
{
	return;
}

void SongSelector::build(Catalog *cat)
{
	// take songs and randomize order
	vector<Song*> shuffler;

	for(unsigned int i = 0; i < cat->size(); i++ )
	{
		if(!cat->getSongptr(i)->isArchive() )
		{
			shuffler.push_back(cat->getSongptr(i));
		}
       		else
		{
			continue; 
		}
	}
	
	unsigned seed = time(NULL);
	std::shuffle(shuffler.begin(), shuffler.end(), std::default_random_engine(seed));
	
	for(unsigned int i = 0; i < shuffler.size(); i++)
	{
		sslist.push_back(shuffler[i]); 
	}
	it = sslist.begin();
	// Still need to figure out how to access list items
	while(it != sslist.end() )
	{
		Song *ptr;
		ptr = *it;
		cout << ptr << endl;

		it++;
	}
	return;
}
