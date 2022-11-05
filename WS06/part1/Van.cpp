/* ------------------------------------------------------
Workshop 6 part 1
Module: Van
Filename: Van.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    28th October, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
#include "Van.h"

namespace sdds
{
   Van::Van(std::istream& is) {
      std::string VanInfo; //TAG,MAKER,TYPE,PURPOSE,CONDITION,TOP_SPEED
      std::string tag;
      getline(is, VanInfo);
      size_t startPos = 0;
      size_t endPos = VanInfo.find(',');
      trim(tag = VanInfo.substr(startPos, endPos)); 
      if (strcmp(tag.c_str(), "v") == 0 || strcmp(tag.c_str(), "V") == 0) {
         startPos = endPos + 1;
         endPos = VanInfo.find(',', startPos);
         trim(m_maker = VanInfo.substr(startPos, endPos - startPos)); 

         std::string type;
         startPos = endPos + 1;
         endPos = VanInfo.find(',', startPos);
         trim(type = VanInfo.substr(startPos, endPos - startPos)); 
         m_type = type[0];
         
         std::string purpose;
         startPos = endPos + 1;
         endPos = VanInfo.find(',', startPos);
         trim(purpose = VanInfo.substr(startPos, endPos - startPos)); 
         m_purpose = purpose[0];
         
         std::string condition;
         startPos = endPos + 1;
         endPos = VanInfo.find(',', startPos);
         trim(condition = VanInfo.substr(startPos, endPos - startPos)); 
         m_condition = condition[0];

         startPos = endPos + 1;
         endPos = VanInfo.find('\n', startPos);
         m_topSpeed = stod(VanInfo.substr(startPos, endPos - startPos));

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
      out << "| " << std::setw(8) << m_maker;
      out << " | " << std::setw(12) << type();
      out << " | " << std::setw(12) << usage();
      out << " | " << std::setw(6) << condition();
      out << " | " << std::setw(6) << std::fixed << std::setprecision(2) << m_topSpeed << " |" << std::endl;
   }


}

