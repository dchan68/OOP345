// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 1/15/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

namespace sdds{
	class Event
	{
		char desc[128];
		unsigned int time;
	public:
		static unsigned COUNTER;
		Event();
		void display() const;
		void setDescription(char*);
	};
}
#endif

