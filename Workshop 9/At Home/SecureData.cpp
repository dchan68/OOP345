// Name: Daryan Chan
// Seneca Student ID: 113973192
// Seneca email: dchan68@myseneca.ca
// Date of completion: 3/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		//converter(text, key, nbytes, Cryptor());
		//encoded = !encoded;

		const int nThreads = 4;
		const int chunkSize = nbytes / nThreads;

		std::thread threads[nThreads];
		Cryptor cryptors[nThreads];

		for (int i = 0; i < nThreads; i++)
		{
			unsigned int size = chunkSize;

			auto func = std::bind(converter, text + i * chunkSize, key, (i == nThreads - 1) ? size = nbytes - i * chunkSize : size, cryptors[i]);
			threads[i] = std::thread(func);
		}

		for (unsigned int i = 0; i < nThreads; i++)
			threads[i].join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			try {
				std::ofstream ofs(file, std::ofstream::binary);
				// TODO: write data into the binary file
				//         and close the file
				ofs.write(text, nbytes);
				ofs.close();
			}
			catch (...) {
				throw std::string("\n***Cannot open file***\n");
			}

		}
	}

	void SecureData::restore(const char* file, char key) {

		try {
			// TODO: open binary file for reading
			std::ifstream ifs(file, std::ifstream::binary);
			// TODO: - allocate memory here for the file content
			char* buffer = new char[nbytes];

			// TODO: - read the content of the binary file
			ifs.read(buffer, nbytes);

			*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

			encoded = true;

			// decode using key
			code(key);

			*ofs << "Data decrypted in memory\n\n";

		}
		catch (...) {
			throw std::string("\n***Cannot open file***\n");
		}

	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
