/* ------------------------------------------------------
Workshop 4 part 2
Module: Restaurant
Filename: Restaurant.cpp
Version 1
Author:	Oluresosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    4th October, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Restaurant.h"

namespace sdds
{
   Restaurant::Restaurant() {
      m_noOfReservations = 0u;
      m_reservation = nullptr;
   }

   //constructor
   Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
      m_noOfReservations = cnt;
      m_reservation = new Reservation * [m_noOfReservations];
      for (size_t i = 0; i < m_noOfReservations; i++) {
         m_reservation[i] = new Reservation(*reservations[i]);
      }
   }

   //copy constructor
   Restaurant::Restaurant(const Restaurant& res) {
      *this = res;
   }

   // copy assignment
   auto Restaurant::operator=(const Restaurant& res)-> Restaurant& {
      if (this != &res) {
         for (size_t i = 0u; i < m_noOfReservations; i++) {
            delete m_reservation[i];
         }
         delete[] m_reservation;
         m_noOfReservations = res.m_noOfReservations;

         m_reservation = new Reservation * [m_noOfReservations];

         for (size_t i = 0u; i < m_noOfReservations; i++)
         {
            m_reservation[i] = new Reservation(*res.m_reservation[i]);
         }
      }
      return *this;
   }

   // move constructor
   Restaurant::Restaurant(Restaurant&& res) noexcept {
      *this = std::move(res);
   }

   // move assignment
   auto Restaurant::operator=(Restaurant&& res) noexcept-> Restaurant& {
      if (this != &res)
      {
         m_noOfReservations = res.m_noOfReservations;
         delete[] m_reservation;
         m_reservation = res.m_reservation;

         res.m_noOfReservations = 0;
         res.m_reservation = nullptr;
      }
      return *this;
   }

   Restaurant::~Restaurant() {
      for (size_t i = 0; i < m_noOfReservations; i++) {
         delete m_reservation[i];
      }
      delete[] m_reservation;
   }

   auto Restaurant::size()-> size_t {
      return m_noOfReservations;
   }

   auto operator << (std::ostream& ostr, const Restaurant& res)-> std::ostream& {
      static int count = 0;
      ostr << "--------------------------" << std::endl;
      ostr << "Fancy Restaurant (" << ++count << ")" << std::endl;
      ostr << "--------------------------" << std::endl;
      if (res.m_noOfReservations == 0)
      {
         ostr << "This restaurant is empty!" << std::endl;
      }
      if (res.m_noOfReservations > 0)
      {
         for (size_t i = 0; i < res.m_noOfReservations; i++)
         {
            ostr << *res.m_reservation[i];
         }
      }
      ostr << "--------------------------" << std::endl;
      return ostr;
   }

}