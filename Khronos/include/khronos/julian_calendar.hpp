#pragma once

/**	@file khronos/julian_calendar.hpp
	@author Evan Kwak
	@date 2012-10-25

	Julian calendar functions and class declaration.
	*/


#include <khronos/def.hpp>
#include <khronos/calendar.hpp>
#include <khronos/julian_day.hpp>

#include <string>

namespace khronos {

	constexpr int operator"" _BC(unsigned long long gregorianYear) {

		return 1 - (int)gregorianYear;

	}

	constexpr jd_t JULIAN_EPOCH = 1'721'423.5;
	constexpr bool is_julian_leapyear(year_t year)
	{
		if (year % 4 == 0) {
			return true;
		}
		return false;
	}





	//get info from calendar.hpp
	constexpr day_t julian_days_in_month(month_t month, bool isLeapYear) {
		return civil::days_in_month(month, isLeapYear);


	}
	constexpr char const* julian_month_name(month_t month) {
		return civil::month_name_long(month);
	}

	constexpr char const* julian_short_month_name(month_t month) {
		return civil::month_name_short(month);
	}




	//call the functions
	void jd_to_julian(jd_t jdn, year_t& year, month_t& month, day_t& day);
	jd_t julian_to_jd(year_t year, month_t month, day_t day);
	jd_t julian_to_jd(year_t year, month_t month, day_t day, hour_t hour, minute_t minute, second_t second);
	void jd_to_julian(jd_t jd, year_t& year, month_t& month, day_t& day, hour_t& hour, minute_t& minute, second_t& second);
	//create the julian class
	class Julian {
		year_t		year_ = 0;
		month_t		month_ = 0;
		day_t		day_ = 0;

		hour_t hour_ = 0;

		minute_t minute_ = 0;

		second_t second_ = 0;

		void from_jd(jd_t jd) { jd_to_julian(jd, year_, month_, day_); }
		jd_t to_jd() const { return julian_to_jd(year_, month_, day_); }




		//jd_t to_jd() const{ return gregorian_to_jd(year_, month_, day_,hour_,minute_,second_); }
	public:
		Julian();


		/*! Get the year.
			\return Astronomical year. */
		constexpr year_t  year() const { return year_; }





		/*! Get the month.
			\return Month number [1..12] */
		constexpr month_t month() const { return month_; }


		/*! Get the day of the month.
			\return Day of month number [1..31]. */
		constexpr day_t   day() const { return day_; }

		constexpr hour_t hour() const { return hour_; }
		constexpr minute_t minute() const { return minute_; }
		constexpr second_t second() const { return second_; }



		/*! Construct a Julian calendar date from year,month,day,[hour,minute,second]
			\param year [in] Astronomical year.
			\param month [in] Month number [1..12]
			\param day [in] Day of month [1..31]
			\param hour [in] 24-hour of the day [0..23]
			\param minute [in] minute of the hour [0..59]
			\param second [in] second of the minute [0..59]
			*/
		constexpr Julian(year_t year, month_t month, day_t day) : year_(year), month_(month), day_(day) {}

		constexpr Julian(year_t year, month_t month, day_t day, hour_t hour, minute_t minute, second_t second) : year_(year), month_(month), day_(day), hour_(hour), minute_(minute), second_(second) {}

		Julian(Jd const& jd) { from_jd(jd.jd()); }


		//std::string to_string() const;


		/**	Implicit cast to Jd class. */
		operator Jd () const { return Jd(to_jd()); }


		/**	Assign and convert from Jd type to Julian type. */
		Julian& operator = (Jd const& jd) {
			from_jd(jd.jd());
			return *this;
		}
		Julian operator+(const day_t other);
	};

	//function calls
	year_t  year(Julian g);
	month_t  month(Julian g);
	day_t  day(Julian g);
	hour_t  hour(Julian g);
	minute_t  minute(Julian g);
	second_t second(Julian g);


};
