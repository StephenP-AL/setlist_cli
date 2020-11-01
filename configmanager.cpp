/* configmanager.cpp
 * Loads and saves configuration settings between sessions
 */

#include "configmanager.h"
#include <iostream>
#include "defaults.h"
#include <sys/stat.h>

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
bool ConfigManager::initialize()
{
	std::string file = getenv("HOME");
	std::string file2 = "/.config/SetlistManager";
	file = file + file2;
	if(!mkdir(file.c_str(),0777))
	{
		return false;
	}
	std::ofstream outfile;
	if(!outfile )
	{
		return false; 
	}
	defaultBreakLength = D_BRLENGTH;
	defaultBreakCount = D_BRCOUNT;
	defaultIntro = D_INTRO;
	defaultSetLength = D_SETLENGTH;
	this->write();
	return true;
}
void ConfigManager::load()
{
	std::string file = getenv("HOME");
	std::string file2 = "/.config/SetlistManager/settings.cfg";
	file = file + file2;

	std::string line;
	std::ifstream infile;
	infile.open(file);
	if(!infile )
	{
		std::cout << "Unable to open configuration file: " << file << std::endl; 
		std::cout << "Creating configuration file\n";
		this->initialize();
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
#ifdef DEBUG
			std::cout << " Set to : " << defaultBreakLength	<< std::endl;
#endif
		}
		else if(line.substr(0,18).compare("defaultBreakCount=") == 0 )
		{
			defaultBreakCount = stoi(line.substr(18,line.length()-18));
#ifdef DEBUG
			std::cout << "Set to : " << defaultBreakCount << std::endl;	
#endif
		}
		else if(line.substr(0,17).compare("defaultSetLength=") == 0 )
		{
			defaultSetLength = stoi(line.substr(17,line.length() - 17));
#ifdef DEBUG
			std::cout << "Set to : " << defaultSetLength << std::endl;
#endif
		}
		else if(line.substr(0,13).compare("defaultIntro=") == 0 )
		{
			defaultIntro = stoi(line.substr(13,line.length() - 13));
#ifdef DEBUG
		       	std::cout << "Set to : " << defaultIntro << std::endl;	
#endif
		}
	}
	infile.close();
	return;
}	
void ConfigManager::write()
{
	std::ofstream outfile;
	outfile.open(this->configFile());
	if(!outfile )
	{
		this->configFile();
		return; 
	}
	outfile << "lastCatalog=" << lastCatalog << std::endl;
	outfile << "defaultBreakLength=" << defaultBreakLength << std::endl;
	outfile << "defaultBreakCount=" << defaultBreakCount << std::endl;
	outfile << "defaultSetLength=" << defaultSetLength << std::endl;
	outfile << "defaultIntro=" << defaultIntro << std::endl;
	outfile.close();
	return;
}
std::string ConfigManager::toString()
{
	std::string a;
	a = "Last: " + lastCatalog + " | Default break length: " + std::to_string(defaultBreakLength) + " | Default break count: " + std::to_string(defaultBreakCount);
	return "a";
}

std::string ConfigManager::configFile()
{
	std::string file = getenv("HOME");
	file = file + "/.config/SetlistManager/settings.cfg";
	return file;
}
