/* ------------------------------------------------------
Workshop 6 part 2
Module: Autoshop
Filename: Autoshop.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    5th November, 2022
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
      std::vector<Vehicle*>::iterator vehicles;
      for (auto vehicles = m_vehicles.begin(); vehicles != m_vehicles.end(); vehicles++) {
         (*vehicles)->display(out);
         out << std::endl;
      }
   }

   Autoshop::~Autoshop() {
      for (size_t i = 0; i < m_vehicles.size(); i++) {
         delete m_vehicles[i];
      }
   }
}

