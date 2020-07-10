/* CLI Setlist Manager
 * Unit tests
 */

// Headers
#include "timemod.h"
#include "song.h"
#include <iostream>
#include <string.h>

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

return 0;
}
