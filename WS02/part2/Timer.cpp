/* ------------------------------------------------------
Workshop 2 part 2
Module: Timer
Filename: Timer.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    24th September, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono> // For part 2 experiements
#include "Timer.h"

using namespace std;

namespace sdds
{
   void Timer::start()
   {
      m_startTime = std::chrono::steady_clock::now();
   }

   long long Timer::stop()
   {
      std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
      auto m_endTime = end - m_startTime;
      return m_endTime.count();
   }
}