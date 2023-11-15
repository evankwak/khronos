/**	@file Julian_to_jd.cpp
	@author Evan Kwak
	@date 2012-10-25

	Date and time library Julian conversion implementations.
	*/

#include <khronos/julian_calendar.hpp>
#include <cmath>
namespace khronos {

	/*
	
	function name julian_to_jd
	desc convertes julian date to julian day
	
	
	*/

	jd_t julian_to_jd(year_t year, month_t month, day_t day)
	{

		long long a = (14 - month) / 12;
		long long y = year + 4800 - a;
		long long m = month + 12 * a - 3;
		return day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083.5;
	}
	/*

	function name julian_to_jd
	desc convertes julian date to julian day
	

	*/
	jd_t julian_to_jd(year_t year, month_t month, day_t day, hour_t hour, minute_t minute, second_t second)
	{
		long long a = (14 - month) / 12;
		long long y = year + 4800 - a;
		long long m = month + 12 * a - 3;
		double jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083.5;

		double tod = (hour + minute / 60.0 + second / 3600.0) / 24.0;
		return jdn + tod;


	}

	/*

	function name julian_to_jd
	desc convertes julian day to julian calendar
	

	*/

	void jd_to_julian(jd_t jd, year_t& year, month_t& month, day_t& day)
	{

		

		long long a = floor( jd + 0.5);
		long long b = a + 1524;
		long long c = floor( (b - 122.1) / 365.25);
		long long d = floor(365.25 * c);
		long long e = floor((b - d) / 30.6001);

		if (e < 14)
		{
			month =floor( e - 1);
		}
		else
		{
			month =floor( e - 13);
		}

		if (month > 2) {
			year =floor( c - 4716);
		}
		else
		{
			year = floor( c - 4715);
		}

		day = b - d -floor(30.6001 * e);



	}


	/*

	function name julian_to_jd
	desc convertes julian day to julian calendar


	*/
	void jd_to_julian(jd_t jd, year_t& year, month_t& month, day_t& day,hour_t& hour,minute_t& minute,second_t& second)
		{


		 jd_to_julian(jd, year, month, day);
		
		 long long tod = (jd+0.5) - floor(jd+0.5 );

		 second_t secondsInDay = (tod * 24 * 60 * 60 + 0.5);

		 hour = secondsInDay / (60 * 60);

		 minute = fmod(secondsInDay / 60, 60);

		 second = ceil(secondsInDay-60 * floor(secondsInDay/60));




		}




};