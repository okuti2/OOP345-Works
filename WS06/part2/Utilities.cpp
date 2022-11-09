/* ------------------------------------------------------
Workshop 6 part 2
Module: Utilities
Filename: Utilities.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    5th November, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include "Vehicle.h"
#include "Utilities.h"
#include "Van.h"
#include "Car.h"
#include "Racecar.h"
#include "Luxuryvan.h"
namespace sdds
{
   /*auto createInstance(std::istream& in)->Vehicle* {
		std::string line;
		Vehicle* result = nullptr;
		std::getline(in, line);
		trim(line);
		char type = line[0];
		std::stringstream ss(line);
		if (type == 'c' || type == 'c') {
			result = new Car(ss);
		}
		else if (type == 'v' || type == 'v') {
			result = new Van(ss);
		}
		return result;
   }*/

	auto createInstance(std::istream& in)->Vehicle* { // without using sstream
		/*Vehicle* result = nullptr;
		in >> std::ws;
		char first = in.peek();
		if (first == 'c' || first == 'C') {
			result = new Car(in);	
		}
		else if (first == 'v' || first == 'V') {
			result = new Van(in);
		}
		else if (first == 'r' || first == 'R'){
			result = new Racecar(in);
		}
		else if (first == 'l' || first == 'L') {
			result = new Luxuryvan(in);
		}
		else {
			throw "Unknown Vehicle";
		}
		return result;*/

		Vehicle* result = nullptr;
		std::string line;
		std::getline(in, line);
		size_t length = line.length();
		if (length > 0) {
			trim(line);
			std::string type;
			type = line[0];

			std::stringstream ss(line);
			if (line[0] == 'c' || line[0] == 'C') {
				return new Car(ss);
			}
			else if (line[0] == 'v' || line[0] == 'V') {
				return new Van(ss);
			}
			else if (line[0] == 'r' || line[0]== 'R') {
				return new Racecar(ss);
			}
			else if (line[0] == 'l' || line[0]== 'L') {
				return new Luxuryvan(ss);
			}
			else {
				//throw std::invalid_argument("Unrecognized record type: [" + type + ']');
				throw ("Unrecognized record type: [" + type + "]");

			}
		}
		return result;
	}

   auto trim(std::string& str) -> void {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }
}

