/* ------------------------------------------------------
Workshop 3 part 1
Module: Dictionary
Filename: Dictionary .cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    26th September, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Queue.h"
#include "Dictionary.h"

using namespace std;

namespace sdds
{
   //Constructor
   Dictionary::Dictionary() {
      m_definition = "";
      m_definition = "";
   };

   ////copy constructor
   //Dictionary::Dictionary(const Dictionary& dnary) {
   //   *this = dnary;
   //}

   ////copy assignment operator
   //Dictionary& Dictionary::operator=(const Dictionary& dnary) {
   //   if (this != &dnary) {
   //      if (dnary.m_term != ""){ // not sure if this will give my read violation incase it is not in
   //         m_definition = dnary.m_definition;
   //            m_term = dnary.m_term;
   //      }
   //   }
   //   return *this;
   //}

   ////move constructor
   //Dictionary::Dictionary( Dictionary&& dnary) noexcept {
   //   *this = move(dnary);
   //}

   ////move assignment
   //Dictionary& Dictionary::operator=(Dictionary&& dnary) noexcept {
   //   if (this != &dnary) {
   //      //if (dnary.m_term != "") { // not sure if this will give my read violation incase it is not in
   //         m_definition = dnary.m_definition;
   //         dnary.m_definition = "";
   //         m_term = dnary.m_term;
   //         dnary.m_term = "";
   //   }
   //   return *this;
   //}


   //Destructor
   Dictionary::~Dictionary() {
      m_definition = "";
      m_term = "";
   };

   // needs << overload operator 
}