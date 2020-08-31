// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 1/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <string>

namespace sdds {
	class RecordSet {
		unsigned long int counter;
		std::string* s_array;
	
	public:
		RecordSet();
		RecordSet(const char*);
		RecordSet(const RecordSet&);
		RecordSet& operator=(const RecordSet&);
		~RecordSet();
		size_t size() const;
		std::string getRecord(size_t);
		void setEmpty();
		RecordSet(RecordSet&&);
		RecordSet& operator=(RecordSet&&);
	};
}
#endif
