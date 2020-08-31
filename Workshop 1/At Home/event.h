/*
Student Name: Daryan Chan
Student Number: 113973192
Student Email: dchan68@myseneca.ca
Date of Completion: 1/19/2020
I have done all the coding in this part my self and
only copied the code that my professor provided to complete the my workshop.
*/

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned int g_sysClock;
namespace sdds
{
	class Event {
		char* desc;
		unsigned int time;
	public:
		static unsigned COUNTER;
		Event();
		~Event();
		Event(const Event& copy);
		Event& operator=(const Event&);
		void display() const;
		void setDescription(char*);
	};
}
#endif