/*
Student Name: Daryan Chan
Student Number: 113973192
Student Email: dchan68@myseneca.ca
Date of Completion: 1/19/2020
I have done all the coding in this part my self and
only copied the code that my professor provided to complete the my workshop.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"

using namespace std;
unsigned int g_sysClock;

namespace sdds {
	unsigned Event::COUNTER = 1;
	Event::Event() {
		desc = nullptr;
	}

	Event::Event(const Event& copy) {
		*this = copy;
	}

	Event::~Event() {
		delete[] desc;
	}

	void Event::display() const {
		int hh = 0, mm = 0, ss = 0;
		hh = time / 3600;
		mm = (time / 60) % 60;
		ss = time % 60;
		if (desc == nullptr) {
			cout << setw(3) << setfill(' ') << COUNTER << ". " << "[ No Event ]\n";
		}
		else {
			cout << setw(3) << setfill(' ') << COUNTER << ". " << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << " -> " << desc << "\n";
		}
		COUNTER++;
	}

	Event& Event::operator=(const Event& copy) {
		if (this != &copy) {
			setDescription(copy.desc);
			time = copy.time;
		}
		return *this;
	}

	void Event::setDescription(char* description) {
		if (description != nullptr && description[0] != '\0') {
			int length = strlen(description);
			desc = new char[length + 1];
			strcpy(desc, description);
			time = g_sysClock;
		}
		else
			desc = nullptr;
	}
}
