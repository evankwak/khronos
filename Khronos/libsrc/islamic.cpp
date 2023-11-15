/**	@file Islamic.cpp
	
	/*
@author Evan Kwak
@date 2023 - 10 - 25

*/



 


#include <khronos/islamic_calendar.hpp>
namespace khronos {

	/*

	function name  is_islamic_leapyear(year_t year)
	desc checks if islamic month is a leap year


	*/
	bool is_islamic_leapyear(year_t year)
	{
		return (11 * year + 14) % 30 < 11;

	}

	/*
	name = islamic_month_name
	desc = returns islamic month name
	
	*/


	char const* islamic_month_name(month_t month) {
		char const* const islamicNames[13] = {
		   "",
			"Muharram", "Safar", "Rabi'al-Awwal",
	   "Rabi'ath-Thani", "Jumada I-Ula", "Jumada t-Tania", "Rajab", "Sha'ban", "Ramadan", "Shawwal",
	   "Dhu I-Qa'da", "Dhu I-Hijja"
		};


		return islamicNames[month];
	}



	

};
