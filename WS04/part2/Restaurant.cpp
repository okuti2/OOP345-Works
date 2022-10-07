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
   Restaurant& Restaurant::operator=(const Restaurant& res) {
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
   Restaurant& Restaurant::operator=(Restaurant&& res) noexcept {
      if (this != &res)
      {
         m_noOfReservations = res.m_noOfReservations;

         /*for (auto i = 0u; i < m_noOfReservations; i++)
         {
             delete m_reservation[i]; corrected memory leak by removing this part-using a single deletion rather than a loop+ that
         }*/
         delete[] m_reservation;
         m_reservation = res.m_reservation;

         /* m_reservation = new const Reservation *[m_noOfReservations]; // leak

          for (size_t i = 0u; i < m_noOfReservations; i++) corrected memory leak by removing this part - dynamically allocating and assigning to source with loop created memory that was not used and consequently not freed
          {
              m_reservation[i] = new Resrvation(*res.m_reservation[i]); // leak
          }*/
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

   size_t Restaurant::size() {
      return m_noOfReservations;
   }

   std::ostream& operator << (std::ostream& ostr, const Restaurant& res) {
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