// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/18/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Movie.h"

namespace sdds {
    Movie::Movie() {
        mov_year = 0;
        mov_title = "";
        mov_desc = "";
    }

    const string& Movie::title() const {
        return mov_title;
    }

    Movie::Movie(const string& mov) {
        string title, year, desc;
        string str = mov;

        title = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        year = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        desc = str;

        // trim the whitespaces
        title.erase(title.find_last_not_of(' ') + 1);
        title.erase(0, title.find_first_not_of(' '));

        desc.erase(desc.find_last_not_of(' ') + 1);
        desc.erase(0, desc.find_first_not_of(' '));

        mov_title = title;
        mov_desc = desc;
        mov_year = stoi(year);
    }

    ostream& operator<<(ostream& os, const Movie& mov) {
        os << setw(40) << setfill(' ') << mov.mov_title << " | ";
        os << setw(4) << mov.mov_year << " | ";
        os << mov.mov_desc << '\n';
        return os;
    }
}