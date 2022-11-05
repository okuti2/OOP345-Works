/* ------------------------------------------------------
Workshop 6 part 1
Module: Autoshop
Filename: Autoshop.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    28th October, 2022
-----------------------------------------------------------*/
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <vector>
#include <string>
#include "Vehicle.h"

namespace sdds
{
   class Autoshop
   {
      std::vector<Vehicle*> m_vehicles;
   public:
      auto operator +=(Vehicle* theVehicle)-> Autoshop&;
      auto display(std::ostream& out) const -> void;
   };

}
#endif



