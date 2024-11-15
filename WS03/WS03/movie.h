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

#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include "mediaItem.h"
#include "settings.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace seneca {
	class Movie : public MediaItem {
		Movie(const std::string& title,
			const std::string& summary,
			unsigned short year);
	public:
		void display(std::ostream& out) const override;
		static Movie* createItem(const std::string& strMovie);
	};
}

#endif