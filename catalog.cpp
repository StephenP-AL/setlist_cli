/* Catalog.cpp
 *
 */
// Definitions
// #define DEBUG

// Headers
#include "catalog.h"
#include "song.h"
#include <vector>
Catalog::Catalog()
{
}
Catalog::~Catalog()
{
}
//		Catalog duplicate();
void Catalog::addSong(Song *i)
{
	cat.push_back(i);
	cout << i->getTitle() << endl;
	return;
}
void Catalog::sort()
{
	cout << "Sort function" << endl;
	return;
}
//		void shuffle();
//		Song getsong();


