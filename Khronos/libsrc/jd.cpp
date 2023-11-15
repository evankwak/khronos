


/*
@author Evan Kwak
@date 2012 - 10 - 25

*/



#include <khronos/julian_day.hpp>
#include <sstream>
#include <khronos/gregorian_calendar.hpp>
#include <cmath>

using namespace std;




namespace khronos {
	/**	Jd default constructor.  Initialize to the current local time. */

	Jd::Jd()
		: jd_(0)
	{
		time_t nowTime = time(NULL);
		struct tm tmNow;
		localtime_s(&tmNow, &nowTime);
		jd_ = gregorian_to_jd(
			year_t(tmNow.tm_year) + 1900,
			month_t(tmNow.tm_mon) + 1,
			day_t(tmNow.tm_mday)
		);
	}

	std::string Jd::to_string() const
	{
		return std::string();
	}

	








}