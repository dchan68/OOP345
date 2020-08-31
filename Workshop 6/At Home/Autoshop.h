// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 3/8/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef sdds_Autoshop_h
#define sdds_Autoshop_h

#include <vector>
#include <iostream>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;

	public:
        Autoshop& operator+=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        Autoshop() {};
        ~Autoshop();

        template <typename T>
        void select(T condition, std::list<const Vehicle*>& vehicles)
        {
            for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++)
            {
                if (condition(*it))
                {
                    vehicles.push_back(*it);
                }
            }
        }
    };
}
#endif
