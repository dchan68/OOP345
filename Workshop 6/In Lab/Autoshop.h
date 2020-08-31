// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 3/4/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef sdds_Autoshop_h
#define sdds_Autoshop_h

#include <vector>
#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		~Autoshop();
		void display(std::ostream& out) const;
		friend std::ostream& operator<<(std::ostream& os, const Autoshop& obj);
	};
}
#endif
