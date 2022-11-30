// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 16th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//-----------------------------------------------------------
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>


namespace sdds
{
   class Utilities
   {
      size_t m_widthField = 1; //  length of token extracted
      static char m_delimiter; //all utilities objects share the same delimiter
   public:
      //Member Functions
      auto setFieldWidth(size_t newWidth) -> void;
      auto getFieldWidth() const->size_t;
      auto extractToken(const std::string& str, size_t& next_pos, bool& more)->std::string;
      //Class Functions
      static auto setDelimiter(char newDelimiter) -> void;
      static auto getDelimiter() -> char;

      auto trim(std::string& str) const -> void; // trim function
   };
}
#endif