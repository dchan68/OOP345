// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/2/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include <iomanip>
#include <cstring>
#include <iostream>
#include "Set.h"

namespace sdds {
	template<typename T, size_t N, typename K, typename V>
	class SetSummable :public Set<T, N> {
	public:
		SetSummable():Set<T, N>() {}

		V accumulate(const K& key) const {
			V item;
			item = this->operator[](0).getInitialValue();
			for (size_t i = 0; i < this->size(); i++) {
				item = (this->operator[](i)).sum(key, item);
			}
			return item;
		}
	};
}
#endif