/* ------------------------------------------------------
Workshop 7 part 1
Module: CrimeStatistics
Filename: CrimeStatistics.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    9th November, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include "CrimeStatistics.h"

namespace sdds
{
   CrimeStatistics::CrimeStatistics(std::string filename) {
      std::ifstream file(filename);
      if (!file) {
         throw std::invalid_argument("ERROR: Cannot open file [" + filename + "].\n");
      }
      else {
         std::string line;
         while (std::getline(file, line)) {
            Crime crime;
            std::string year;
            std::string cases;
            std::string resolved;
            trim(crime.m_province = line.substr(0, 25));
            trim(crime.m_district = line.substr(25, 25));
            trim(crime.m_crime = line.substr(50, 25));
            trim(year = line.substr(75, 5));
            crime.m_year = stoi(year);
            trim(cases = line.substr(80, 5));
            crime.m_numCases = stoi(cases);
            trim(resolved = line.substr(85, 5));
            crime.m_numResolved = stoi(resolved);
            m_crimes.push_back(crime);
         }
      }
   }

   auto CrimeStatistics::display(std::ostream& out) const->void {
      std::for_each(m_crimes.begin(), m_crimes.end(), [=, &out](const Crime& Crime)
         { out << Crime << std::endl;});
   }

   auto CrimeStatistics::trim(std::string& str) const -> void { // removes the whitespace from the front and back of a string, taken from workshop 4 part 2 
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }

   /*auto CrimeStatistics::charToString(char* arr)const->std::string {
      size_t size_arr = strlen(arr);
      std::string str = "";
      for (size_t x = 0; x < size_arr; x++) {
         str = str + arr[x];
      }
      trim(str);
      return str;
   }*/

   std::ostream& operator<<(std::ostream& out, const Crime& theCrime) {
      out << std::left << "| " << std::setw(21) << theCrime.m_province;
      out << std::left << " | " << std::setw(15) << theCrime.m_district;
      out << std::left << " | " << std::setw(20) << theCrime.m_crime;
      out << std::right << " | " << std::setw(6) << theCrime.m_year;
      out << std::right << " | " << std::setw(4) << theCrime.m_numCases;
      out << std::right << " | " << std::setw(3) << theCrime.m_numResolved << " |";
      return out;
   }
}

