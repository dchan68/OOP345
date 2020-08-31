// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/9/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <ostream>
#include "Reservation.h"

namespace sdds{

	class Restaurant{
		size_t m_currentDay = 0u;
		Reservation* m_reservations = nullptr;
		size_t m_cnt = 0u;
	public:
		//Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& cpy);
		Restaurant& operator=(const Restaurant& cpy);
		Restaurant(Restaurant&& src) noexcept;
		Restaurant& operator=(Restaurant&& src) noexcept;
		~Restaurant();
		size_t size() const { return m_cnt; } //added the function definition here because it was given me trouble on matrix when I put definition in cpp file.

		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif