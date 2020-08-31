// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: March 16, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "SongCollection.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>

namespace sdds{
    SongCollection::SongCollection(std::string filename){
        std::ifstream file(filename);

        if (!file)
            throw "Bad filename!";

        if (file){
            std::ifstream file(filename);
            std::string words;
            file.seekg(std::ios::beg);

            do{
                std::getline(file, words);

                if (file){
                    Song songs;

                    trim(songs.m_title = words.substr(0, 25));
                    trim(songs.m_artist = words.substr(25, 25));
                    trim(songs.m_album = words.substr(50, 25));

                    try{
                        songs.m_year = stoi(words.substr(75, 5));
                    }
                    catch (...){
                        songs.m_year = 0;
                    }

                    try{
                        songs.m_length = stoi(words.substr(80, 5));
                    }
                    catch (...){
                        songs.m_length = 0;
                    }

                    try{
                        songs.m_price = stod(words.substr(85, 5));
                    }
                    catch (...){
                        songs.m_price = 0;
                    }

                    songList.push_back(songs);
                }
            } while (file);
            file.close();
        }
    }

    void SongCollection::display(std::ostream& out) const{
        std::copy(songList.begin(), songList.end(), std::ostream_iterator<Song>(std::cout, "\n"));

        auto sum = std::accumulate(songList.begin(), songList.end(), 0u, [](const int& res, const Song& song) { return res + song.m_length; });

        //out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        printbar(out);
        std::string str = "Total Listening Time: ";
        str += std::to_string(sum / 3600); // hour
        str += ":";
        str += std::to_string((sum %= 3600) / 60); // minutes
        str += ":";
        str += std::to_string(sum % 60); // seconds
        out << "| " << std::setw(84) << str << " |\n";
    }

    void SongCollection::trim(std::string& str) const{
        size_t i = 0u;
        for (i = 0u; i < str.length() && str[i] == ' '; i++)
            ;
        str = str.substr(i);

        for (i = str.length(); i > 0 && str[i - 1] == ' '; i--)
            ;
        str = str.substr(0, i);
    }

    void SongCollection::sort(std::string field){
        if (field == "title")
            std::sort(songList.begin(), songList.end(), [](const Song& a, const Song& b) { return a.m_title < b.m_title; });
        else if (field == "album")
            std::sort(songList.begin(), songList.end(), [](const Song& a, const Song& b) { return a.m_album < b.m_album; });
        else if (field == "length")
            std::sort(songList.begin(), songList.end(), [](const Song& a, const Song& b) { return a.m_length < b.m_length; });
    }

    void SongCollection::cleanAlbum() {
        for_each(songList.begin(), songList.end(), [](Song& song) {if (song.m_album == "[None]") song.m_album = ""; });
    }

    bool SongCollection::inCollection(std::string artist) const{
        auto search = std::find_if(songList.begin(), songList.end(), [&artist](const Song& song) { return song.m_artist == artist; });
        return search != songList.end();
    }

    std::list<Song> SongCollection::getSongsForArtist(std::string artist) const{
        auto count = std::count_if(songList.begin(), songList.end(), [&artist](const Song& song) { return song.m_artist == artist; });
        std::list<Song> songs(count);

        std::copy_if(songList.begin(), songList.end(), songs.begin(), [&artist](const Song& song) { return song.m_artist == artist; });
        return songs;
    }

    std::ostream& operator<<(std::ostream& out, const Song& theSong){
        int min, sec;
        min = theSong.m_length / 60;
        sec = theSong.m_length - min * 60;

        out << "| " << std::setw(20) << std::left << theSong.m_title << " | "
            << std::setw(15) << std::left << theSong.m_artist << " | "
            << std::setw(20) << std::left << theSong.m_album << " | "
            << std::setw(6) << std::right;
        (theSong.m_year == 0 ? out << " " : out << theSong.m_year);
        out << " | " << min << ":";
        out << std::setfill('0') << std::setw(2) << sec << std::setfill(' ') << " | "
            << theSong.m_price << " |";

        return out;
    }
} 



