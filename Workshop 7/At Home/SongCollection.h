// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: March 16, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef sdds_SongCollection_h
#define sdds_SongCollection_h

#include <list>
#include <string>
#include <vector>

void printbar(std::ostream& out); // w7_home

namespace sdds{
    struct Song{
        std::string m_artist{};
        std::string m_title{};
        std::string m_album{};
        double m_price{ 0 };
        int m_year{ 0 };
        int m_length{ 0 };
    };

    class SongCollection{
        std::vector<Song> songList;
        void trim(std::string& str) const;

    public:
        SongCollection(std::string);
        void display(std::ostream& out) const;
        void sort(std::string field);
        void cleanAlbum();
        bool inCollection(std::string artist) const;
        std::list<Song> getSongsForArtist(std::string artist) const;
    };

    std::ostream& operator<<(std::ostream& out, const Song& theSong);
} 
#endif
