// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/9/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <utility>
#include "ConfirmationSender.h"

namespace sdds{
	ConfirmationSender::ConfirmationSender() {}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& cpy){
		*this = cpy;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cpy){
		if (this != &cpy){
			this->m_cnt = cpy.m_cnt;
			delete[] this->m_reservations;

			this->m_reservations = new const Reservation* [m_cnt];
			for (auto i = 0u; i < m_cnt; ++i)
				this->m_reservations[i] = cpy.m_reservations[i];
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept{
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept{
		if (this != &src){
			this->m_cnt = src.m_cnt;
			delete[] this->m_reservations;

			this->m_reservations = src.m_reservations;
			src.m_reservations = nullptr;
			src.m_cnt = 0;
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender(){
		delete[] m_reservations;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
		bool found = false;
		for (auto i = 0u; i < m_cnt && found == false; ++i)
			if (&res == m_reservations[i])
				found = true;

		if (found == false){
			const sdds::Reservation** tmp = nullptr;
			tmp = new const Reservation * [m_cnt + 1];
			for (auto i = 0u; i < m_cnt; ++i)
				tmp[i] = m_reservations[i];
			tmp[m_cnt] = &res;
			++m_cnt;
			delete[] m_reservations;
			m_reservations = tmp;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
		for (auto i = 0u; i < m_cnt; ++i)
			if (&res == m_reservations[i])
				m_reservations[i] = nullptr;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender){
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";
		if (sender.m_cnt == 0)
			os << "The object is empty!\n";
		for (auto i = 0u; i < sender.m_cnt; ++i)
			if (sender.m_reservations[i] != nullptr)
				os << *(sender.m_reservations[i]);
		os << "--------------------------\n";
		return os;
	}
}