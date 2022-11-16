// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion:
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
      size_t m_nextSerialNum;
      size_t m_itemsInStock;

      static size_t m_widthField;
      static size_t id_generator;
   public:
      Station(const std::string& str);
      auto getItemName() const -> const std::string&;
      auto getNextSerialNumber() ->size_t;
      auto getQuantity() const->size_t;
      auto updateQuantity() -> void;
      auto display(std::ostream& os, bool full)const -> void;
      auto trim(std::string& str) const -> void;


   };

}
#endif