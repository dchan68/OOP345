// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 3/4/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <iomanip>
#include "Car.h"

namespace sdds{
    Car::Car(std::istream& is){
        std::string temp;

        std::getline(is, temp, ',');
        m_maker = trim(temp);

        std::getline(is, temp, ',');
        trim(temp);

        if (temp == "" || temp == "n")
            m_condition = "new";
        else if (temp == "b")
            m_condition = "broken";
        else if (temp == "u")
            m_condition = "used";
        else
            throw "Invalid record!";
        

        std::getline(is, temp, ',');

        try{
            m_topSpeed = std::stoi(temp);
        }
        catch (...){
            throw "Invalid record!";
        }
    }

    std::string Car::condition() const{
        return m_condition;
    }

    double Car::topSpeed() const{
        return m_topSpeed;
    }

    void Car::display(std::ostream& out) const{
        out << "| " << std::setw(10) << m_maker
            << " | " << std::setw(6) << std::left << this->condition()
            << " | " << std::setw(6) << std::setprecision(2) << std::fixed << std::right << this->topSpeed() << " |";
    }

    std::string& Car::trim(std::string& str){
        while (str.length() > 0 && str[0] == ' ')
            str.erase(0, 1);

        while (str.length() > 0 && str[str.length() - 1] == ' ')
            str.erase(str.length() - 1, 1);

        return str;
    }
}