/* ------------------------------------------------------
Workshop 5 part 2
Module: SpellChecker.h
Filename: SpellChecker.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    14th October, 2022
-----------------------------------------------------------*/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace sdds
{
   class SpellChecker
   {
      const static size_t m_count = 6;
      std::string m_badWords[m_count];
      std::string m_goodWords[m_count];
      int m_corrections[m_count]{};
   public:
      SpellChecker(const char* filename);
      auto trim(std::string& str) const -> void;
      auto operator()(std::string& text)-> void;
      auto showStatistics(std::ostream& out) const -> void;
   };
   
}
#endif



