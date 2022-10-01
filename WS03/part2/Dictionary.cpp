/* ------------------------------------------------------
Workshop 3 part 2
Module: Dictionary
Filename: Dictionary .cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    29th September, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include "Dictionary.h"

using namespace std;

namespace sdds
{
   //Constructor
   Dictionary::Dictionary() {
      m_definition = "";
      m_definition = "";
   };

   //Destructor
   Dictionary::~Dictionary() {
      m_definition = "";
      m_term = "";
   };

   bool Dictionary::operator==(const Dictionary& dictionary) const
   {
      return m_term == dictionary.m_term;
   }

   // needs << overload operator 
   ostream& operator<<(std::ostream& ostr, const Dictionary& dictionary)
   {
      if (&dictionary.getTerm()){
         ostr << setw(20) << right << dictionary.getTerm() << ": " << dictionary.getDefinition();
      }
      
      return ostr;
   }
}