/* ------------------------------------------------------
Workshop 6 part 1
Module: Car
Filename: Car.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    28th October, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Car.h"

namespace sdds
{
   Car::Car(std::istream& is) {
      std::string CarInfo;
      std::string tag;
      getline(is, CarInfo);
      size_t startPos = 0;
      size_t endPos = CarInfo.find(',');
      trim(tag = CarInfo.substr(startPos, endPos)); // takes out the bad word from the line 
      if (strcmp(tag.c_str(), "c") == 0 || strcmp(tag.c_str(), "C") == 0) {
         startPos = endPos + 1;
         endPos = CarInfo.find(',', startPos);
         trim(m_maker = CarInfo.substr(startPos, endPos - startPos)); // takes out the good word from line

         std::string condition;
         startPos = endPos + 1;
         endPos = CarInfo.find(',', startPos);
         trim(condition = CarInfo.substr(startPos, endPos - startPos)); // takes out the good word from line
         m_condition = condition[0];
        
         startPos = endPos + 1;
         endPos = CarInfo.find('\n', startPos);
         m_topSpeed = stod(CarInfo.substr(startPos, endPos - startPos));

      }
   }

   auto Car::condition() const->std::string {
      std::string result;
      switch (m_condition) {
      case 'n':
         result = "new";
         break;
      case 'u':
         result = "used";
         break;
      case 'b':
         result = "broken";
         break;
      }
      return result;
   }

   auto Car::trim(std::string& str) const -> void { // removes the whitespace from the front and back of a string, taken from workshop 4 part 2 
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }

   auto Car::topSpeed() const->double {
      return m_topSpeed;
   }

   auto Car::display(std::ostream& out) const -> void {
      out<<std::right<< "| " << std::setw(10) << m_maker;
      out << std::left << std::fixed<<" | " << std::setw(6) << condition();
      out << " | " << std::setw(6) << std::fixed << std::setprecision(2) << m_topSpeed << " |" << std::endl;
   }
}


