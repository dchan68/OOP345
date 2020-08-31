// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 3/4/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <iomanip>
#include "Car.h"

namespace sdds{
	Car::Car(): m_maker{}, m_condition{}, m_topSpeed{ 0.0 }{

	}

	Car::Car(std::istream& is){
		size_t indexStart = 0;
		std::string temp = "";
		std::getline(is, temp);

		// This code will get rid of all whitespaces
		while (temp.find(" ") != std::string::npos){
			indexStart = temp.find(" ");
			temp.erase(indexStart, 1);
		}

		indexStart = temp.find(",");
		temp.erase(0, indexStart + 1);

		indexStart = temp.find(",");
		m_maker = temp.substr(0, indexStart);
		temp.erase(0, indexStart + 1);

		indexStart = temp.find(",");
		m_condition = temp.substr(0, indexStart);
		temp.erase(0, indexStart + 1);

		m_topSpeed = stoi(temp);
	}

	std::string Car::condition() const{
		std::string condition;

		if (m_condition == "n")
			condition = "new";	
		else if (m_condition == "b")
			condition = "broken";	
		else if (m_condition == "u")
			condition = "used";
		else 
			condition = "There is no matched condition existing";

		return condition;
	}

	double Car::topSpeed() const{
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const{
		out << "| " << std::right << std::setw(10) << m_maker << " | " << std::left << std::setw(6)
			<< condition() << " | " << std::setw(6) << std::fixed << std::setprecision(2)
			<< topSpeed() << " |";
	}

	std::ostream& operator<<(std::ostream& os, const Car& obj){
		obj.display(os);
		return os;
	}
}