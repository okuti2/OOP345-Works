/* ------------------------------------------------------
Workshop 3 part 1
Module: Queue
Filename: Queue.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    26th September, 2022
-----------------------------------------------------------*/
#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include<iostream>
#include<iomanip>
#include<string>
#include <string.h>
#include<cstring>
#include "Dictionary.h"

namespace sdds
{
   template <typename T, unsigned CAPACITY>
   class Queue
   {
      T m_object[CAPACITY]{};
      static unsigned m_count{0u};
      static T m_empty;
      

   public:
      Queue() {
         ++m_count
      }

      virtual ~Queue() {
         --m_count
      }

      //a mutator that adds a copy of the parameter to the queue if there still is capacity. If the item has been added, this function return true; false otherwise.
      bool push(const T& item) {
         bool result = false;
         if (m_count < CAPACITY) {
            ++m_count;
            m_object[m_count] = item;
            result = true;
         }
         return result;
      }

      // a mutator that removes the first member of the queue. It creates a temporary copy of it and then shifts the rest of the queue elements forward by one index. This function returns a copy of the removed object.
      Queue& pop() {
         T temp;
         temp = m_object[0];
         for (size_t i; i < m_count; i++) {
            m_object[i] = m_object[i + 1];
         }
         return temp;
      }

      const static unsigned size()const {
         return m_count;
      }

      std::ostream& display(std::ostream& ostr = std::cout) const;

      T& operator[](unsigned i)
      {
         return i < CAPACITY ? m_object[i] : m_empty;
      }
   };

   template <typename T, unsigned CAPACITY>
   unsigned Queue<T, CAPACITY>::m_count = 0u;

   //specialization
   template<> 
   Dictionary Queue<Dictionary, 100u>::m_empty = Dictionary{ "Empty substitute", "Empty Term" };

   template <typename T, unsigned CAPACITY>
   std::ostream& Queue<T,CAPACITY>::display(std::ostream& ostr) const {
      ostr << "----------------------\n";
      ostr << "| Dictionary Content |\n";
      ostr << "----------------------\n";
      for (size_t i; i < CAPACITY; i++) {
         ostr << T[i] << "\n";
      }
      ostr << "----------------------\n";
      return ostr;
   };
   
      
}
#endif //! SDDS_QUEUE_H
