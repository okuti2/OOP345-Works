/* ------------------------------------------------------
Workshop 4 part 2
Module: Reservation
Filename: Reservation .cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    4th October, 2022
-----------------------------------------------------------*/
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds
{
   class Reservation
   {
   private:
      std::string m_reservationId;
      std::string m_name;
      std::string m_email;
      unsigned m_numOfPeople;
      unsigned m_day;
      unsigned m_time;

   public:
      Reservation();
      void update(int day, int time);
      Reservation(const std::string& res);
      void trim(std::string& str) const;
      friend std::ostream& operator<<(std::ostream& ostr, const Reservation& res);
   };

}
#endif

