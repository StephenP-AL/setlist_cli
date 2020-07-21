/* fileio.h
 * Reads and writes files
 */

#ifndef FILEIO_H
#define FILEIO_H

#include "catalog.h"
#include <fstream>
#include <string.h>

void openCatalog(string path, Catalog *open);
void writeCatalog(string path, Catalog cat);

void waitenter(void);







#endif
