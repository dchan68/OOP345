// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/18/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "SpellChecker.h"
#include <iomanip>
#include <string>
#include <fstream>

namespace sdds{
	SpellChecker::SpellChecker(){
		*m_badWords = "\0";
		*m_goodWords = "\0";
	}

	SpellChecker::SpellChecker(const char* filename){
		std::ifstream file(filename);
		if (file.is_open() == false){
			throw ("Bad file name!");
		}
		else { //else, file exits
			int lineCount = 0;

			std::string words;
			file.seekg(std::ios::beg);
			do{
				std::getline(file, words);

				if (file){
					if (words[0] != ' '){
						size_t spaceStart = 0;
						size_t spaceEnds = 0;

						spaceStart = words.find(' '); // count when the first space appear

						for (size_t i = spaceStart; i < words.size() && words[i] == ' '; i++)
						{
							spaceEnds = i;
						}
						trim(m_badWords[lineCount] = words.substr(0, spaceStart));
						trim(m_goodWords[lineCount] = words.substr(spaceEnds));
						lineCount++;
					}
				}
			} while (file);
			file.close();
		}
	}

	void SpellChecker::operator()(std::string& text) const{
		int n = sizeof(m_badWords) / sizeof(m_badWords[0]);
		int start = 0;

		for (int i = 0; i < n; i++){
			do {
				start = (int)text.find(m_badWords[i]);
				if (start >= 0){
					text.replace(start, m_badWords[i].length(), m_goodWords[i]);
				}
			} while (start != -1);
		}

		std::string::size_type pos = 0; 
		while ((pos = text.find("\r", pos)) != std::string::npos)
		{
			//text.erase ( pos, 2 );
			text.replace(pos, 1, "");
		}
	}

	void SpellChecker::trim(std::string& str) const{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}
}