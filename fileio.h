/* fileio.h
 * Reads and writes files
 */

#ifndef FILEIO_H
#define FILEIO_H

#include "catalog.h"
#include <fstream>
#include <string.h>

void openCatalog(std::string path, Catalog *open);
void writeCatalog(std::string path, Catalog *out);

void waitenter(void);







#endif
