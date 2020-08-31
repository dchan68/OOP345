// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 1/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iomanip>
#include <cstring>
#include <iostream>

namespace sdds {

	template<typename K, typename V>
	class Pair{
		K k_key;
		V v_value;

	public:
		Pair() : k_key {}, v_value {} {}

		Pair(const K& k, const V& v) : k_key{ k }, v_value{ v } {
		/*	k_key = k;
			v_value = v;*/
		}

		const K& key() const {
			return k_key;
		}

		const V& value() const {
			return v_value;
		}

		virtual void display(std::ostream& os) const {
			os << k_key << " : " << v_value << std::endl;
		}

		friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& t) {
		t.display(os);
		return os;
	    }
	};


}
#endif 