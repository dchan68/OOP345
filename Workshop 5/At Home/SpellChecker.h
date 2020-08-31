// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

namespace sdds{
	class SpellChecker{
		std::string m_badWords[5];
		std::string m_goodWords[5];
	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
		void trim(std::string& str) const;
	};

} 
#endif
