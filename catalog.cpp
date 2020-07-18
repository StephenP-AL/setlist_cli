/* Catalog.cpp
 *
 */
// Definitions
// #define DEBUG

// Headers
#include "catalog.h"
#include "song.h"
#include <vector>
#include <algorithm>
#include <random>
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
		void Catalog::shuffle()
{
	// I don't know if this works, but it compiles
	unsigned seed = time(NULL);
	std::shuffle(cat.begin(), cat.end(), std::default_random_engine(seed));
	return;
}
//		Song getsong();


