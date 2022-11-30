// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 28th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include "LineManager.h"

namespace sdds
{
   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {

   }

   auto LineManager::reorderStations()-> void {
      Workstation* ws = m_firstStation;

      /*std::sort(m_activeLine.begin(), m_activeLine.end(), [&ws](Workstation* ws1, Workstation* ws2) {
         ws1 = ws;
         return ws2 == ws1->getNextStation();
      });*/ // NOT SURE if will work

      std::for_each(m_activeLine.begin(), m_activeLine.end(), [&ws](Workstation* activeLine) {
         activeLine = ws;
         ws = ws->getNextStation();
      });
   };

   auto LineManager::run(std::ostream& os)-> bool {
      static size_t iterationNo = 0;
      os << "Line Manager Iteration : " << iterationNo++ << std::endl;

      if (!g_pending.empty()) {
         *m_firstStation += std::move(g_pending.front());
         g_pending.pop_front();
      }

      for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* ws) {
         ws->fill(os);
      });

      for_each(m_activeLine.begin(), m_activeLine.end(), [](Workstation* ws) {
         ws->attemptToMoveOrder();
      });

      return (m_cntCustomerOrder == g_completed.size() + g_incomplete.size());

   };

   auto LineManager::display(std::ostream& os) const -> void {
      std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* work) {
         work->display(os);
      });
   };

}