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

   Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {

   }

   Restaurant::Restaurant(const Restaurant& res) {
      *this = res;
   }

   Restaurant& Restaurant::operator=(const Restaurant& res) {
      if (this != &res) {
         for (size_t i = 0; i < m_noOfReservations; i++) {

         }
      }
      return *this;
   }
}