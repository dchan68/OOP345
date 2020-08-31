// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 1/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#include <fstream>
#include <iostream>
#include "RecordSet.h"

using namespace std;

namespace sdds {
	RecordSet::RecordSet() {
		this->setEmpty();
	}

	RecordSet::RecordSet(const char* filename) {
		counter = 0;
		string tempString;
		ifstream in;
		in.open(filename);
		if (!in.is_open()) {
			cout << "File is not open" << endl;
			this->setEmpty();
		}
		else {
			while (getline(in, tempString, ' ')) {
				counter++;
			}
			in.close();
		}
		in.open(filename);
		s_array = new string[counter];
		if (!in.is_open()) {
			cout << "File is not open" << endl;
			this->setEmpty();
		}
		else {
			while (in.good()) {
				for (unsigned long int i = 0; i < counter; i++) {
					getline(in, s_array[i], ' ');
				}
			}
		}
	}

	RecordSet::RecordSet(const RecordSet& copy) {
		this->setEmpty();
		*this = copy;
	}
	
	RecordSet::~RecordSet() {
		delete[] s_array;
	}

	RecordSet& RecordSet::operator=(const RecordSet& passedObject) {
		if (this != &passedObject) {
			delete[] s_array;
			counter = passedObject.counter;
			if (passedObject.s_array != nullptr) {
				s_array = new string[passedObject.counter];
				for (unsigned int i = 0; i < counter; i++) {
					s_array[i].assign(passedObject.s_array[i]);
				}
			}
			else {
				s_array = nullptr;
			}
		}
		return *this;
	}

	size_t RecordSet::size() const {
		return counter;
	}

	string RecordSet::getRecord(size_t index) {
		string strToReturn;
		if (s_array == nullptr) {
			strToReturn = string();
		}
		else {
			strToReturn = s_array[index];
		}
		return strToReturn;
	}

	void RecordSet::setEmpty() {
		s_array = nullptr;
		counter = 0;
	}
}