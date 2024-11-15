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

#include "book.h"

namespace seneca {

    Book::Book(const std::string& title, const std::string& author, const std::string& country,
        unsigned short year, double price, const std::string& summary)
        : MediaItem(title, summary, year), m_author(author), m_country(country), m_price(price) {}

    void Book::display(std::ostream & out) const
    {
        if (g_settings.m_tableView)
        {
            out << "B | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(2) << this->m_country << " | ";
            out << std::setw(4) << this->getYear() << " | ";
            out << std::left;
            if (g_settings.m_maxSummaryWidth > -1)
            {
                if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth)
                    out << this->getSummary();
                else
                    out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
            }
            else
                out << this->getSummary();
            out << std::endl;
        }
        else
        {
            size_t pos = 0;
            out << this->getTitle() << " [" << this->getYear() << "] [";
            out << m_author << "] [" << m_country << "] [" << m_price << "]\n";
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
            while (pos < this->getSummary().size())
            {
                out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
                pos += g_settings.m_maxSummaryWidth;
            }
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
                << std::setfill(' ') << '\n';
        }
	}

    Book* Book::createItem(const std::string& strBook) {
        if (strBook.empty() || strBook[0] == '#') {
            throw std::invalid_argument("Not a valid book.");
        }

        std::istringstream stream(strBook);
        std::string title, author, country, summary, yearStr, priceStr;
        unsigned short year;
        double price;

        std::getline(stream, author, ',');
        trim(author);

        std::getline(stream, title, ',');
        trim(title);

        std::getline(stream, country, ',');
        trim(country);

        std::getline(stream, priceStr, ',');
        trim(priceStr);
        price = std::stod(priceStr);

        std::getline(stream, yearStr, ',');
        trim(yearStr);
        year = std::stoi(yearStr);

        std::getline(stream, summary);
        trim(summary);

        return new Book(title, author, country, year, price, summary);
    }
}