#pragma once

/*
khronos\timeofday.hpp
@author Evan Kwak
	@date 2012-10-25
Last Updated: 2015-09-22

Khronos library 'time-of-day' declarations.
*/


#include <khronos/def.hpp>


namespace khronos {
	// LITERALS
	/* UDL - converts an 'AM' hour to 'military' hour. */


	constexpr int operator"" _am(unsigned long long hours) {
		if (hours == 12) {
			return (hour_t)hours - 12;
		}
		else
			return (hour_t)hours;

	}

	/* UDL - converts an 'PM' hour to 'military' hour. */
	constexpr int operator"" _pm(unsigned long long hours) {
		if (hours == 12) {
			return (hour_t)hours;
		}
		else
			return (hour_t)hours + 12;

	}

	/* Seconds per day. */


	constexpr second_t SECONDS_PER_DAY = 24 * 60 * 60;

	/* H:M:S.S to time-of-day [0.0..1.0) */

	constexpr tod_t tod(hour_t hour, minute_t minute, second_t second) {


		return (second + 60 * (minute + 60 * hour)) / SECONDS_PER_DAY;


	}









} // end-of-namespace khronos
