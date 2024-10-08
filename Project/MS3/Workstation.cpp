// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 28th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <deque>
#include "Workstation.h"

namespace sdds
{
   std::deque<CustomerOrder> g_pending{}; //holds the orders to be placed onto the assembly line at the first station.
   std::deque<CustomerOrder> g_completed{}; //holds the orders that have been removed from the last station and have been completely filled.
   std::deque<CustomerOrder> g_incomplete{}; //holds the orders that have been removed from the last station and could not be filled completely.

   Workstation::Workstation(const std::string& str) : Station(str) {}

   auto Workstation::fill(std::ostream& os)->void { //fills the order infront of the queue if there are customerOrder
      if (!m_orders.empty()) {
         m_orders.front().fillItem(*this, os);
      }
   };

   auto Workstation::attemptToMoveOrder()-> bool {//attempts to move the order at the front of the queue to the next station in the assembly line
      bool orderMoved = false;
      if (!m_orders.empty()) {
         if (m_orders.front().isItemFilled(getItemName())|| !getQuantity()) { // the order has to be filled or empty to move to the next station
            if (!m_pNextStation) {
               if (m_orders.front().isOrderFilled()) {
                  g_completed.push_back(std::move(m_orders.front()));
               }
               else {
                  g_incomplete.push_back(std::move(m_orders.front()));
               }
            }
            else {
               *m_pNextStation += std::move(m_orders.front());
            }
             m_orders.pop_front(); // should pop regardless of what happened. Did not do this and the program stopped at fillOrders
               orderMoved = true;
         }
      }
      return orderMoved;
   };

   auto Workstation::setNextStation(Workstation* station)-> void {
      m_pNextStation = station;
   };

   auto Workstation::getNextStation() const->Workstation* {
      return m_pNextStation;
   };

   auto Workstation::display(std::ostream& os) const -> void {
      if (m_pNextStation != nullptr) {
         os << getItemName() << " --> " << m_pNextStation->getItemName();
      }
      else {
         os << getItemName() << " --> End of Line";
      }
      os << std::endl;
   };

   auto Workstation::operator+=(CustomerOrder&& newOrder)->Workstation& {
      m_orders.push_back(std::move(newOrder));
      return *this;
   };

}