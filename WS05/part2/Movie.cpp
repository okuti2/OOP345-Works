/* ------------------------------------------------------
Workshop 5 part 2
Module: Movie
Filename: Movie.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
line 45-48 was taken from my trim function in workshop 4 part 2
-----------------------------------------------------------
Date    14th October, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
#include "Movie.h"

namespace sdds
{
   Movie::Movie() {
      m_title = "";
      m_desc = "";
      m_year = 0u;
   }

   auto Movie::title() const->const std::string& {
      return m_title;
   }

   Movie::Movie(const std::string& strMovie) { // parametrized constructor

      size_t startPos = 0;
      size_t endPos = strMovie.find(',');
      trim(m_title = strMovie.substr(startPos, endPos));

      startPos = endPos + 1;
      endPos = strMovie.find(',', startPos);
      m_year = stoi(strMovie.substr(startPos, endPos - startPos));

      startPos = endPos + 1;
      endPos = strMovie.find('\n', startPos);
      trim(m_desc = strMovie.substr(startPos, endPos - startPos));
   }

   auto Movie::trim(std::string& str) const-> void {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }

   auto operator <<(std::ostream& ostr, const Movie& movie)->std::ostream& {
      ostr << std::setw(40) << movie.m_title <<" | ";
      ostr << std::setw(4) << movie.m_year << " | ";
      ostr << movie.m_desc << std::endl;
      return ostr;
   }





}

