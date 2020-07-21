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

			       	if(line.substr(0,6).compare("title:") == 0 )
				{
					songptr->setTitle(line.substr(6,line.length())); 
				}
			 	else if(line.substr(0,9).compare("composer:") == 0 )
				{
				       	songptr->setComposer(line.substr(9,line.length()));
				}
				else if(line.substr(0,4).compare("key:") == 0 )
				{
					songptr->setKey(line.substr(4,line.length()));
				}
				
			}

			open->addSong(songptr);
			songptr = NULL;
			
			
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
