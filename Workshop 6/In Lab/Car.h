// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 3/4/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef sdds_Car_h
#define sdds_Car_h

#include <string>
#include <iostream>
#include "Vehicle.h"

namespace sdds{
	class Car : public Vehicle{
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;

	public:
		Car();
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		friend std::ostream& operator<<(std::ostream& os, const Car& obj);
	};
}
#endif
