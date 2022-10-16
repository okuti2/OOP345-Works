/* ------------------------------------------------------
Workshop 5 part 2
Module: Collection
Filename: Collection.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    14th October, 2022
-----------------------------------------------------------*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds
{
   template <typename T>
   class Collection
   {
      std::string m_name;
      T* m_items{};
      size_t m_size;
      void (*m_observer)(const Collection<T>&, const T&); // functor 
   public:
      Collection(const std::string& name);
      Collection(const Collection& src) = delete;
      Collection& operator=(const Collection& src) = delete;
      ~Collection();
      auto name() const-> const std::string& { // returns the name of the collection
         return m_name;
      };

      auto size() const -> size_t { // returns the size of the array m_items
         return m_size;
      };

      auto setObserver(void (*observer)(const Collection<T>&, const T&))-> void;
      auto operator+=(const T& item)->Collection<T>&;
      auto operator[](size_t idx) const->T&;
      auto operator[](const std::string& title) const->T*;
      //friend auto operator << (std::ostream& ostr, const Collection<T>& col)->std::ostream&;
   };

   template <typename T>
   Collection<T>::Collection(const std::string& name) {
      m_name = name;
      m_items = nullptr;
      m_observer = nullptr;
      m_size = 0u;
   }

   template <typename T> // destructor
   Collection<T>::~Collection() {
      delete[] m_items;
   };

   template <typename T>
   auto Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&))-> void {// stores the address of the callback function into the attribute
      m_observer = observer; // needs to store the address of the functor
   };

   template <typename T>
   auto Collection<T>::operator+=(const T& item)->Collection<T>& {
      bool isCopy = false;
      for (size_t i = 0; i < m_size && isCopy == false; i++) { // checks through the m_items array for a maych with the passed parameter
         if (m_items[i].title() == item.title()) {
            isCopy = true;
         }
      }

      if (isCopy == false) {
         T* temp = new T[m_size + 1]; // temp array to store the data in and add the new item into
         for (size_t i = 0; i < m_size; i++) { 
            temp[i] = m_items[i];
         }
         temp[m_size] = item;
         m_size++;
         if (m_observer != nullptr) { // observer function is called if the the observer has been registered, 
            m_observer(*this, item);
         }
         delete[] m_items;
         m_items = temp;
      }

      return *this;
   }

   template <typename T>
   auto Collection<T>::operator[](size_t idx) const->T& { // returns the item at index idx
      if (idx >= m_size) {
         throw std::out_of_range("Bad Index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
         /*OR
         std::string errMess = "Bad Index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
         throw std::out_of_range(errMess); */
      }
      return m_items[idx];
   }

   template <typename T>
   auto Collection<T>::operator[](const std::string& title) const->T* { // returns the address of the item with the same title as the title passed into the function or nullptr
      T* object = nullptr; // dummy object to hold the object if found or null pointer if not found
      bool found = false;
      for (size_t i = 0; i < m_size && !found; i++) {
         if (m_items[i].title() == title) {
            object = &m_items[i];
            found = true;
         }
      }
      return object;
   }

   template <typename T>
   auto operator << (std::ostream& ostr, const Collection<T>& col)->std::ostream& {
      for (size_t i = 0; i < col.size(); i++) {
         ostr << col[i];
      }
      return ostr;
   }



}
#endif



