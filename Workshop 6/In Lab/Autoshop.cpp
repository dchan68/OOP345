// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 3/4/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "Autoshop.h"
namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	Autoshop::~Autoshop(){
		for (auto& car : m_vehicles)
			delete car;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;

		for (auto& car_element : this->m_vehicles) {
			car_element->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const Autoshop& obj) {
		obj.display(os);
		return os;
	}
}