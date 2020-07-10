/* Converts between time units
 */

#ifndef timemod
#define timemod

#include <string.h>

using namespace std;

/* This class probably is necessary, but I'll leave it here just in case
class timestore
{
	private:
		unsigned int Hour;
		unsigned int Minute;
		unsigned int Second;

	public:
		timestore();
		~timestore();
		timestore(unsigned int hr, unsigned int min, unsigned int sec);
		timestore(unsigned int sec); //calculate all fields based on seconds only
		void setHour(unsigned int hr);
		unsigned int getHour();
		void setMinute(unsigned int min);
		unsigned int getMinute();
		void setSecond(unsigned int sec);
		unsigned int getSecond();

};
*/
unsigned int sectohr(unsigned int seconds);
unsigned int remmin(unsigned int seconds);
unsigned int remsec(unsigned int seconds);
unsigned int addseconds(unsigned int hour, unsigned int minute, unsigned int second);

#endif
