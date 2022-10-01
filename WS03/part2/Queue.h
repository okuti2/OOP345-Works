/* ------------------------------------------------------
Workshop 3 part 2
Module: Queue
Filename: Queue.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    29th September, 2022
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
      unsigned m_count{ 0u };
      static T m_empty;
   public:
      Queue() {
         m_count = 0;
      }

      virtual ~Queue() {};

      //a mutator that adds a copy of the parameter to the queue if there still is capacity. If the item has been added, this function return true; false otherwise.
      virtual bool push(const T& item) {
         bool result = false;
         if (m_count < CAPACITY) {
            m_object[m_count] = item;
            m_count++;
            result = true;
         }
         return result;
      }

      // a mutator that removes the first member of the queue. It creates a temporary copy of it and then shifts the rest of the queue elements forward by one index. This function returns a copy of the removed object.
      T pop() {
         T temp;
         temp = m_object[0];
         for (size_t i = 0; i < m_count; i++) {
            m_object[i] = m_object[i + 1];
         }
         m_count--;
         return temp;
      }

      unsigned size() const {
         return m_count;
      }

      T& operator[](unsigned i)
      {
         return i < CAPACITY ? m_object[i] : m_empty;
      }

      std::ostream& display(std::ostream& ostr = std::cout) const;

   };

   // initializing the static object
   template <typename T, unsigned CAPACITY>
   T Queue<T, CAPACITY>::m_empty = T{};

   //specialization
   template<>
   inline Dictionary Queue<Dictionary, 100u>::m_empty = Dictionary{ "Empty substitute", "Empty Term" };

   template <typename T, unsigned CAPACITY>
   std::ostream& Queue<T, CAPACITY>::display(std::ostream& ostr) const {
      ostr << "----------------------" << std::endl;
      ostr << "| Dictionary Content |" << std::endl;
      ostr << "----------------------" << std::endl;
      for (size_t i = 0; i < m_count; i++) {
         //ostr << i << std::endl;
         ostr << m_object[i] << std::endl;
      }
      ostr << "----------------------" << std::endl;
      return ostr;
   };

}
#endif //! SDDS_QUEUE_H

