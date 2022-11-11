/* ------------------------------------------------------
Workshop 7 part 1
Module: CrimeStatistics
Filename: CrimeStatistics.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    9th November, 2022
-----------------------------------------------------------*/
#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H

#include <iostream>
#include <vector>
#include <string>
#include <list>

namespace sdds
{
   struct Crime
   {
      std::string m_province;
      std::string m_district;
      std::string m_crime;
      unsigned m_numCases;
      unsigned m_year;
      unsigned m_numResolved;
   };
   class CrimeStatistics
   {
      std::vector<Crime>m_crimes;
   public:
      CrimeStatistics(std::string filename);
      auto display(std::ostream& out) const->void;
      auto trim(std::string& str) const -> void;
      //auto charToString(char* arr)const->std::string;
   };
   std::ostream& operator<<(std::ostream& out, const Crime& theCrime);

}
#endif




