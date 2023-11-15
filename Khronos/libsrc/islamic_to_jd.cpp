/**	@file Islamic_to_jd.cpp
	@author Evan Kwak
	@date 2023 10 25

	Islamic calendar conversion implementations.
	*/

#include <khronos/islamic_calendar.hpp>
namespace khronos {


	jd_t islamic_to_jd(year_t year, month_t month, day_t day)
	{
		// Calculate the Julian Date (JD) for the given Islamic date components.

		jd_t JDN = day + ceil(29.5 * (month - 1)) + (year - 1) * 354 + floor((3 + 11 * year) / 30);

		// Adjust the JD to the start of the Islamic calendar epoch (known as the "epoch offset").
	    // The Islamic JD epoch is 1948439.5 - 1 days before the standard JD epoch.
		return JDN += 1948439.5 - 1;


	}



	/*
	
	name:islamic_to_jd
	desc converts islamic date to jd
	
	*/

	jd_t islamic_to_jd(year_t year, month_t month, day_t day, hour_t hour, minute_t minute, second_t second)
	{

		// Calculate the JD for the date part (year, month, day) using the previous function.

		jd_t jdn = islamic_to_jd(year, month, day);
		// Calculate the time of day as a fraction of a day.

		tod_t tod = second + 60 * (minute + 60 * hour) / (24 * 60 * 60);

		// If the TOD is equal to or greater than 0.5 (midday or later), adjust it by subtracting 1 day.

		if (tod >= 0.5)
		{
			tod = tod - 1;
		}

		return jdn + tod;

	}





};
