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
		while (!m_vehicles.empty()){
			delete m_vehicles.back();
			m_vehicles.pop_back();
		}
	}

	void Autoshop::display(std::ostream& out) const{
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++){
			(*it)->display(out);
			out << std::endl;
		}
		out << "--------------------------------\n";
	}
}