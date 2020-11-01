/* configmanager.h
 * Stores and loads configurations between sessions
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <string.h>
#include <fstream>

class ConfigManager 
{
	private:
		std::string lastCatalog;
		int defaultBreakLength;
		int defaultBreakCount;
		int defaultSetLength;
		int defaultIntro;
		bool initialize();
		std::string configFile();
	public:
		ConfigManager();
		~ConfigManager();
		void setLastCatalog(std::string s);
		std::string getLastCatalog();
		void setDefaultBreakLength(int i);
		int getDefaultBreakLength();
		void setDefaultBreakCount(int i);
		int getDefaultBreakCount();
		void setDefaultIntro(int i);
		int getDefaultIntro();
		void setDefaultSetLength(int i);
		int getDefaultSetLength();
		void load();
		void write();
		std::string toString();
};
#endif
