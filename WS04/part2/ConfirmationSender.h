/* ------------------------------------------------------
Workshop 4 part 2
Module: ConfirmationSender
Filename: ConfirmationSender.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    4th October, 2022
-----------------------------------------------------------*/
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include <string>
#include "Reservation.h"

namespace sdds
   // aggregation between confirmationSender and Reservation
{
   class ConfirmationSender
   {
      const sdds::Reservation** m_reservation{};
      size_t m_noOfReservations{ 0u };
   public:
      ConfirmationSender();
      ConfirmationSender(const ConfirmationSender& src); // copy constructor
      ConfirmationSender& operator=(const ConfirmationSender& src); // copy assignment
      ConfirmationSender(ConfirmationSender&& src) noexcept; // move constructor
      ConfirmationSender& operator=(ConfirmationSender&& src) noexcept; //move assignment
      ConfirmationSender& operator+=(const Reservation& res); 
      ConfirmationSender& operator-=(const Reservation& res);
      ~ConfirmationSender(); // destructor
      friend std::ostream& operator <<(std::ostream& ostr, const ConfirmationSender& src);
   };

}
#endif

