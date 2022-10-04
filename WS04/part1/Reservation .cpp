/* ------------------------------------------------------
Workshop 4 part 1
Module: Reservation
Filename: Reservation .cpp
Version 1
Author:	Oluresosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    4th October, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Reservation.h"

namespace sdds
{
   Reservation::Reservation() {
      m_reservationId[0] = '\0';
      m_name = "";
      m_email = "";
      m_numOfPeople = 0;
      m_day = 0;
      m_time = 0;
   }

   void Reservation::update(int day, int time) {
      m_day = day;
      m_time = time;
   }

   Reservation::Reservation(const std::string& res) {
      int startPos = 0;
      int endPos = res.find(':');
      this->trim(m_reservationId = res.substr(startPos, endPos));

      startPos = endPos + 1;
      endPos = res.find(',', startPos);
      this->trim(m_name = res.substr(startPos, endPos - startPos));

      startPos = endPos + 1;
      endPos = res.find(',', startPos);
      this->trim(m_email = res.substr(startPos, endPos - startPos));

      startPos = endPos + 1;
      endPos = res.find(',', startPos);
      m_numOfPeople = stoi(res.substr(startPos, endPos - startPos));

      startPos = endPos + 1;
      endPos = res.find(',', startPos);
      m_day = stoi(res.substr(startPos, endPos));

      startPos = endPos + 1;
      endPos = res.find(',', startPos);
      m_time = stoi(res.substr(startPos, endPos));
   }

   void Reservation::trim(std::string& str) const {
      for (size_t i = 0u; i < str.length() + 1; i++)
      {
         str.erase(i, str.find_first_not_of(' '));
         str.erase(str.find_last_not_of(' ') + 1);
      }
   }

   std::ostream& operator<<(std::ostream& ostr, const Reservation& res) {
      ostr << "Reservation ";
      ostr << res.m_reservationId <<":"<< std::right<< std::setw(10);
      ostr << res.m_name << std::setw(20) << std::right;
      ostr << "<" << res.m_email << ">" << std::setw(20) << std::left;
      if (6 <= res.m_time <= 9) {
         ostr << " Breakfast ";
      }
      else if (11 <= res.m_time <= 15) {
         ostr << " Lunch ";
      }
      else if (17 <= res.m_time <= 21) {
         ostr << " Dinner ";
      }
      else {
         ostr << " Drinks ";
      }
      ostr << " on day " << res.m_day << " @ " << res.m_time << ":00 for " << res.m_numOfPeople;

      if (res.m_numOfPeople == 1) {
         ostr << " person. ";
      }
      else {
         ostr << " people. ";
      }
      ostr << "\n";

      return ostr;
   }
}