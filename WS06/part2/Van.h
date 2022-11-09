/* ------------------------------------------------------
Workshop 6 part 2
Module: Van
Filename: Van.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    5th November, 2022
-----------------------------------------------------------*/
#ifndef SDDS_VAN_H
#define SDDS_VAN_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
   class Van : public Vehicle
   {
      std::string m_maker{};
      char m_type{};
      char m_purpose{};
      char m_condition{};
      double m_topSpeed = 0;
   public:
      Van (std::istream& is); // constructor that stores the tag, maker,type, purpose, condition, topspeed
      auto condition() const->std::string; //returns the condition of the car in full words
      auto topSpeed() const -> double; // returns the topspeed
      auto type() const -> std::string;
      auto usage() const->std::string;
      auto trim(std::string& str) const -> void; // trim function from workshop 4 part 2
      virtual auto display(std::ostream& out) const -> void;

   };
}
#endif


