/* CLI Setlist Manager
 * Unit tests
 */

// Headers
#include "fileio.h"
#include "timemod.h"
#include "song.h"
#include <iostream>
#include <string.h>
#include "catalog.h"
#include <vector>
#include <list>
#include "songselector.h"
#include "setlist.h"
#include "configmanager.h"
using namespace std;

//Preprocessor Definitions
#define DEBUG
#define DEBUG1
#define DEBUG2

// Functions
// void waitenter(void);


int main(void){





	
// Song class tests
std::cout << "*-------Testing Song class functions" << std::endl;
Song testsong;
std::string blerg;
blerg = "ploop";
bool boof = true;
int yerp = 9001;

// Title

testsong.setTitle(blerg);
std::cout << "Song Title set/get: " ;
if(testsong.getTitle().compare(blerg) == 0)
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

// Composer
testsong.setComposer(blerg);
std::cout << "Song Composer set/get: ";
if(testsong.getComposer().compare(blerg) == 0 )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

// Key
testsong.setKey(blerg);
std::cout << "Song Key set/get: ";
if(testsong.getKey().compare(blerg) == 0 )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

// Genre
testsong.setGenre(blerg);
std::cout << "Song Genre set/get: ";
if(testsong.getGenre().compare(blerg) == 0 )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

// Archive
testsong.setArchive(boof);
std::cout << "Song Archive set/get: ";
if(testsong.isArchive() )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}
testsong.toggleArchive();
std::cout << "Song Archive toggle: ";
if(testsong.isArchive() )
{
	std::cout << "Fail" << std::endl; 
}
else
{
	std::cout << "Pass" << std::endl; 
}

// Length
testsong.setLength(yerp);
std::cout << "Song Length set/get: ";
if(testsong.getLength() == yerp )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

// Tempo
testsong.setTempo(yerp);
std::cout << "Song Tempo set/get: ";
if(testsong.getTempo() == yerp )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

// Intro
testsong.setIntro(yerp);
std::cout << "Song Intro set/get: ";
if(testsong.getTempo() == yerp )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

// To String
std::string tostr;
std::string a = " | ";
tostr = blerg + a + blerg + a + blerg + a + blerg + a + "Archive: False" + a + "Length:" + to_string(yerp) + a + "Tempo:" + to_string(yerp) + a + "Intro:" + to_string(yerp);
std::cout << "Song to string: ";
if(testsong.toString().compare(tostr) == 0)
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

// Timemod
std::cout << "*--------Testing Time modifiers" << std::endl;
unsigned int i=7349;
std::cout << "Timemod sectohr [" << sectohr(i) << "]: ";
if(sectohr(i) == 2 )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

std::cout << "Timemod remmin [" << remmin(i) << "]: ";
if(remmin(i) == 2 )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

std::cout << "Timemod remsec [" << remsec(i) << "]: ";
if(remsec(i) == 29 )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}
std::cout << "Timemod addseconds: ";
if(addseconds(2,2,29) == i )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}



/* Unused class
// Timestore
timestore ts1;
std::cout << "*--------Timestore class" << std::endl;
i = 2;
//Gets and sets
std::cout << "Timestore Hour get/set: ";
ts1.setHour(i);
if(ts1.getHour() == i )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}

std::cout << "Timestore Minute get/set: ";
ts1.setMinute(i);
if(ts1.getMinute() == i )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}
std::cout << "Timestore Second get/set: ";
ts1.setSecond(i);
if(ts1.getSecond() == i )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}
// Parameterized (seconds only)
i = 7349;
timestore ts2(i);
std::cout << "Paramaterized constructor (seconds only) [" << ts2.getHour() << ":" << ts2.getMinute() << ":" << ts2.getSecond() << "]: ";
if(ts2.getHour() == 2 && ts2.getMinute() == 2 && ts2.getSecond() == 29 )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}
*/

// Catalog from external file
std::cout << "*--------Catalog and catalog files" << std::endl;
Catalog testcat;
openCatalog("Example.setlist",&testcat);
std::cout << "Catalog read from file: ";
if(testcat.getSong(0).getTitle().compare("Chocolate Rain") == 0 )
{
	std::cout << "Pass\n"; 
}
else
{
	std::cout << "Fail\n"; 
}

// Duplication

std::cout << "Catalog Duplicate: "  ;
Catalog testcat2;
testcat.duplicate(&testcat2);
if(testcat.getSong(0).getTitle().compare(testcat2.getSong(0).getTitle()) == 0 )
{
	std::cout << "Pass\n"; 
}
else
{
	std::cout << "Fail\n"; 
}


// configmanager

std::cout << "*--------Config Manager" << std::endl;
ConfigManager config;
config.setLastCatalog(blerg);
std::cout << "LastCatalog set/get: ";
if(config.getLastCatalog().compare(blerg) == 0)
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std::endl; 
}
config.setDefaultBreakLength(yerp);
std::cout << "defaultBreakLength set/get: ";
if(config.getDefaultBreakLength() == yerp )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std :: endl; 
}
config.setDefaultBreakCount(yerp);
std::cout << "defaultBreakCount set/get: ";
if(config.getDefaultBreakCount() == yerp )
{
	std::cout << "Pass" << std::endl; 
}
else
{
	std::cout << "Fail" << std :: endl; 
}
//****************************************************************************
// Informal testing

testcat.sort_title();
SongSelector testselector(&testcat);
Setlist testsetlist(3600,3,300,"dance,disco,pop,rock,blues",&testcat);
/*testsetlist.setGenreRestrict("dance,disco,pop,rock,jazz,blues");
testsetlist.setLength(3600);
testsetlist.setBreakCount(3);
testsetlist.setBreakLength(300);
//testsetlist.populate(testselector);
testsetlist.populate(&testcat);
*/
std::cout << "******************************************\n";
testsetlist.printSongs();
return 0;
}

// Pauses program until user hits enter
/*
void waitenter(void)
{
	std::cout << "Press enter to continue" << std::endl;
	while (cin.get() != '\n');
	return;
}
*/
