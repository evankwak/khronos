/*
@author Evan Kwak
@date 2012 - 10 - 25

*/

#include <khronos/julian_calendar.hpp>
#include <time.h>
#include <ctime>


namespace khronos {

	//default constructor usinng time of day
	Julian::Julian() {
		time_t nowTime = time(NULL);
		struct tm tmNow;
		localtime_s(&tmNow, &nowTime);
		year_ = year_t(tmNow.tm_year) + 1900;
		month_ = month_t(tmNow.tm_mon) + 1;
		day_ = day_t(tmNow.tm_mday);
	}


	
	year_t  year(Julian g) {

		return g.year();
	}

	month_t month(Julian g) {
		return g.month();

	}

	day_t day(Julian g) {
		return g.day();
	}

	hour_t hour(Julian g) {
		return g.hour();
	}

	minute_t minute(Julian g) {
		return g.minute();

	}

	second_t second(Julian g) {
		return  g.second();
	}


};



