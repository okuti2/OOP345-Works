/* ------------------------------------------------------
Workshop 6 part 1
Module: Autoshop
Filename: Autoshop.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    28th October, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "Autoshop.h"
#include "Vehicle.h"

namespace sdds
{
   auto Autoshop::operator +=(Vehicle* theVehicle)->Autoshop& {
      m_vehicles.push_back(theVehicle);
      return *this;
   }

   auto Autoshop::display(std::ostream& out) const -> void {
      for (size_t i = 0; i < m_vehicles.size(); i++) {
         m_vehicles[i]->display(out);
         delete m_vehicles[i];
      }
   }
}

