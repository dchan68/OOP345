// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/9/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iomanip>
#include "Reservation.h"

namespace sdds{
	void Reservation::trim(std::string& str) const{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}

	Reservation::Reservation(const std::string& res){
		size_t posS = 0;
		size_t posE = res.find(':');
		this->trim(m_id = res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = res.find(',', posS);
		this->trim(m_name = res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = res.find(',', posS);
		this->trim(m_email = res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = res.find(',', posS);
		m_partysize = std::stoi(res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = res.find(',', posS);
		m_day = std::stoi(res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = res.find(',', posS);
		m_time = std::stoi(res.substr(posS, posE - posS));
	}

	std::ostream& operator<<(std::ostream& out, const Reservation& res){
		std::string email = "<" + res.m_email + ">";
		out << "Reservation " << res.m_id << ": "
			<< std::setw(10) << std::right << res.m_name << "  "
			<< std::setw(20) << std::left << email << std::right;
		if (6 <= res.m_time && res.m_time <= 9)
			out << "    Breakfast ";
		else if (11 <= res.m_time && res.m_time <= 15)
			out << "    Lunch ";
		else if (17 <= res.m_time && res.m_time <= 21)
			out << "    Dinner ";
		else
			out << "    Drinks ";
		out << "on day " << res.m_day << " @ " << res.m_time
			<< ":00 for " << res.m_partysize << " people.\n";
		return out;
	}
}