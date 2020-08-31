// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca	
// Date of completion: 3/11/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;
namespace sdds {

	struct Song {
		string m_artist;
		string m_title;
		double m_price;
		string m_album;
		string m_releaseYear;
		size_t m_length;
	};

	class SongCollection {
		vector<Song> m_song;

	public:
		SongCollection(const char* file);
		void display(std::ostream& out) const;
	};
	ostream& operator<<(ostream& out, const Song& theSong);
}
#endif
