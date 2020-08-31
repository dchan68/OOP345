// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/13/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;
	public:
		Book();
		~Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		
		Book(const std::string& strBook);

		friend std::ostream& operator<<(std::ostream& out, const Book& book);
	};
}

#endif