/* ------------------------------------------------------
Workshop 7 part 2
Module: CrimeStatistics
Filename: CrimeStatistics.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    11th November, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
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
            crime.m_resolved = stoi(resolved);
            m_crimes.push_back(crime);
         }
      }
   }

   auto CrimeStatistics::display(std::ostream& out) const->void {

      std::for_each(m_crimes.begin(), m_crimes.end(), [=, &out](const Crime& Crime){ out << Crime << std::endl;});

      auto total_crimes = std::accumulate(m_crimes.begin(), m_crimes.end(), 0u, [=](const size_t& x, const Crime& crime)
      { return x + crime.m_numCases; });

      auto total_resolved = std::accumulate(m_crimes.begin(), m_crimes.end(), 0u, [=](const size_t& x, const Crime& crime)
      { return x + crime.m_resolved; });

      out << "----------------------------------------------------------------------------------------" << std::endl;
      out << "| " << std::right<<std::setw(79) << "Total Crimes:  " << total_crimes << " |"
         << std::endl;
      out << "| " <<std::right << std::setw(79) << "Total Resolved Cases:  " << total_resolved << " |"
         << std::endl;
   }

   auto CrimeStatistics::trim(std::string& str) const -> void { // removes the whitespace from the front and back of a string, taken from workshop 4 part 2 
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }

   auto CrimeStatistics::sort(const std::string fieldName) -> void {

      std::sort(m_crimes.begin(), m_crimes.end(), [=](const Crime& a, const Crime& b) {
         if (fieldName == "Province") {
            return a.m_province < b.m_province;
         }
         else if (fieldName == "Crime") {
            return a.m_crime < b.m_crime;
         }
         else if (fieldName == "Cases") {
            return a.m_numCases < b.m_numCases;
         }
         else if (fieldName == "Resolved") {
            return a.m_resolved < b.m_resolved;
         }
         else {
            return false;
         }
      });
   }

   auto CrimeStatistics::cleanList() -> void {

      std::transform(m_crimes.begin(), m_crimes.end(), m_crimes.begin(), [=](Crime& Crime) { 
         if (Crime.m_crime == "[None]") {
            Crime.m_crime = "";
         }
         return Crime;
      });
   }

   auto CrimeStatistics::inCollection(const std::string crimeName) const-> bool {
      
      return std::any_of(m_crimes.begin(), m_crimes.end(), [=](const Crime& Crime){
         return Crime.m_crime == crimeName;
      });
   }

   auto CrimeStatistics::getListForProvince(const std::string Province) const->std::list<Crime> {
      size_t numInList = std::count_if(m_crimes.begin(), m_crimes.end(), [=](const Crime& Crime)
      {return Province == Crime.m_province;});
      std::list<Crime>FilteredByProvince(numInList);

      std::copy_if(m_crimes.begin(), m_crimes.end(), FilteredByProvince.begin(), [=](const Crime& Crime) {
         return Province == Crime.m_province;
      });

      return FilteredByProvince;
   }

   std::ostream& operator<<(std::ostream& out, const Crime& theCrime) {
      out << std::left << "| " << std::setw(21) << theCrime.m_province;
      out << std::left << " | " << std::setw(15) << theCrime.m_district;
      out << std::left << " | " << std::setw(20) << theCrime.m_crime;
      out << std::right << " | " << std::setw(6) << theCrime.m_year;
      out << std::right << " | " << std::setw(4) << theCrime.m_numCases;
      out << std::right << " | " << std::setw(3) << theCrime.m_resolved << " |";
      return out;
   }
}

