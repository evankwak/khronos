/*
@author Evan Kwak
@date 2012 - 10 - 25

*/

#include <khronos/gregorian_calendar.hpp>

#include <sstream>

namespace khronos {
	/**	Gregorian default constructor.  Initialize to the current local time. */
	Gregorian::Gregorian() {
		time_t nowTime = time(NULL);
		struct tm tmNow;
		localtime_s(&tmNow, &nowTime);
		year_ = year_t(tmNow.tm_year) + 1900;
		month_ = month_t(tmNow.tm_mon) + 1;
		day_ = day_t(tmNow.tm_mday);
	}




	/** Print the Gregorian Date as a string. */
	//std::string Gregorian::to_string() const {
	//	std::ostringstream oss;
	//
	//	// day of week
	//	//oss << civil::day_name(day_of_week(to_jd())) << ", ";
	//
	//	oss << gregorian_month_name(month_) << ' ' << (unsigned)day_ << ' ';
	//	if (year_ <= 0)
	//		oss << (-year_ + 1) << " BCE";
	//	else
	//		oss << year_ << " CE";
	//
	//	return oss.str();
	//}



	


	year_t  year(Gregorian g) {

		return g.year();
	}

	month_t month(Gregorian g) {
		return g.month();

	}

	day_t day(Gregorian g) {
		return g.day();
	}

	hour_t hour(Gregorian g) {
		return g.hour();
	}

	minute_t minute(Gregorian g) {
		return g.minute();

	}

	second_t second(Gregorian g) {
		return  g.second();
	}


}
