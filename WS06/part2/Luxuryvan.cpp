/* ------------------------------------------------------
Workshop 6 part 2
Module: Luxuryvan
Filename: Luxuryvan.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    5th November, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
#include <cstring>
#include "Luxuryvan.h"

namespace sdds
{
   Luxuryvan::Luxuryvan(std::istream& in) :Van(in) {
      std::string consumption;
      getline(in, consumption);
      trim(consumption);
      m_consumption = consumption[0];
      if (m_consumption == 'g') {
         //throw "Gas consumed van is not luxury";
         throw "Invalid record!";
      }
   }

   auto Luxuryvan::display(std::ostream& out) const->void {
      if (m_consumption == 'e') {
         Van::display(out);
         out <<" "<< consumption() << "  *";
      }
      
   }
   auto Luxuryvan::consumption() const->std::string {
      std::string consumption = "";
      if (m_consumption == 'e') {
         consumption = "electric van";
      }
      else if (m_consumption == 'g') {
         consumption = "gas consumed van";
      }
      return consumption;
   }

}

