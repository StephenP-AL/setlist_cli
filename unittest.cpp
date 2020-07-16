/* CLI Setlist Manager
 * Unit tests
 */

// Headers
#include "timemod.h"
#include "song.h"
#include <iostream>
#include <string.h>
#include "catalog.h"
using namespace std;

//Preprocessor Definitions
#define DEBUG
#define DEBUG1
#define DEBUG2


int main(void){
	// Song class tests
cout << "*-------Testing Song class functions" << endl;
Song test;
string blerg;
blerg = "ploop";
bool boof = true;
int yerp = 9001;

// Title

test.setTitle(blerg);
cout << "Song Title set/get: " ;
if(test.getTitle().compare(blerg) == 0)
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Composer
test.setComposer(blerg);
cout << "Song Composer set/get: ";
if(test.getComposer().compare(blerg) == 0 )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Key
test.setKey(blerg);
cout << "Song Key set/get: ";
if(test.getKey().compare(blerg) == 0 )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Archive
test.setArchive(boof);
cout << "Song Archive set/get: ";
if(test.isArchive() )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}
test.toggleArchive();
cout << "Song Archive toggle: ";
if(test.isArchive() )
{
	cout << "Fail" << endl; 
}
else
{
	cout << "Pass" << endl; 
}

// Length
test.setLength(yerp);
cout << "Song Length set/get: ";
if(test.getLength() == yerp )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Tempo
test.setTempo(yerp);
cout << "Song Tempo set/get: ";
if(test.getTempo() == yerp )
{
	cout << "Pass" << endl; 
}
else
{
	cout << "Fail" << endl; 
}

// Intro
test.setIntro(yerp);
cout << "Song Intro set/get: ";
if(test.getTempo() == yerp )
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

Catalog testcatalog();

return 0;
}
