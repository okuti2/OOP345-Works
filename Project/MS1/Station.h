// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 16th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>

namespace sdds
{
   class Station
   {
      int m_id;
      std::string m_name;
      std::string m_description;
      unsigned m_nextSerialNum;
      unsigned m_itemsInStock;

      static size_t m_widthField; // max num of chars to print to the screen
      static size_t id_generator; // generates IDs for new instances
   public:
      Station(const std::string& str);
      auto getItemName() const -> const std::string&;
      auto getNextSerialNumber() ->size_t;
      auto getQuantity() const->size_t;
      auto updateQuantity() -> void;
      auto display(std::ostream& os, bool full)const -> void;
   };
   

}
#endif