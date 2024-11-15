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

#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H

#include "mediaItem.h"
#include "settings.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>
#include <algorithm>

namespace seneca {
	struct TvEpisode
	{
		const TvShow* m_show{};
		unsigned short m_numberOverall{};
		unsigned short m_season{};
		unsigned short m_numberInSeason{};
		std::string m_airDate{};
		unsigned int m_length{};
		std::string m_title{};
		std::string m_summary{};
	};

	class TvShow : public MediaItem {
		string m_id;
		std::vector<TvEpisode> m_episodes;

		TvShow(const std::string& id, const std::string& title, unsigned short year,
			const std::string& summary);
	public:
		void display(std::ostream& out) const override;
		static TvShow* createItem(const std::string& strShow);

		template<typename Collection_t> 
		void addEpisode(Collection_t& col, const std::string& strEpisode) {
            if (strEpisode.empty() || strEpisode[0] == '#') {
                throw std::invalid_argument("Not a valid episode.");
            }

            std::istringstream stream(strEpisode);
            std::string id, epNumStr, seasonStr, epInSeasonStr, airDate, lengthStr, title, summary;

            std::getline(stream, id, ',');
            MediaItem::trim(id);

            std::getline(stream, epNumStr, ',');
            MediaItem::trim(epNumStr);

            std::getline(stream, seasonStr, ',');
            MediaItem::trim(seasonStr);

            std::getline(stream, epInSeasonStr, ',');
            MediaItem::trim(epInSeasonStr);

            std::getline(stream, airDate, ',');
            MediaItem::trim(airDate);

            std::getline(stream, lengthStr, ',');
            MediaItem::trim(lengthStr);

            std::getline(stream, title, ',');
            MediaItem::trim(title);

            std::getline(stream, summary);            
            MediaItem::trim(summary);

            auto it = std::find_if(col.begin(), col.end(), [&](const MediaItem* item) {
                return item && dynamic_cast<const TvShow*>(item)->m_id == id;
                });

            if (it == col.end()) return;

            TvEpisode episode;
            episode.m_show = dynamic_cast<const TvShow*>(*it);
            episode.m_numberOverall = static_cast<unsigned short>(std::stoi(epNumStr));
            episode.m_season = seasonStr.empty() ? 1 : static_cast<unsigned short>(std::stoi(seasonStr));
            episode.m_numberInSeason = static_cast<unsigned short>(std::stoi(epInSeasonStr));
            episode.m_airDate = airDate;
            episode.m_length = static_cast<unsigned int>(std::stoi(lengthStr)) * 60;
            episode.m_title = title;
            episode.m_summary = summary;

            dynamic_cast<TvShow*>(*it)->m_episodes.push_back(episode);
		}

		double getEpisodeAverageLength() const;
		std::list<std::string> getLongEpisodes() const;
	};
}

#endif