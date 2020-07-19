/* fileio.h
 * Reads and writes files
 */

#ifndef FILEIO_H
#define FILEIO_H

#include "catalog.h"
#include <fstream>
#include <string.h>

Catalog openCatalog(string path);
void writeCatalog(string path, Catalog cat);








#endif
