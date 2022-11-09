/* ------------------------------------------------------
Workshop 6 part 2
Module: Luxuryvan
Filename: Luxuryvan.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    5th November, 2022
-----------------------------------------------------------*/
#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H

#include <iostream>
#include <vector>
#include <string>
#include "Van.h"

namespace sdds
{
   class Luxuryvan : public Van
   {
      std::vector<Luxuryvan*> m_lvehicles;
      char m_consumption;
   public:
      Luxuryvan(std::istream& in);
      auto display(std::ostream& out) const->void;
      auto consumption() const->std::string;

   };
}
#endif


