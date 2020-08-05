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
using namespace std;

//Preprocessor Definitions
#define DEBUG
#define DEBUG1
#define DEBUG2

// Functions
// void waitenter(void);


int main(void){





	
// Song class tests
cout << "*-------Testing Song class functions" << endl;
Song testsong;
string blerg;
blerg = "ploop";
bool boof = true;
int yerp = 9001;

// Title

testsong.setTitle(blerg);
cout << "Song Title set/get: " ;
if(testsong.getTitle().compare(blerg) == 0)
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Composer
testsong.setComposer(blerg);
cout << "Song Composer set/get: ";
if(testsong.getComposer().compare(blerg) == 0 )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Key
testsong.setKey(blerg);
cout << "Song Key set/get: ";
if(testsong.getKey().compare(blerg) == 0 )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Genre
testsong.setGenre(blerg);
cout << "Song Genre set/get: ";
if(testsong.getGenre().compare(blerg) == 0 )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Archive
testsong.setArchive(boof);
cout << "Song Archive set/get: ";
if(testsong.isArchive() )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}
testsong.toggleArchive();
cout << "Song Archive toggle: ";
if(testsong.isArchive() )
{
	cout << "Fail" << endl; 
}
else
{
	cout << "Pass" << endl; 
}

// Length
testsong.setLength(yerp);
cout << "Song Length set/get: ";
if(testsong.getLength() == yerp )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Tempo
testsong.setTempo(yerp);
cout << "Song Tempo set/get: ";
if(testsong.getTempo() == yerp )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Intro
testsong.setIntro(yerp);
cout << "Song Intro set/get: ";
if(testsong.getTempo() == yerp )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// To String
std::string tostr;
std::string a = " | ";
tostr = blerg + a + blerg + a + blerg + a + blerg + a + "Archive: False" + a + "Length:" + to_string(yerp) + a + "Tempo:" + to_string(yerp) + a + "Intro:" + to_string(yerp);
cout << "Song to string: ";
if(testsong.toString().compare(tostr) == 0)
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Timemod
cout << "*--------Testing Time modifiers" << endl;
unsigned int i=7349;
cout << "Timemod sectohr [" << sectohr(i) << "]: ";
if(sectohr(i) == 2 )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

cout << "Timemod remmin [" << remmin(i) << "]: ";
if(remmin(i) == 2 )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

cout << "Timemod remsec [" << remsec(i) << "]: ";
if(remsec(i) == 29 )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}
cout << "Timemod addseconds: ";
if(addseconds(2,2,29) == i )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}



/* Unused class
// Timestore
timestore ts1;
cout << "*--------Timestore class" << endl;
i = 2;
//Gets and sets
cout << "Timestore Hour get/set: ";
ts1.setHour(i);
if(ts1.getHour() == i )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

cout << "Timestore Minute get/set: ";
ts1.setMinute(i);
if(ts1.getMinute() == i )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}
cout << "Timestore Second get/set: ";
ts1.setSecond(i);
if(ts1.getSecond() == i )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}
// Parameterized (seconds only)
i = 7349;
timestore ts2(i);
cout << "Paramaterized constructor (seconds only) [" << ts2.getHour() << ":" << ts2.getMinute() << ":" << ts2.getSecond() << "]: ";
if(ts2.getHour() == 2 && ts2.getMinute() == 2 && ts2.getSecond() == 29 )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}
*/

// Catalog from external file
cout << "*--------Catalog and catalog files" << endl;
Catalog testcat;
openCatalog("Example.setlist",&testcat);
cout << "Catalog read from file: ";
if(testcat.getSong(0).getTitle().compare("Chocolate Rain") == 0 )
{
	cout << "Pass\n"; 
}
else
{
	cout << "Fail\n"; 
}

// Duplication

cout << "Catalog Duplicate: "  ;
Catalog testcat2;
testcat.duplicate(&testcat2);
if(testcat.getSong(0).getTitle().compare(testcat2.getSong(0).getTitle()) == 0 )
{
	cout << "Pass\n"; 
}
else
{
	cout << "Fail\n"; 
}

testcat.sort_title();
for(unsigned int i = 0; i < testcat.size(); i++ )
{
	cout << testcat.getSongptr(i)->getTitle() << endl; 
}
waitenter();
SongSelector testselector;
testselector.build(&testcat);

waitenter();
for(unsigned int i = 0; i < testcat.size(); i++ )
{
	cout << testcat.getSongptr(i)->getTitle() << endl; 
}
return 0;
}

// Pauses program until user hits enter
/*
void waitenter(void)
{
	cout << "Press enter to continue" << endl;
	while (cin.get() != '\n');
	return;
}
*/
