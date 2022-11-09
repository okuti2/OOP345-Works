/* ------------------------------------------------------
Workshop 6 part 2
Module: Car
Filename: Car.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I got my isDigit function from stackoverflow
-----------------------------------------------------------
Date    5th November, 2022
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
      std::string tag;
      std::string maker;
      std::string condition;
      std::string topSpeed;
      getline(is, tag, ',');
      trim(tag);
      
      if (strcmp(tag.c_str(), "c") == 0 || strcmp(tag.c_str(), "C") == 0 || strcmp(tag.c_str(), "r") == 0|| strcmp(tag.c_str(), "R") == 0) {
         getline(is, maker, ',');
         getline(is, condition, ',');
         getline(is, topSpeed, ',');
         trim(m_maker = maker);
         trim(condition);
         if (condition == "") {
            m_condition = 'n';
         } else if (condition != "n" && condition != "u" && condition != "b") {
            //throw "Invalid record!";
            throw std::invalid_argument("Invalid record!");
         }else{
            m_condition = condition[0];
         }
         trim(topSpeed);
         if (isDigit(topSpeed)) {
            m_topSpeed = stod(topSpeed);
         }
         else {
            //throw "Invalid record!";
            throw std::invalid_argument("Invalid record!");
         }

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
      out << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
   }

   auto Car::isDigit(const std::string& sample)->bool {
      std::string::const_iterator it = sample.begin();
      while (it != sample.end() && std::isdigit(*it)) ++it;
      return !sample.empty() && it == sample.end();
   }

}


