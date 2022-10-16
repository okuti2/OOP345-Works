/* ------------------------------------------------------
Workshop 5 part 2
Module: SpellChecker
Filename: SpellChecker.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    14th October, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
#include "SpellChecker.h"

namespace sdds
{
   SpellChecker::SpellChecker(const char* filename) { // loads the contents of the file 
      static size_t counter = 0u; // made it static so that it can be used for the file scope
      const char* errMes = "Bad file name!";
      std::ifstream fs(filename);
      if (!fs) {
         throw errMes; // when it is caught it will be a const char* msg 
      }
      else {
         std::string line;
         
         while (std::getline(fs, line)) {
            size_t startPos = 0;
            size_t endPos = line.find(' ');
            trim(m_badWords[counter] = line.substr(startPos, endPos));

            startPos = endPos + 1;
            endPos = line.find('\n', startPos);
            trim(m_goodWords[counter] = line.substr(startPos, endPos - startPos));

            ++counter;
         }
         fs.close();
      }
   }

   auto SpellChecker::trim(std::string& str) const -> void { // removes the whitespace from the front and back of a string, taken from workshop 4 part 2 
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }

   auto SpellChecker::operator()(std::string& text)-> void {
      for (size_t i = 0; i < m_count; i++) {
        // m_corrections[i] = 0;
         size_t startPos = text.find(m_badWords[i]);
         size_t length = m_badWords[i].length();
         while (startPos != std::string::npos) {
            text.replace(startPos, length, m_goodWords[i]);
            startPos = text.find(m_badWords[i], startPos + 1);
            m_corrections[i]++;
         }
      }
   }

   auto SpellChecker::showStatistics(std::ostream& out) const -> void {
                  //BAD_WORD: CNT replacements<endl>
      out << "Spellchecker Statistics" << std::endl;
      for (size_t i = 0; i < m_count; i++) {
         out << std::right << std::setw(15) << m_badWords[i];
         out<< ": " << m_corrections[i] << " replacements" << std::endl;
      }
   }

}

