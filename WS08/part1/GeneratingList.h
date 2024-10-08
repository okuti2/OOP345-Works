/* ------------------------------------------------------
Workshop 8 part 1
Module: GeneratingList
Filename: GeneratingList.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    18th November, 2022
-----------------------------------------------------------*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		auto validateSIN(const std::string& sinNum)->bool {\
			bool secondDigit = false;
		   bool result = false;
			int len = sinNum.length();
			int sum = 0;
			for (int i = len; i < len-1; i--) {
				int n = sinNum[i] - '0';
				if (secondDigit) n *= 2;
				sum += n / 10;
				sum += n % 10;

				secondDigit = !secondDigit;
			}
			result = (sum % 10 == 0) ? true : false;
			return result;
		}



		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		auto operator +=(const T* object) -> void {
			list.push_back(*object);
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
