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
Song test;
string blerg;
blerg = "ploop";

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


}
