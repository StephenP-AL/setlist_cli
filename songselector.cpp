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

SongSelector::SongSelector(Catalog *cat)
{
	this->build(cat);
	return;
}
// 
void SongSelector::build(Catalog *cat)
{
	// take songs and randomize order
	
	unsigned seed = time(NULL);
	method = seed % 2;
	std::cout << method << std::endl;
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
	
	std::shuffle(shuffler.begin(), shuffler.end(), std::default_random_engine(seed));
	
	//Add songs to list
	for(unsigned int i = 0; i < shuffler.size(); i++)
	{
		sslist.push_back(shuffler[i]); 
	}
	

	return;
}


void SongSelector::printList()
{
	it = sslist.begin();
	while(it != sslist.end())
	{
		cout << ((Song*)*it)->toString() << std::endl;
	       	it++;	
	}
}

Song* SongSelector::nextSong(Song* previous, unsigned int index)
{
	it = sslist.begin();
//	Song* ret = NULL;
	if(previous == NULL )
	{
		Song* ret = (Song*)*it;
		sslist.erase(it);
		return(ret);
	}
	
	else if((index + method) % 2 == 0 )
	{
		for(Song* ret = NULL; it != sslist.end(); it++ )
		{
			if(  ((Song*)*it)->getKey().compare(previous->getKey()) != 0   )
			{
				ret = *it;
				sslist.erase(it);
				return(ret);
			}
#ifdef DEBUG
		printf("%s\n","---DEBUG--- SONG SELECTOR rejected: wrong key");
#endif
	
		}
#ifdef DEBUG
		printf("%s\n","---DEBUG--- SONG SELECTOR No matching song");
#endif
		
		return(NULL);		
	}
	else
	{
		for(Song* ret = NULL; it != sslist.end(); it++ )
		{
			Song* comp = (Song*)*it;
			double difference, ratio;
			if(previous->getTempo() <= comp->getTempo() )
			{
				difference = comp->getTempo() - previous->getTempo(); 
			}
			else
			{
				difference = previous->getTempo() - comp->getTempo(); 
			}
			ratio = difference / (double)previous->getTempo();
			if(ratio > 0.1   )
			{
				ret = *it;
				sslist.erase(it);
				return(ret);
			}
#ifdef DEBUG
			printf("%s\n","---DEBUG--- SONG SELECTOR rejected: wrong tempo");
#endif
			
		}
#ifdef DEBUG
		printf("%s\n","---DEBUG---SONG SELECTOR No matching song");
#endif
       		return NULL;		
	}
	
       		
	


	return(NULL);
}
