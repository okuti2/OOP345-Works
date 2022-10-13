/* ------------------------------------------------------
Workshop 5 part 1
Module: ConfirmationSender
Filename: ConfirmationSender.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    12th October, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

namespace sdds
{
   Book::Book() { // default constructor initializing to a safe state
      m_author = "";
      m_title = "";
      m_countryOfPub = "";
      m_year = 0;
      m_price = 0;
      m_description = "";
   }

   auto Book::title() const -> const std::string& { // returns the title of the book
      return m_title;
   }

   auto Book::country() const -> const std::string& { // returns the country of publication
      return m_countryOfPub;
   }

   auto Book::year() const -> const size_t& { // returns the publication year
      return m_year;
   }

   auto Book::price() -> double& { // returns the book price 
      return m_price;
   }

   Book::Book(const std::string& strBook) { // extracts the data from a long string and stores each substring into its related member variable in the object. I used this function in ws 4 
      size_t startPos = 0;
      size_t endPos = strBook.find(',');
      this->trim(m_author = strBook.substr(startPos, endPos));

      startPos = endPos + 1;
      endPos = strBook.find(',', startPos);
      this->trim(m_title = strBook.substr(startPos, endPos - startPos));

      startPos = endPos + 1;
      endPos = strBook.find(',', startPos);
      this->trim(m_countryOfPub = strBook.substr(startPos, endPos - startPos));

      startPos = endPos + 1;
      endPos = strBook.find(',', startPos);
      m_price = stod(strBook.substr(startPos, endPos - startPos));

      startPos = endPos + 1;
      endPos = strBook.find(',', startPos);
      m_year = stoi(strBook.substr(startPos, endPos));

      startPos = endPos + 1;
      endPos = strBook.find('\n', startPos);
      this->trim(m_description = strBook.substr(startPos, endPos - startPos));
   }

   auto Book::trim(std::string& str) const -> void { // removes the whitespace from the front and back of a string, taken from workshop 4 part 2 
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }
  
   auto operator <<(std::ostream& ostr, const Book& book)->std::ostream& { // prints out the book object 
      ostr << std::setw(20) << book.m_author << " | ";
      ostr << std::setw(22) << book.m_title << " | ";
      ostr << std::setw(5) << book.m_countryOfPub << " | ";
      ostr << std::setw(4) << book.m_year << " | ";
      ostr << std::setw(6) << std::setprecision(2) << std::fixed << book.m_price << " | ";
      ostr << book.m_description << std::endl;
      return ostr;
   }

}