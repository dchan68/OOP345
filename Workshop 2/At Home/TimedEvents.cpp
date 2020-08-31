// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 1/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <iomanip> 
#include "TimedEvents.h"


namespace sdds{

	void TimedEvents::startClock(){
		ts = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock(){
		te = std::chrono::steady_clock::now();
	}

	// function will record an event
	void TimedEvents::recordEvent(const char* msg){
		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(te - ts);
		if (nr < MAX_RECORDS)
		{
			this->events[nr].msg = msg;
			this->events[nr].units = "nanoseconds";
			this->events[nr].duration = ms;
			nr++;
		}
	}

	// this will report the set of times recorded
	std::ostream& operator<<(std::ostream& out, const TimedEvents& events){
		out << "--------------------------\n";
		out << "Execution Times:\n";
		out << "--------------------------\n";
		for (int i = 0; i < events.nr; i++)
			out << std::setw(20) << std::left
			<< events.events[i].msg << ' ' << std::setw(12) << std::right
			<< events.events[i].duration.count() << ' '
			<< events.events[i].units << '\n';
		out << "--------------------------\n";
		return out;
	}
}