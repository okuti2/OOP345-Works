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
      m_cntItem = 0;
      m_lstItem = nullptr;
   }

   CustomerOrder::CustomerOrder(const std::string& str) {
      Utilities utility;
      size_t pos = 0;
      bool more = true;
      m_name = utility.extractToken(str, pos, more);
      m_product = utility.extractToken(str, pos, more);

      while (more) {
         Item** temp = new Item * [m_cntItem + 1];
         for (size_t i = 0; i < m_cntItem; i++)
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

   CustomerOrder::CustomerOrder(const CustomerOrder& custOrd) {
      throw std::exception();
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& custOrd) noexcept {
      *this = std::move(custOrd);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src)noexcept {
      if (this != &src)
      {
         for (auto i = 0u; i < m_cntItem; i++)
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
      for (size_t i = 0; i < m_cntItem; i++) {
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

      sameName = std::count_if(m_lstItem, m_lstItem + 1, [=](const Item* item) {
         return (item->m_itemName == itemName);
      });

      if (sameName == 0) {
         isFilled = true;
      } else {
            std::for_each(m_lstItem, m_lstItem + m_cntItem, [&](const Item* item) {
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
         for (size_t i = 0; i < m_cntItem && !filled; i++) {
            if (m_lstItem[i]->m_itemName == station.getItemName()) {
               if (station.getQuantity() > 0) {
                  m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                  m_lstItem[i]->m_isFilled = true;
                  station.updateQuantity();
                  os << std::right << std::setw(11) << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                  filled = true;
               }
               else {
                  os << std::setw(19) << "Unable to fill" << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]";
               }
            }
         }
      }
   }

   auto CustomerOrder::display(std::ostream& os) const -> void {
      os << m_name << " - " << m_product << "\n";
      for (size_t i = 0; i < m_cntItem; i++)
      {
         os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
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