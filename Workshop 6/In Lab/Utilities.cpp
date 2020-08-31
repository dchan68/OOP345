// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 3/4/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"
#include<string>
#include<iostream>
#include <sstream>

using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		size_t pos;
		size_t end_pos;
		std::string line;

		Vehicle* temp = nullptr;

		getline(in, line);

		if (!line.empty()) {

			pos = line.find_first_not_of(' ');
			end_pos = line.find_last_not_of(' ');
			line = line.substr(pos, end_pos - pos + 1);

			if (line.at(0) == 'c' || line.at(0) == 'C') {
				std::stringstream record(line);
				temp = new Car(record);
			}
		}
		return temp;
	}
}