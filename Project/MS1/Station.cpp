// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "Station.h"
#include <iostream>
#include <iomanip>

namespace sdds
{
   Station::Station(const std::string& str) {
      // yet to be implemented 
   }

   auto Station::getItemName() const -> const std::string& {
      return m_name;
   }

   auto Station::getNextSerialNumber()->size_t {
      return m_nextSerialNum;
   }

   auto Station::getQuantity() const->size_t {
      return m_itemsInStock;
   }

   auto Station::updateQuantity() -> void {
     (m_itemsInStock - 1) > 0 ? m_itemsInStock-- : m_itemsInStock = 0;
   }

   auto Station::display(std::ostream& os, bool full)const -> void {

         os << std::setw(3) << m_id << "|"; 
         os << std::setw(m_widthField) << m_name << "|";
         os << std::setw(6) << m_nextSerialNum << "|"; 
         if (full) {
            os << std::setw(4) << m_itemsInStock << "|";
            os << m_description << std::endl;
         }
         else {
            os << std::endl;
         }
   }

   auto Station::trim(std::string& str) const -> void { 
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }
}