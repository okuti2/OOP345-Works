/* ------------------------------------------------------
Workshop 6 part 1
Module: Utilities
Filename: Utilities.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    4th November, 2022
-----------------------------------------------------------*/
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include "Vehicle.h"

namespace sdds
{
     auto createInstance(std::istream& in)-> Vehicle*;
     auto trim(std::string& str) -> void;
   
}
#endif