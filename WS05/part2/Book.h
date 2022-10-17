/* ------------------------------------------------------
Workshop 5 part 2
Module: Book
Filename: Book.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    13th October, 2022
-----------------------------------------------------------*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds
{
   class Book
   {
      std::string m_author;
      std::string m_title;
      std::string m_countryOfPub;
      unsigned m_year;
      double m_price;
      std::string m_description;

   public:
      Book();
      auto title() const -> const std::string&;
      auto country() const -> const std::string&;
      auto year() const -> const size_t&;
      auto price() -> double&;
      auto trim(std::string& str) const-> void; // used in workshop 4 part 2
      Book(const std::string& strBook);
      friend auto operator <<(std::ostream& ostr, const Book& book)->std::ostream&;
      template <typename T>
      auto fixSpelling(T& spellChecker)-> void;
   };

   template <typename T>
   auto Book::fixSpelling(T& spellChecker)-> void { // this function is passed the function object of spellChecker because of the overloaded() operator
      spellChecker(m_description); // this calls the overloaded () operator and replaces all the bad spelling with the correct ones
   }
}
#endif


