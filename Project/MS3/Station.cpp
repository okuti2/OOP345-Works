// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 16th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "Station.h"
#include <iostream>
#include <iomanip>
#include "Utilities.h"

namespace sdds
{
   size_t Station::id_generator = 0u;
   size_t Station::m_widthField = 0u;

   Station::Station(const std::string& str) { // custom constructor that extracts all the tokens into the Station variables
      m_id = ++id_generator;
      Utilities utility; // temp utilities object
      size_t pos = 0u;
      bool more = true;
      m_name = utility.extractToken(str, pos, more);
      m_nextSerialNum = stoi(utility.extractToken(str, pos, more));
      m_itemsInStock = stoi(utility.extractToken(str, pos, more));
      m_widthField = std::max(m_widthField, utility.getFieldWidth());
      m_description = utility.extractToken(str, pos, more);
   }

   auto Station::getItemName() const -> const std::string& {
      return m_name;
   }

   auto Station::getNextSerialNumber()->size_t {
      return m_nextSerialNum++;
   }

   auto Station::getQuantity() const->size_t {
      return m_itemsInStock;
   }

   auto Station::updateQuantity() -> void { // reduces the quantity everytime it is called
      (m_itemsInStock - 1) > 0 ? m_itemsInStock-- : m_itemsInStock = 0;
   }

   auto Station::display(std::ostream& os, bool full)const -> void {
      os << std::right << std::setfill('0') << std::setw(3) << m_id << " | ";
      os << std::left << std::setfill(' ') << std::setw(m_widthField) << m_name << " | ";
      os << std::right << std::setfill('0') << std::setw(6) << m_nextSerialNum << " | ";
      if (full) {
         os << std::setfill(' ') << std::setw(4) << m_itemsInStock << " | ";
         os << m_description << std::endl;
      }
      else {
         os << std::endl;
      }
   }
}