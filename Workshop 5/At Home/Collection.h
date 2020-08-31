// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 2/18/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace sdds {

    template<typename T>
    class Collection {
        string col_name;
        T* col_arr;
        int col_size;

    public:
        Collection(string name) {
            col_arr = nullptr;
            col_name = name;
            col_size = 0;
        }

        Collection(Collection& c) {
            delete[] c.col_arr;
            c.col_arr = nullptr;
            c.col_size = 0;
        }

        ~Collection() {
            delete[] col_arr;
            col_arr = nullptr;
        }

        const string& name() const {
            return col_name;
        }

        const int size() const {
            return col_size;
        }

        void setObserver(void (*observer)(const Collection<T>& _col, const T& _t)) {}

        Collection<T>& operator+=(const T& item) {
            bool found = false;
            int i;
            if (col_size > 0) {
                for (i = 0; i < col_size; ++i) 
                    found = (col_arr[i].title() == item.title());

                if (!found) {
                    T temp[col_size + 1];
                    for (i = 0; i < col_size; ++i) 
                        temp[i] = col_arr[i];
                    col_size++;
                    delete[] col_arr;
                    col_arr = nullptr;
                    col_arr = new T[col_size];
                    for (i = 0; i < col_size - 1; ++i) {
                        col_arr[i] = temp[i];
                    }
                    col_arr[col_size - 1] = item;
                }
            }
            else {
                col_arr = new T[1];
                col_arr[0] = item;
                col_size++;
            }
            return *this;
        }

        T& operator[](int index) const {
            if (index > size()) {
                string error_message =
                    "Bad index [" + to_string(index) + "]. Collection has [" + to_string(size()) + "] items";
                throw (out_of_range(error_message));
            }
            else 
                return col_arr[index];
        }

        T* operator[](string title) const {
            bool found = false;
            int i = 0;
            if (col_size > 0) {
                while (!found && i < col_size) {
                    if (col_arr[i].title() == title) {
                        found = true;
                    }
                    else {
                        i++;
                    }
                }
            }
            if (found) 
                return &col_arr[i];
            else 
                return nullptr;       
        }

        friend ostream& operator<<(ostream& os, Collection& c) {
            for (int i = 0; i < c.col_size; ++i) 
                os << c.col_arr[i];
            return os;
        }
    };
}

#endif
