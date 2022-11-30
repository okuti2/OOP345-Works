// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 28th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include "Workstation.h"
namespace sdds
{

   class LineManager
   {
      std::vector<Workstation*> m_activeLine;
      size_t m_cntCustomerOrder;
      Workstation* m_firstStation;
   public:
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);
      auto reorderStations()-> void;
      auto run(std::ostream& os)-> bool;
      auto display(std::ostream& os) const -> void;
      
   };
}
#endif