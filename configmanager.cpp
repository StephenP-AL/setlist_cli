/* configmanager.cpp
 * Loads and saves configuration settings between sessions
 */

#include "configmanager.h"
#include <iostream>

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
void ConfigManager::loadConfig()
{
	const char *file = getenv("HOME");
	std::cout << "Load config stub " << file << std::endl;
	return;
}	
void ConfigManager::writeConfig()
{
	std::cout << "Write config stub \n";
	return;
}
std::string ConfigManager::toString()
{
	return "blerg";
}

