// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Utilities.h"

namespace sdds
{
  
   auto Utilities::setFieldWidth(size_t newWidth) -> void {
      m_widthField = newWidth;
   }

   auto Utilities::getFieldWidth() const->size_t {
      return m_widthField;
   }

   auto Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)->std::string {
      // yet to be implemented
   }

   auto Utilities::setDelimiter(char newDelimiter) -> void {
      m_delimiter = newDelimiter;
   }

   auto Utilities::getDelimiter() -> char {
      return m_delimiter;
    }



}