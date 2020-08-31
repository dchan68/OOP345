// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/9/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <ostream>

namespace sdds{
	class Reservation{
		std::string m_id = "";
		std::string m_name = "";
		std::string m_email = "";
		size_t m_partysize = 0;
		size_t m_day = 0;
		size_t m_time = 0;
		void trim(std::string& str) const;

	public:
		Reservation() {}
		Reservation(const std::string& m_res);
		friend std::ostream& operator<<(std::ostream& out, const Reservation& res);
	};
}
#endif