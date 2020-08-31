// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 1/15/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Event.h"

using namespace std;
unsigned int g_sysClock;
namespace sdds{
	unsigned Event::COUNTER = 1;

	Event::Event() {
		desc[0] = '\0';
		time = 0;
	}

	void Event::display() const {
		int hh = 0, mm = 0, ss = 0;
		hh = time / 3600;
		mm = (time / 60) % 60;
		ss = time % 60;
		if (desc == nullptr || desc[0] == '\0') {
			cout << setw(3) << setfill(' ') << COUNTER << ". " << "[ No Event ]\n";
		}
		else {
			cout << setw(3) << setfill(' ') << COUNTER << ". " << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << " -> " << desc << "\n";
		}
		COUNTER++;
	}

	void Event::setDescription(char* des) {
		if (des != nullptr) {
			strcpy(desc, des);
			time = g_sysClock;
		}
		else {
			desc[0] = '\0';
			time = 0;
		}
	}
}

//extern static W1.exe