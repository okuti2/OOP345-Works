/* ------------------------------------------------------
Workshop 6 part 2
Module: Car
Filename: Car.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    5th November, 2022
-----------------------------------------------------------*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
   class Car : public Vehicle
   {
   private:
      std::string m_maker{};
      char m_condition{};
      double m_topSpeed = 0;
   public:
      Car(std::istream& is); // constructor that stores the tag, maker, condition, topspeed
      auto condition() const->std::string; //returns the condition of the car in full words
      virtual auto topSpeed() const -> double; // returns the topspeed
      auto trim(std::string& str) const -> void; // trim function from workshop 4 part 2
     virtual auto display(std::ostream& out) const -> void;
      auto isDigit(const std::string& sample)->bool; // checks if the string is a number

   };


}
#endif




