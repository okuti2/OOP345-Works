/* ------------------------------------------------------
Workshop 4 part 2
Module: ConfirmationSender
Filename: ConfirmationSender.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    4th October, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "ConfirmationSender.h"

namespace sdds
{
   ConfirmationSender::ConfirmationSender() {
      m_noOfReservations = 0u;
      m_reservation = nullptr;
   }

   // copy constructor
   ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
      *this = src;
   }

   // copy assignment
   ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
      if (this != &src) {
         for (size_t i = 0u; i < m_noOfReservations; i++) {
            delete m_reservation[i];
         }
         delete[] m_reservation;
         m_noOfReservations = src.m_noOfReservations;

         m_reservation = new const Reservation * [m_noOfReservations];

         for (size_t i = 0u; i < m_noOfReservations; i++)
         {
            m_reservation[i] = new const Reservation(*src.m_reservation[i]);
         }
      }
      return *this;
   }

   // move constructor
   ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept {
      *this = std::move(src);
   }

   //move assignment
   ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept {
      if (this != &src)
      {
         m_noOfReservations = src.m_noOfReservations;

         /*for (auto i = 0u; i < m_noOfReservations; i++)
         {
             delete m_reservation[i]; corrected memory leak by removing this part-using a single deletion rather than a loop+ that
         }*/
         delete[] m_reservation;
         m_reservation = src.m_reservation;

         /* m_reservation = new const Reservation *[m_noOfReservations]; // leak

          for (size_t i = 0u; i < m_noOfReservations; i++) corrected memory leak by removing this part - dynamically allocating and assigning to source with loop created memory that was not used and consequently not freed
          {
              m_reservation[i] = new Resrvation(*res.m_reservation[i]); // leak
          }*/
         src.m_noOfReservations = 0;
         src.m_reservation = nullptr;
      }
      return *this;
   }

   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
      return *this;
   }

   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
      return *this;
   }

   //Destructor
   ConfirmationSender::~ConfirmationSender() {
      for (size_t i = 0; i < m_noOfReservations; i++) {
         delete m_reservation[i];
      }
      delete[] m_reservation;
   }

   std::ostream& operator <<(std::ostream& ostr, const ConfirmationSender& src) {
      ostr << "--------------------------" << std::endl;
      ostr << "Confirmations to Send" << std::endl;
      ostr << "--------------------------" << std::endl;
      if (src.m_noOfReservations == 0)
      {
         ostr << "There are no confirmations to send!" << std::endl;
      }
      if (src.m_noOfReservations > 0)
      {
         for (size_t i = 0; i < src.m_noOfReservations; i++)
         {
            ostr << *src.m_reservation[i];
         }
      }
      ostr << "--------------------------" << std::endl;
      return ostr;
   }
} 