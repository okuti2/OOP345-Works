/* ------------------------------------------------------
Workshop 4 part 2
Module: Restaurant
Filename: Restaurant.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    4th October, 2022
-----------------------------------------------------------*/
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

#include <iostream>
#include <string>

namespace sdds
{
   //class Reservation;
   class Restaurant
   {
      Reservation** m_reservation{};
      size_t m_noOfReservations{ 0u };
   public:
      Restaurant();
      Restaurant(const Reservation* reservations[], size_t cnt);
      Restaurant(const Restaurant& res); // copy constructor
      Restaurant& operator=(const Restaurant& res); // copy assignment
      Restaurant(Restaurant&& res) noexcept;// move constructor
      Restaurant& operator=(Restaurant&& src) noexcept;// move assignment operator
      ~Restaurant();
      size_t size();
      friend std::ostream& operator << (std::ostream& ostr, const Restaurant& res);
   };

}
#endif
