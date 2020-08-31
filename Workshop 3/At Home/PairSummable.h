// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/2/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include <iomanip>
#include <cstring>
#include <iostream>
#include "Pair.h"

using namespace std;
namespace sdds {
	template<typename K, typename V>
	class PairSummable : public Pair<K, V> {
		static V summation;
		static size_t widthMin;

	public:
		PairSummable() :Pair<K, V>() {}

		PairSummable(const K& key, const V& value) :Pair<K, V>(key, value) {
			if (widthMin < key.length()) {
				widthMin = key.length();
			}
		}
		
		static const V& getInitialValue() {
			return summation;
		}

		V sum(const K& key, const V& val) const {
			return(this->key() == key) ? this->value() + val : val;
		}

		void display(ostream& os) const {
			os << left << setw(widthMin);
			Pair<K, V>::display(os);
			os << right;
		}
	};
	
	template<>
	string PairSummable<string, string>::summation = "";

	template<typename K, typename V>
	size_t PairSummable<K, V>::widthMin = 0u;

	template<typename K, typename V>
	V PairSummable<K, V>::summation = 0u;

	template<>
	string PairSummable<string, string>::sum(const string& key, const string& value) const {
		string temp = "";
		if (PairSummable<string, string>::key() == key)
		{
			if (value == "") temp = this->value();
			else  temp = value + ", " + this->value();
		}
		else temp = value;
		return temp;
	}
}
#endif