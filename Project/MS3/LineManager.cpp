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
#include "Utilities.h"

namespace sdds
{
   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
      std::ifstream readFile(file);
      if (readFile)
      {
         while (!readFile.eof())
         {
            try
            {
               size_t next_pos = 0u;
               bool more = true;
               std::string temp, first = "", next = "";
               Utilities utility;
               std::getline(readFile, temp);
               first = utility.extractToken(temp, next_pos, more);
               if (more)
               {
                  next = utility.extractToken(temp, next_pos, more);
               }

               std::for_each(stations.begin(), stations.end(), [&](Workstation* ws)
                  {
                     if (ws->getItemName() == first)
                     {
                        if (next != "")
                        {
                           auto it = std::find_if(stations.begin(), stations.end(), [&](Workstation* nextStation)
                              { return nextStation->getItemName() == next; });
                           ws->setNextStation(*it);
                        }
                        else
                        {
                           ws->setNextStation();
                        }
                        m_activeLine.push_back(ws);
                     } });
            }
            catch (const std::exception& e)
            {
               std::cerr << e.what() << '\n';
            }
         }
         std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws)
            {
               int find = std::count_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ls) { return ws == ls->getNextStation() || ws->getNextStation() == nullptr; });
               if (find == 0) {
                  m_firstStation = ws;
               } });
         m_cntCustomerOrder = g_pending.size();
      }
   }

   auto LineManager::reorderStations()-> void {
       Workstation* ws = m_firstStation;

      std::transform(m_activeLine.begin(),m_activeLine.end(), m_activeLine.begin(), [&ws](Workstation* wkstation) {
         if(ws!= nullptr){
            wkstation = ws;
            ws = ws->getNextStation();
         }
         return wkstation;
      });
   };

   auto LineManager::run(std::ostream& os)-> bool {
      static size_t iterationNo = 0;
      os << "Line Manager Iteration: " << ++iterationNo << std::endl;

      if (!g_pending.empty()) {
         *m_firstStation += std::move(g_pending.front());
         g_pending.pop_front();
      }

      for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* ws) {
         ws->fill(os); // issue here 
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