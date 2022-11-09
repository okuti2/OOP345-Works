/* ------------------------------------------------------
Workshop 6 part 2
Module: Racecar
Filename: Racecar.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    5th November, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Racecar.h"

namespace sdds
{
   Racecar::Racecar(std::istream& in):Car(in) {
      std::string booster;
      getline(in, booster);
      trim(booster);
      m_booster = stod(booster);
   }

   auto Racecar::display(std::ostream& out) const -> void {
      Car::display(out);
      out << "*" ;
   }

   auto Racecar::topSpeed() const-> double {
      return (1 + m_booster) * Car::topSpeed();
   }


}


