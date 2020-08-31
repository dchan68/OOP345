// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/9/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <ostream>
#include "Reservation.h"

namespace sdds{
	class ConfirmationSender{
		const sdds::Reservation** m_reservations = nullptr;
		size_t m_cnt = 0u;
	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res);
	};
}
#endif