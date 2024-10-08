// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 16th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;

namespace sdds
{
   size_t CustomerOrder::m_widthField = 0u; 

   CustomerOrder::CustomerOrder() {
      m_name = "";
      m_product = "";
      m_cntItem = 0u;
      m_lstItem = nullptr;
   }

   CustomerOrder::CustomerOrder(const std::string& str) {
      Utilities utility;
      size_t pos = 0u;
      bool more = true;
      m_name = utility.extractToken(str, pos, more);
      m_product = utility.extractToken(str, pos, more);

      while (more) { // if the end line is not found
         Item** temp = new Item * [m_cntItem + 1]; // attempted to use smart pointers but it did not work at all
         for (size_t i = 0u; i < m_cntItem; i++)
         {
            temp[i] = m_lstItem[i];
         }
         delete[] m_lstItem;
         m_lstItem = temp;
         m_lstItem[m_cntItem] = new Item(utility.extractToken(str, pos, more));
         m_cntItem++;
      }

      m_widthField = std::max(m_widthField, utility.getFieldWidth());
   }

   CustomerOrder::CustomerOrder(const CustomerOrder& custOrd) { // canot copy
      throw std::exception();
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& custOrd) noexcept {
      *this = std::move(custOrd);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src)noexcept {
      if (this != &src)
      {
         for (auto i = 0u; i < m_cntItem; i++) // had an error where I could not delete the itemlist without triogerring a read violation. I did not initialize values and set m_lstItem = nullptr
         {
            delete m_lstItem[i];
         }
         delete[] m_lstItem;

         m_name = src.m_name;
         m_product = src.m_product;
         m_cntItem = src.m_cntItem;
         m_lstItem = src.m_lstItem;

         src.m_name = "";
         src.m_product = "";
         src.m_lstItem = nullptr;
         src.m_cntItem = 0u;
      }
      return *this;
   }

   CustomerOrder::~CustomerOrder() {
      for (size_t i = 0u; i < m_cntItem; i++) {
         delete m_lstItem[i];
         m_lstItem[i] = nullptr;
      };
      delete[] m_lstItem;
   }

   auto CustomerOrder::isOrderFilled() const->bool {
      return std::all_of(m_lstItem, m_lstItem + m_cntItem, [=](Item* item) {
         return item->m_isFilled;
         });
   }

   auto CustomerOrder::isItemFilled(const std::string& itemName) const->bool {
      bool isFilled = false;
      unsigned sameName = 0;
      unsigned numOfFilled = 0;

      sameName = std::count_if(m_lstItem, m_lstItem + m_cntItem, [&](const Item* item) { // checks all the items in the pointer array if their names match the parameter
         return (item->m_itemName == itemName);
      });

      if (sameName == 0) {
         isFilled = true; 
      } else {
            std::for_each(m_lstItem, m_lstItem + m_cntItem, [&](const Item* item) { // counts how many of the itemName in the items are filled
            if (item->m_itemName == itemName && item->m_isFilled) {
               numOfFilled++;
            }
            });
         if (numOfFilled == sameName) isFilled = true;
      }
      return isFilled;
   }

   auto CustomerOrder::fillItem(Station& station, std::ostream& os)->void {
      bool filled = false;
      if (m_lstItem != nullptr) {
         for (size_t i = 0u; i < m_cntItem && !filled; i++) { // should only fill one item
            if (m_lstItem[i]->m_itemName == station.getItemName() && (!m_lstItem[i]->m_isFilled)) { // did not check if it was filled before and got horrible errors
               if (station.getQuantity() > 0) { // canot fill an item that is not in stock 
                  m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                  m_lstItem[i]->m_isFilled = true;
                  station.updateQuantity();
                  os << std::right << std::setw(11) << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                  filled = true;
               }
               else {
                  os <<std::right<< std::setw(19) << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
               }
            }
         }
      }
   }

   auto CustomerOrder::display(std::ostream& os) const -> void {
      os << m_name << " - " << m_product << "\n";
      for (size_t i = 0u; i < m_cntItem; i++)
      {
         os << "[" << std::setw(6)<<std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
         os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName
            << " - ";
         if (m_lstItem[i]->m_isFilled)
         {
            os << "FILLED\n";
         }
         else
            os << "TO BE FILLED\n";
      }
   }
}