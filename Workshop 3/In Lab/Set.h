// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 1/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <cstring>

namespace sdds{
	template<typename T, int N>

	class Set{
		T arr[N];
		int count;
	public:
		Set() : arr{}, count{ 0 } {
			
		}

		size_t size() const {
			return count;
		}

		const T& operator[](size_t pos) const {
			return arr[pos];
		}

		void operator+=(const T& i) {
			if (size() < N) {
				arr[count] = i;
				count++;
			}
		}
	};
}
#endif
