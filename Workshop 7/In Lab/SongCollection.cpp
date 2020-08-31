// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca	
// Date of completion: 3/11/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "SongCollection.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <algorithm> 
#include <numeric>

namespace sdds{

	SongCollection::SongCollection(const char* file) {
		ifstream inFile(file);
		string line;

		if (inFile.fail() || string(file) != "songs.txt") 
			throw string("filename is incorrect");

		else {
			while (getline(inFile, line)) {

				size_t pos;
				size_t end_pos;

				Song temp_song;
				temp_song.m_title = (line.substr(0, 24));
				pos = temp_song.m_title.find_first_not_of(' ');
				end_pos = temp_song.m_title.find_last_not_of(' ');
				temp_song.m_title = temp_song.m_title.substr(pos, end_pos - pos + 1);

				temp_song.m_artist = (line.substr(24, 25));
				pos = temp_song.m_artist.find_first_not_of(' ');
				end_pos = temp_song.m_artist.find_last_not_of(' ');
				temp_song.m_artist = temp_song.m_artist.substr(pos, end_pos - pos + 1);

				temp_song.m_album = (line.substr(50, 25));
				pos = temp_song.m_album.find_first_not_of(' ');
				end_pos = temp_song.m_album.find_last_not_of(' ');
				temp_song.m_album = temp_song.m_album.substr(pos, end_pos - pos + 1);

			    temp_song.m_price = stod(line.substr(85, 5));
				temp_song.m_releaseYear = (line.substr(75, 7));
				temp_song.m_length = stoi((line.substr(80, 5)));

				m_song.push_back(temp_song);
			}
		}
	}

	void SongCollection::display(std::ostream& out) const {
		for_each(m_song.begin(), m_song.end(), [&](const Song song) {out << song; });
	}

	ostream& operator<<(ostream& out, const Song& theSong) {
		auto SongPlaytime = [](int seconds) {

			std::string time;
			int mins;

			mins = seconds / 60;

			time = to_string(int(mins % 60));
			time += ":";
			time += int(seconds % 60) < 10 ? "0" + to_string(int(seconds % 60)) : to_string(int(seconds % 60));

			return time;
		};

		out << "| " << std::left << std::setw(20) << theSong.m_title;
		out << " | " << std::left << std::setw(15) << theSong.m_artist;
		out << " | " << std::left << std::setw(20) << theSong.m_album;
		out << " | " << std::right << std::setw(6) << theSong.m_releaseYear;
		out << " | " << SongPlaytime(theSong.m_length);
		out << " | " << std::setprecision(2) << std::fixed << theSong.m_price << " |" << endl;

		return out;
	}
}