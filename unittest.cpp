/* CLI Setlist Manager
 * Unit tests
 */

// Headers
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

return 0;
}
