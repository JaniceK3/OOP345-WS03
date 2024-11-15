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

#include "movie.h"

using namespace std;

namespace seneca {

    Movie::Movie(const std::string& title,
        const std::string& summary,
        unsigned short year) : MediaItem(title, summary, year) {}

	void Movie::display(std::ostream& out) const {
        if (g_settings.m_tableView)
        {
            out << "M | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(9) << this->getYear() << " | ";
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
            out << this->getTitle() << " [" << this->getYear() << "]\n";
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

    Movie* Movie::createItem(const std::string& strMovie) {
        if (strMovie.empty() || strMovie[0] == '#') {
            throw std::invalid_argument("Not a valid book.");
        }

        std::istringstream stream(strMovie);
        std::string title, summary, yearStr;
        unsigned short year;

        std::getline(stream, title, ',');
        trim(title);

        std::getline(stream, yearStr, ',');
        trim(yearStr);
        year = std::stoi(yearStr);

        std::getline(stream, summary);
        trim(summary);

        return new Movie(title, summary, year);
    }
}