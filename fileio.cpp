/* fileio.cpp
 * functions for reading and writing to files
 */


// Headers
#include "fileio.h"
#include "catalog.h"
#include "song.h"
#include <fstream>
#include <string.h>
using namespace std;

// Definitions
#define DEBUG




void openCatalog(string path,Catalog *open)
{
	
	string line;
	unsigned int num;
	Song *songptr;
	ifstream infile;
	infile.open(path);
	if(!infile )
	{
		cout << "Unable to open '" << path << "'\n";	 
		delete songptr;
		return;
	}
	else
	{
		
		cout << "Opening " << path << endl;
		while(!infile.eof() && line.substr(0,4).compare("#eof") != 0)
		{
			while(!infile.eof() && line.substr(0,5).compare("#song") != 0 )
			{
				getline(infile,line);
			}
			songptr = new Song;
			while(!infile.eof() && line.substr(0,5).compare("#gnos") != 0 )
			{
				getline(infile,line);
				// Replaces CR with null terminator
				if((int)line[line.length() - 1] == 13 )
				{
					line[line.length() - 1] = 0; 
				}
				// Title
			       	if(line.substr(0,6).compare("title:") == 0 )
				{
					songptr->setTitle(line.substr(6,line.length())); 
				}
				// Composer
			 	else if(line.substr(0,9).compare("composer:") == 0 )
				{
				       	songptr->setComposer(line.substr(9,line.length()));
				}
				// Key
				else if(line.substr(0,4).compare("key:") == 0 )
				{
					songptr->setKey(line.substr(4,line.length()));
				}
				// Genre
				else if(line.substr(0,6).compare("genre:") == 0 )
				{
					songptr->setGenre(line.substr(6,line.length())); 
				}
				// Length
				else if(line.substr(0,7).compare("length:") == 0 )
				{
					if(line.substr(7,line.length()).compare("") == 0 )
					{
						songptr->setLength(0); 
					}
					else
					{
						songptr->setLength(stoi(line.substr(7,line.length())));
					}
				}
				else if(line.substr(0,6).compare("tempo:") == 0 )
				{
					if(line.substr(6,line.length()).compare("") == 0 )
					{
						songptr->setTempo(0); 
					}
					else
					{
						songptr->setTempo(stoi(line.substr(6,line.length()))); 
					}
				}
				
				
			}

			if(songptr->getTitle().length() > 0)
			{
				open->addSong(songptr);
				songptr = NULL;
			}
			else
			{
				delete songptr; 
			}
			
			
			
		}
	
	if (songptr != NULL)
	{
	//	delete songptr;
	}
	return;
      		
	}
	
}

void writeCatalog(string path, Catalog cat)
{
	cout << "Stub file writer" << endl;
	return;
}

void waitenter(void)
{
	cout << "Press enter to continue" << endl;
	while (cin.get() != '\n');
	return;
}
