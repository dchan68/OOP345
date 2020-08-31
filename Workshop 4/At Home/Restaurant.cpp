// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/9/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Restaurant.h"

namespace sdds{
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt){
		this->m_reservations = new Reservation[cnt];
		this->m_cnt = cnt;
		for (auto i = 0u; i < cnt; ++i)
			this->m_reservations[i] = *reservations[i];
	}

	Restaurant::Restaurant(const Restaurant& cpy){
		*this = cpy;
	}

	Restaurant& Restaurant::operator=(const Restaurant& cpy){
		if (this != &cpy){
			m_currentDay = cpy.m_currentDay;
			m_cnt = cpy.m_cnt;

			delete[] this->m_reservations;
			this->m_reservations = new Reservation[m_cnt];
			for (auto i = 0u; i < m_cnt; ++i)
				this->m_reservations[i] = cpy.m_reservations[i];
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept{
		*this = std::move(src);
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept{
		if (this != &src){
			m_currentDay = src.m_currentDay;
			m_cnt = src.m_cnt;

			delete[] this->m_reservations;
			this->m_reservations = src.m_reservations;
			src.m_currentDay = 0;
			src.m_cnt = 0;
			src.m_reservations = nullptr;
		}
		return *this;
	}

	Restaurant::~Restaurant(){
		delete[] m_reservations;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& res){
		os << "--------------------------\n";
		os << "Fancy Restaurant\n";
		os << "--------------------------\n";
		if (res.m_cnt == 0)
			os << "The object is empty!\n";
		for (auto i = 0u; i < res.m_cnt; ++i)
			os << res.m_reservations[i];
		os << "--------------------------\n";
		return os;
	}
}