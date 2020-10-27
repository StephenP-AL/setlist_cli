/* configmanager.cpp
 * Loads and saves configuration settings between sessions
 */

#include "configmanager.h"
#include <iostream>

#define DEBUG
/*
	private:
		std::string lastCatalog;
		int defaultBreakLength;
		int defaultBreakCount;
		int defaultSetLength;
		int defaultIntro;
		*/

ConfigManager::ConfigManager()
{
	return;
}
ConfigManager::~ConfigManager()
{}
void ConfigManager::setLastCatalog(std::string s)
{
	lastCatalog = s;
	return;
}
std::string ConfigManager::getLastCatalog()
{
	return lastCatalog;
}
void ConfigManager::setDefaultBreakLength(int i)
{
	defaultBreakLength = i;
	return;
}
int ConfigManager::getDefaultBreakLength()
{
	return defaultBreakLength;
}
void ConfigManager::setDefaultBreakCount(int i)
{
	defaultBreakCount = i;
	return;
}
int ConfigManager::getDefaultBreakCount()
{
	return defaultBreakCount;
}
void ConfigManager::setDefaultIntro(int i)
{
	defaultIntro = i;
}
int ConfigManager::getDefaultIntro()
{
	return defaultIntro;
}
void ConfigManager::setDefaultSetLength(int i)
{
	defaultSetLength = i;
	return;
}
int ConfigManager::getDefaultSetLength()
{
	return defaultSetLength;
}
void ConfigManager::load()
{
//	const char *file = getenv("HOME");
	std::string file = getenv("HOME");
	std::string file2 = "/.config/SetlistManager/settings.cfg";
	file = file + file2;

	std::string line;
	std::ifstream infile;
	infile.open(file);
	if(!infile )
	{
		std::cout << "Unable to open configuration file: " << file << std::endl; 
		return;
	}
	while(!infile.eof() )
	{
		getline(infile,line);
		if(line.substr(0,12).compare("lastCatalog=") == 0 )
		{
			lastCatalog = line.substr(12,line.length() - 12);
#ifdef DEBUG
			std::cout << "Set to : " << lastCatalog  << std::endl; 
#endif
		}
		else if(line.substr(0,19).compare("defaultBreakLength=") == 0)
		{
			defaultBreakLength = stoi(line.substr(19,line.length()-19));
			std::cout << " Set to : " << defaultBreakLength	<< std::endl;
		}
		else if(line.substr(0,18).compare("defaultBreakCount=") == 0 )
		{
			defaultBreakCount = stoi(line.substr(18,line.length()-18));
			std::cout << "Set to : " << defaultBreakCount << std::endl;	
		}
		else if(line.substr(0,17).compare("defaultSetLength=") == 0 )
		{
			defaultSetLength = stoi(line.substr(17,line.length() - 17));
			std::cout << "Set to : " << defaultSetLength << std::endl;
		}
		else if(line.substr(0,13).compare("defaultIntro=") == 0 )
		{
			defaultIntro = stoi(line.substr(13,line.length() - 13));
		       	std::cout << "Set to : " << defaultIntro << std::endl;	
		}
		
		
       		std::cout << line << std::endl;		
	}
	
	
	return;
}	
void ConfigManager::write()
{
	std::cout << "Write config stub \n";
	return;
}
std::string ConfigManager::toString()
{
	return "blerg";
}

