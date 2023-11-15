/*
khronos\gregorian_to_jdn.cpp
(c) Garth Santor
Created: 2015-09-22
Last Updated: 2015-09-22
Edited By Evan Kwak
Khronos library 'gregorian::to_jdn' implementation.
*/

#include <khronos/gregorian_calendar.hpp>
#include <khronos/timeofday.hpp>

#include <khronos/gregorian_calendar.hpp>


namespace khronos {

	/**	Real-number implementation. */
	jd_t greg2jd_real(year_t year, month_t month, day_t dayOfMonth) {
		long long y = year - 1;
		return
			GREGORIAN_EPOCH - 1
			+ 365 * y
			+ floor(y / 4.0)
			- floor(y / 100.0)
			+ floor(y / 400.0)
			+ floor(((367.0 * month - 362.0) / 12.0)
				+ ((month <= 2)
					? 0
					: (is_gregorian_leapyear(year) ? -1 : -2)))
			+ dayOfMonth;
	}


	/**	Integer implementation (wikipedia). */
	constexpr jd_t greg2jd_integer(year_t year, month_t month, day_t day) {
		long long a = (14 - month) / 12;
		long long y = year + 4800 - a;
		long long m = month + 12 * a - 3;
		return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045 - 0.5;
	}

	jd_t gregorian_to_jd(year_t year, month_t month, day_t day) {
		assert(year > -4800 && "Minimum year is 4800 BCE");
		assert(month >= 1 && "Minimum month is January = 1");
		assert(month <= 12 && "Maximum month is December = 12");
		assert(day >= 1 && "Minimum day of the month is 1");
		assert(day <= 31 && "Maximum day of the month is 31");
		assert(khronos::greg2jd_integer(year, month, day) == khronos::greg2jd_real(year, month, day));
		return khronos::greg2jd_integer(year, month, day);
	}
	

	/*

	function name gregorian_to_jd
	desc convertes gregorian calendar to jd


	*/

	jd_t gregorian_to_jd(year_t year, month_t month, day_t day, hour_t hour, minute_t minute, second_t second)
	{


		jd_t jda = gregorian_to_jd(year, month, day);

		jd_t todo = tod(hour, minute, second);

		return jda + todo;




	}



	/*!	Convert a Julian Day Number to the Proleptic Gregorian Calendar
		\param year [in] Astronomical year (1 CE = 1, 1 BCE = 0, 2 BCE = -1, etc.)
		\param month [in] 1..12
		\param day [in] 1..31
	*/
	void jd_to_gregorian_real(jd_t jd, year_t& year, month_t& month, day_t& day) {
		assert(jd >= -31738.5 && "Minimum convertible date not provided.");
		using namespace utility;

		double wjd, depoch, quadricent, dqc, cent, dcent, quad, dquad, yindex, yearday, leapadj;
		wjd = floor(jd - 0.5) + 0.5;
		depoch = wjd - GREGORIAN_EPOCH;
		quadricent = floor(depoch / 146097.0);
		dqc = mod(depoch, 146097.0);
		cent = floor(dqc / 36524.0);
		dcent = mod(dqc, 36524);
		quad = floor(dcent / 1461.0);
		dquad = mod(dcent, 1461.0);
		yindex = floor(dquad / 365.0);
		year = (year_t)floor((quadricent * 400.0) + (cent * 100.0) + (quad * 4.0) + yindex);
		if (!((cent == 4.0) || (yindex == 4.0)))
			++year;

		yearday = wjd - gregorian_to_jd(year, 1, 1);
		leapadj = ((wjd < gregorian_to_jd(year, 3, 1)) ? 0 : (is_gregorian_leapyear(year) ? 1 : 2));
		month = static_cast<month_t>(floor((((yearday + leapadj) * 12) + 373) / 367));
		day = static_cast<day_t>((wjd - gregorian_to_jd(year, month, 1)) + 1);
	}







	// integer implementation
	inline void jd_to_gregorian_integer(jd_t jd, year_t& year, month_t& month, day_t& day) {
		assert(jd >= -31738.5 && "Minimum convertible date not provided.");
		jd = floor(jd - 0.5) + 0.5;
		long long j = static_cast<long long>(jd + 0.5) + 32044;
		long long g = j / 146097;
		long long dg = j % 146097;
		long long c = (dg / 36524 + 1) * 3 / 4;
		long long dc = dg - c * 36524;
		long long b = dc / 1461;
		long long db = dc % 1461;
		long long a = (db / 365 + 1) * 3 / 4;
		long long da = db - a * 365;
		long long y = g * 400 + c * 100 + b * 4 + a;
		long long m = (da * 5 + 308) / 153 - 2;
		year = y - 4800 + (m + 2) / 12;
		month = (m + 2) % 12 + 1;
		day = static_cast<day_t>(da - (m + 4) * 153 / 5 + 123);
	}




	/*

	function name jd_to_gregorian
	desc convertes julian day to gregorian calendar


	*/



	void jd_to_gregorian(jd_t jd, year_t& year, month_t& month, day_t& day) {
		assert(jd >= -31738.5 && "Minimum convertable date not provided.");

		jd = floor(jd - 0.5) + 0.5;
		long long a = static_cast<long long>(jd + 0.5) + 32044;
		long long b = (4 * a + 3) / 146097;
		long long c = a - b * 146097 / 4;
		long long d = (4 * c + 3) / 1461;
		long long e = c - 1461 * d / 4;
		long long m = (5 * e + 2) / 153;
		day = static_cast<day_t>(e - (153 * m + 2) / 5 + 1);
		month = static_cast<month_t>(m + 3 - 12 * (m / 10));
		year = b * 100 + d - 4800 + m / 10;



#if defined( _DEBUG )
		{
			year_t y;
			month_t m;
			day_t d;
			detail::jd_to_gregorian_integer(jd, y, m, d);
			assert(year == y);
			assert(month == m);
			assert(day == d);
			detail::jd_to_gregorian_real(jd, y, m, d);
			assert(year == y);
			assert(month == m);
			assert(day == d);
		}
#endif


	}




	/*

	function name hms
	desc convertes  jd to hours minute seconds


	*/
	void hms(jd_t tod, hour_t& hours, minute_t& minutes, second_t& seconds)
	{
		jd_t secondsCalc = floor(tod * 24 * 60 * 60+0.5);

		hours = secondsCalc / (60 * 60);
		minutes = fmod(seconds / 60, 60);

		seconds = fmod(secondsCalc, 60);

	}
	void jd_to_gregorian(jd_t jd, year_t& year, month_t& month, day_t& day, hour_t& hour, minute_t& minute, second_t& second) {

		jd_to_gregorian(jd, year, month, day);

		hms(jd, hour, minute, second);



	}
};
