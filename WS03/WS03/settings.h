/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3
Full Name  : Janice Kang
Student ID#: 114461239
Email      : jkang108@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare that this submission is the result of my own work 
and I only copied the code that my professor provided to complete 
my workshops and assignments. This submitted piece of work has not been 
shared with any other student or 3rd party content provider.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

#include <cstdint>  // wow new stuff for uint16_t

namespace seneca {

	struct Settings {
		uint16_t m_maxSummaryWidth = 80;
		bool m_tableView = false;
	};

	extern Settings g_settings;
}

#endif