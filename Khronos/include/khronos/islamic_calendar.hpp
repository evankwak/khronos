#pragma once


#include <khronos/def.hpp>
#include <khronos/calendar.hpp>
#include <khronos/julian_day.hpp>
#include <string>

/**	@file khronos/Islamic_calendar.hpp
	@author Evan Kwak
	@date 2012-10-25

	Islamic calendar class and functions.
	*/

namespace khronos {


	bool is_islamic_leapyear(year_t year);


	char const* islamic_month_name(month_t month);


	jd_t islamic_to_jd(year_t year, month_t month, day_t day);
	jd_t islamic_to_jd(year_t year, month_t month, day_t day, hour_t hour, minute_t minute, second_t second);
	constexpr jd_t ISLAMIC_EPOCH = 1'721'425.5;

	enum islamic_month_codes_long {
		Muharram =1 , Safar=2, RabialAwwal=3,
		RabiathThani=4, JumadaIUla=5, JumadatTania=6, Rajab=7, Shaban=8, Ramadan=9, Shawwal=10,
		DhulQadah=11 ,DhuIHijja=12
	};


};