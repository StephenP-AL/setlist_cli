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




Catalog openCatalog(string path)
{
	
	Catalog open;
	string line;
	unsigned int num;
	Song *songptr;
	ifstream infile;
	infile.open(path);
	if(!infile )
	{
		cout << "Unable to open '" << path << "'\n";	 
		delete songptr;
		return open;
	}
	else
	{
		
		cout << "Opening" << endl;
		while(!infile.eof() )
		{
			getline(infile,line);
			cout << line << endl;
		}
		
 	
	if (songptr != NULL)
	{
	//	delete songptr;
	}
	return (open);
      		
	}
	
}

void writeCatalog(string path, Catalog cat)
{
	cout << "Stub file writer" << endl;
	return;
}
