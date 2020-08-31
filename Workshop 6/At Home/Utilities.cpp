// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 3/4/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"
#include<string.h>
#include<iostream>
#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
        std::string line;
        char type = '\0';
        char delim = '\0';

        std::getline(in, line);
        std::stringstream ss(line);
        ss >> type >> delim;

        if (ss) {
            if (type == 'c' || type == 'C')
                return new Car(ss);
            else if (type == 'r' || type == 'R')
                return new Racecar(ss);
            else
                throw type;
        }

        return nullptr;
    }
}