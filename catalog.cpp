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
void Catalog::add(Song *i)
{
	cat.push_back(i);
	return;
}
//		void sort();
//		void shuffle();
//		Song getsong();


