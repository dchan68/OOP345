// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/5/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include "Reservation.h"
#include <algorithm>
#include <iomanip>
#include <string>

namespace sdds {
    std::string Reservation::removeSpaces(std::string str) {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }

    Reservation::Reservation(const std::string& m_res) {
        std::string str;
        //note to self: size_type will hold the size of any string. Almost like int but size_type is better
        std::string::size_type start;
        std::string::size_type end;

        //removeSpaces() will removes spaces in a string.
        /* note to self
        int main(){
              char str[] = "g  eeks   for ge  eeks  ";
              removeSpaces(str);
              cout << str;
              return 0;
         }
         output: geeksforgeeeks
        */
        /*
        substr(pos, pos+count) returns only a part of a string that you choose. pos = position of first character. post+count is how many 
        characters you want past the pos.
        ex: std::string a = "0123456789abcdefghij";
            std::string sub1 = a.substr(10);
            std::cout << sub1 << '\n';
            std::string sub2 = a.substr(5, 3);
            std::cout << sub2 << '\n';

            output: abcdefghij        
                    567
        */
        //note to self: read importantNotes.txt for more info
        str = removeSpaces(m_res);
        id = str.substr(0, 7);
        start = str.find(':') + 1;
        end = str.find(',');
        name = str.substr(start, end - start);
        str.erase(0, end + 1);
        //set i<4 because we want email, # of ppl, day, and time and in data.txt, that's where those infos corresponds to in the columns.
        //first column after the comma is email, hence i == 0. 2nd column is partySize, etc
        for (int i = 0; i < 4; i++){
            end = str.find(',') + 1;

            if (i == 0){
                email = str.substr(0, end - 1);
            }
            else if (i == 1){
                //stoi takes a string as an argument and returns in values. Note to self: Read importantNotes.txt for more info
                partySize = std::stoi(str.substr(0, end - 1));
            }
            else if (i == 2){
                day = std::stoi(str.substr(0, end - 1));
            }
            else if (i == 3){
                hour = std::stoi(str);
            }
            str.erase(0, end);
        }
    }

    void Reservation::display(std::ostream& os) const{
        std::cout << "Reservation " << id << ": "
            << std::setw(10) << std::right << name << "  "
            << std::setw(20) << std::left << "<" + email + ">"
            << "    ";
        if (6 <= hour && hour <= 9){
            std::cout << "Breakfast";
        }
        else if (11 <= hour && hour <= 15){
            std::cout << "Lunch";
        }
        else if (17 <= hour && hour <= 21){
            std::cout << "Dinner";
        }
        else{
            std::cout << "Drinks";
        }
        std::cout << " on day " << day << " @ " << hour << ":00"
            << " for " << partySize << " people." << std::endl;
    }

    std::ostream& operator<<(std::ostream& out, const Reservation& res){
        res.display(out);
        return out;
    }
} // namespace sdds

