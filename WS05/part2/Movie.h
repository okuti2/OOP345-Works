/* ------------------------------------------------------
Workshop 5 part 2
Module: Book
Filename: Movie.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    14th October, 2022
-----------------------------------------------------------*/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds
{
   class Movie
   {
      std::string m_title;
      unsigned m_year;
      std::string m_desc;
   public:
      Movie(); // default ocnstructor
      auto title() const->const std::string&; // query that displays the title 
      Movie(const std::string& strMovie); // parametrized constructor
      auto trim(std::string& str) const-> void; // remove whitespace from beginning and end 
      template <typename T>
      auto fixSpelling(T& spellChecker)-> void;
      friend auto operator <<(std::ostream& ostr, const Movie& movie)->std::ostream&;

   };

   template <typename T>
   auto Movie::fixSpelling(T& spellChecker)-> void {
      spellChecker(m_title);
      spellChecker(m_desc);
   }
   
}
#endif


