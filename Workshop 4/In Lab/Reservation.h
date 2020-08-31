// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/5/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>

namespace sdds{
    class Reservation{
        std::string id;
        std::string name;
        std::string email;
        int partySize;
        int day;
        int hour;

    public:
        Reservation();
        Reservation(const std::string& m_res);
        std::string removeSpaces(std::string str);
        void display(std::ostream& os) const;

    };

    std::ostream& operator<<(std::ostream& out, const Reservation& reservation);

} 
#endif