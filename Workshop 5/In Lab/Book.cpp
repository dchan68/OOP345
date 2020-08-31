// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/13/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include"Book.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
namespace sdds{
	Book::Book(){}

	Book::~Book(){}

	const string& Book::title() const{
		return m_title;
	}

	const string& Book::country() const{
		return m_country;
	}

	const size_t& Book::year() const{
		return m_year;
	}

	double& Book::price(){
		return m_price;
	}

	Book::Book(const std::string& textbook){

		size_t indexStart = 0;
		string str = textbook;
		indexStart = str.find(',');
		m_author = str.substr(0, indexStart);
		auto start = m_author.find_first_not_of(' ');
		auto end = m_author.find_last_not_of(' ');
		m_author = m_author.substr(start, end - start + 1); // will delete unwanted space
		str.erase(0, indexStart + 1);


		indexStart = str.find(',');
		m_title = str.substr(0, indexStart);
		start = m_title.find_first_not_of(' ');
		end = m_title.find_last_not_of(' ');
		m_title = m_title.substr(start, end - start + 1);
		str.erase(0, indexStart + 1);

		indexStart = str.find(',');
		m_country = str.substr(0, indexStart);
		start = m_country.find_first_not_of(' ');
		end = m_country.find_last_not_of(' ');
		m_country = m_country.substr(start, end - start + 1);
		str.erase(0, indexStart + 1);

		indexStart = str.find(',');
		m_price = stod(str.substr(0, indexStart));
		str.erase(0, indexStart + 1);

		indexStart = str.find(',');
		m_year = stoi(str.substr(0, indexStart));
		str.erase(0, indexStart + 1);

		m_description = str;
		start = m_description.find_first_not_of(' ');
		end = m_description.find_last_not_of(' ');
		m_description = m_description.substr(start, end - start + 1);
	}

	ostream& operator<<(std::ostream& os, const Book& book) {
		os << std::setw(20) << std::right << book.m_author << " | "
			<< std::setw(22) << std::right << book.m_title << " | "
			<< std::setw(5) << book.m_country << " | "
			<< std::setw(4) << book.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | "
			<< book.m_description << std::endl;
		return os;
	}
}