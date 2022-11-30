// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 28th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"
namespace sdds
{
   extern std::deque<CustomerOrder> g_pending;
   extern std::deque<CustomerOrder> g_completed;
   extern std::deque<CustomerOrder> g_incomplete;

   class Workstation : public Station
   {
      std::deque<CustomerOrder> m_orders;
      Workstation* m_pNextStation = nullptr;
   public:
      Workstation(const std::string& str); // custom constructor
      Workstation(const Workstation& src) = delete; // can't copy
      auto operator=(const Workstation& src)->Workstation & = delete; // copy assignment
      Workstation(Workstation&& src) = delete; // move constructor
      auto operator= (Workstation && src)->Workstation & = delete; // move assignment
      auto fill(std::ostream& os)->void; //fills the order infront of the queue if there are customerOrder
      auto attemptToMoveOrder()-> bool; //attempts to move the order order at the front of the queue to the next station in the assembly line
      auto setNextStation(Workstation* station = nullptr)-> void;
      auto getNextStation() const-> Workstation*;
      auto display(std::ostream& os) const -> void;
      auto operator+=(CustomerOrder&& newOrder)->Workstation&;
   };
}
#endif