// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 16th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Utilities.h"

namespace sdds
{
   char Utilities::m_delimiter = 0; // initializing the static variable

   auto Utilities::setFieldWidth(size_t newWidth) -> void {
      m_widthField = newWidth;
   }

   auto Utilities::getFieldWidth() const->size_t {
      return m_widthField;
   }

   auto Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)->std::string { // extracts token before the delimiter from a string
      size_t end_pos = (str.find(getDelimiter(), next_pos));
      std::string token = str.substr(next_pos, end_pos - next_pos);
      if (end_pos == next_pos) // is the delimiter in next_pos
      {
         more = false;
         throw "error";
      }
      next_pos = end_pos + 1;
      setFieldWidth(std::max(m_widthField, token.size())); // std::max() returns the maximum value of the two
      trim(token);
      more = (end_pos != std::string::npos); // if it as the end then there is no more 
      return token;
   }

   auto Utilities::setDelimiter(char newDelimiter) -> void {
      m_delimiter = newDelimiter;
   }

   auto Utilities::getDelimiter() -> char {
      return m_delimiter;
   }

   auto Utilities::trim(std::string& str) const -> void {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }

}