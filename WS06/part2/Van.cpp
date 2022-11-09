/* ------------------------------------------------------
Workshop 6 part 2
Module: Van
Filename: Van.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    5th November, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
#include <cstring>
#include "Van.h"

namespace sdds
{
   Van::Van(std::istream& is) {

      std::string tag;
      std::string maker;
      std::string type;
      std::string purpose;
      std::string condition;
      std::string topSpeed;
      std::string consumption;
      getline(is, tag, ',');
      trim(tag);

      if (strcmp(tag.c_str(), "v") == 0 || strcmp(tag.c_str(), "V") == 0 || strcmp(tag.c_str(), "l") == 0 || strcmp(tag.c_str(), "L") == 0) {
         getline(is, maker, ',');
         getline(is, type, ',');
         getline(is, purpose, ',');
         getline(is, condition, ',');
         getline(is, topSpeed, ',');
         consumption = is.peek();
         trim(m_maker = maker);
         trim(type);
         if (type != "p" && type != "m" && type != "c") {
            //throw "Invalid record!";
            throw std::invalid_argument("Invalid record!");
         }
         else {
            m_type = type[0];
         }
         trim(purpose);
         if (purpose != "d" && purpose != "p" && purpose != "c")
         {
            //throw "Invalid record!";
            throw std::invalid_argument("Invalid record!");
         }
         else {
            m_purpose = purpose[0];
         }
         trim(condition);
         if (condition == "") {
            m_condition = 'n';
         }
         else if (condition != "n" && condition != "u" && condition != "b") {
            //throw "Invalid record!";
            throw std::invalid_argument("Invalid record!");
         }
         else {
            m_condition = condition[0];
         }
         trim(topSpeed);
         m_topSpeed = stod(topSpeed);
      }
   }

   auto Van::condition() const->std::string {
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

   auto Van::topSpeed() const -> double {
      return m_topSpeed;
   }

   auto Van::type() const->std::string {
      std::string result;
      switch (m_type) {
      case 'p':
         result = "pickup";
         break;
      case 'm':
         result= "mini-bus";
         break;
      case 'c':
         result = "camper";
         break;
      }
      return result;
   }

   auto Van::usage() const->std::string {
      std::string result;
      switch (m_purpose) {
      case 'd':
         result = "delivery";
         break;
      case 'p':
         result = "passenger";
         break;
      case 'c':
         result = "camping";
         break;
      }

      return result;
   }

   auto Van::trim(std::string& str) const -> void { // removes the whitespace from the front and back of a string, taken from workshop 4 part 2 
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }

   auto Van::display(std::ostream& out) const -> void {
      out <<std::right<< "| " << std::setw(8) << m_maker;
      out <<std::left<< " | " << std::setw(12) << type();
      out << " | " << std::setw(12) << usage();
      out << " | " << std::setw(6) << condition();
      out << " | " << std::setw(6) << std::fixed << std::setprecision(2) << m_topSpeed << " |";

   }


}

