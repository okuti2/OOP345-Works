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
#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include<iostream>
#include<iomanip>
#include<string>
#include <string.h>
#include<cstring>
#include "Dictionary.h"
#include "Queue.h"

namespace sdds
{
   template <typename T>
   class UniqueQueue : public Queue<T, 100u>
   {
   public:
      UniqueQueue() {};
      virtual ~UniqueQueue() {};
      bool push(const T& item);
   };

   template <typename T>
   bool UniqueQueue<T>::push(const T& item) {
      bool result = false;
      bool copy = false;
      unsigned count = Queue<T, 100u>::size();
      count++;
      for (unsigned i = 0; i < count; i++)
      {
         if (Queue<T, 100u>::operator[](i) == item) {
            copy = true;
         }
      }
      if (copy == false) result = Queue<T, 100u>::push(item);
      return result;
   };

   template<>
   inline bool UniqueQueue<double>::push(const double& item) {
      bool result = false;
      bool copy = false;
      double difference = 0.005;
      unsigned count = Queue<double, 100u>::size();
      if (Queue<double, 100u>::size() < 100) count++;

      for (unsigned i = 0; i < count && copy == false; i++)
      {
         if (std::abs(Queue<double, 100u>::operator[](i) - item)<= difference) {
            copy = true;
         }
      }
      if (copy == false) result = Queue<double, 100u>::push(item);

      return result;
   }

   template <typename T>
   std::ostream& operator<<(std::ostream& ostr, Queue<T, 100u>& queue ) {
      queue.display(ostr);
      return ostr;
   }

   
}

#endif //! SDDS_UNIQUEQUEUE_H


