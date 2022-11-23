// Name: Olutoyosi Kuti
// Seneca Student ID: 102633211
// Seneca email: okuti2@myseneca.ca
// Date of completion: 16th November 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <string>
#include <memory>
#include "Station.h"



namespace sdds
{
   class CustomerOrder
   {
      struct Item
      {
         std::string m_itemName;
         size_t m_serialNumber{ 0 };
         bool m_isFilled{ false };

         Item(const std::string& src) : m_itemName(src) {};
      };

      std::string m_name; // customer name
      std::string m_product; // name of the product being assembled 
      size_t m_cntItem; // count of the number of items in the customer's order
      Item** m_lstItem; // Each element of the array points to a dynamically allocated object of type Item

      static size_t m_widthField; // the maximum width of a field, used for display purposes
   public:
      CustomerOrder();
      CustomerOrder(const std::string& str);
      CustomerOrder(const CustomerOrder& custOrd); // copy constructor
      CustomerOrder& operator=(const CustomerOrder& custOrd) = delete; // copy assignment operator
      CustomerOrder(CustomerOrder&& custOrd) noexcept;
      CustomerOrder& operator=(CustomerOrder&& custOrd)noexcept;
      ~CustomerOrder();
      auto isOrderFilled() const->bool;
      auto isItemFilled(const std::string& itemName) const->bool;
      auto fillItem(Station& station, std::ostream& os)->void;
      auto display(std::ostream& os) const -> void;
   };


}
#endif