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
// #define DEBUG




void openCatalog(std::string path,Catalog *open)
{
	
	std::string line;
	unsigned int size; // This is for resizing the vector, which is not implemented
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
#ifdef DEBUG
	printf("%s","---DEBUG---Opening ");
	cout << path << endl;
#endif
		while(!infile.eof() && line.substr(0,4).compare("#eof") != 0)
		{
			while(!infile.eof() && line.substr(0,5).compare("#song") != 0 )
			{
				getline(infile,line);
				// Expand vector to accommodate new songs
				if(line.substr(0,13).compare("catalog_size:") == 0 )
				{
					size = stoi(line.substr(13,line.length()));
					open->expand(size);
				}
				
			}
			songptr = new Song;
			while(!infile.eof() && line.substr(0,5).compare("#gnos") != 0 )
			{
				getline(infile,line);
				// removes CR
				if((int)line[line.length() - 1] == 13 )
				{
					line = line.substr(0,line.length() - 1);
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
				// Tempo
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
				// Intro
				else if(line.substr(0,6).compare("intro:") == 0 )
				{
					if(line.substr(6,line.length()).compare("") == 0 )
					{
						songptr->setIntro(0); 
					}
			       		else
					{
						songptr->setIntro(stoi(line.substr(6,line.length()))); 
					}
				}
				else if(line.substr(0,9).compare("archive:0") == 0 )
				{
					songptr->setArchive(false);
				}
				else if(line.substr(0,9).compare("archive:1") == 0 )
				{
					songptr->setArchive(true);
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
	/* This seemed like a good idea, but cuases "free(): double free detected in tcache 2"
	if (songptr != NULL)
	{
		delete songptr;
	}
	*/
	infile.close();
	return;
      		
	}
	
}

void writeCatalog(std::string path, Catalog *out)
{
	ofstream outfile;
	outfile.open(path);
	if(!outfile )
	{
		cout << "Unable to open '" << path << "'" << endl; 
	}
	outfile << "catalog_size:" << out->size() << endl << endl;
	for(unsigned int i = 0; i < out->size(); i++ )
	{
		outfile << "#song" << endl;
		outfile << "title:" << out->getSong(i).getTitle() << endl;
		outfile << "composer:" << out->getSong(i).getComposer() << endl;
		outfile << "key:" << out->getSong(i).getKey() << endl;
		outfile << "genre:" << out->getSong(i).getGenre() << endl;
		outfile << "length:" << out->getSong(i).getLength() << endl;
		outfile << "tempo:" << out->getSong(i).getTempo() << endl;
		outfile << "intro:" << out->getSong(i).getIntro() << endl;
		outfile << "archive:" << out->getSong(i).isArchive() << endl;
		// Sample line below
//		outfile << "<++>" << out->getSong(i).get<++>() << endl;
		outfile << "#gnos" << endl << endl;
		 
		
	}
	
	outfile << "#eof";	
	outfile.close();

	return;
}

void waitenter(void)
{
	cout << "Press enter to continue" << endl;
	while (cin.get() != '\n');
	return;
}
