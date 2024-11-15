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

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "mediaItem.h"
#include "settings.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace seneca {
	class Book : public MediaItem {
		string m_author;
		string m_country;
		double m_price;

		Book(const std::string& title,
			const std::string& author,
			const std::string& country,
			unsigned short year,
			double price,
			const std::string& summary);

	public:
		void display(std::ostream& out) const override;
		static Book* createItem(const std::string& strBook);
	};
}

#endif