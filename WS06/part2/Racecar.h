/* ------------------------------------------------------
Workshop 6 part 2
Module: Racecar
Filename: Racecar.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    5th November, 2022
-----------------------------------------------------------*/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include <string>
#include "Car.h"

namespace sdds
{
   class Racecar : public Car
   {
      double m_booster;
   public:
      Racecar(std::istream& in);
      virtual auto display(std::ostream& out) const -> void;
      auto topSpeed() const-> double;
   };

}
#endif




