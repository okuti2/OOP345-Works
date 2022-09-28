/* ------------------------------------------------------
Workshop 3 part 1
Module: Dictionary
Filename: Dictionary.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    26th September, 2022
-----------------------------------------------------------*/
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include <string>

namespace sdds
{
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};

	public:
		const std::string& getTerm() const {
			return m_term;
		}
		const std::string& getDefinition() const {
			return m_definition;
		}
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{} // constructor
		Dictionary(); // default constructor 

		//Dictionary(const Dictionary& dictionary); //copy constructor
		//Dictionary& operator=(const Dictionary& dictionary); // copy assignment operator
		//Dictionary(Dictionary&& dictionary) noexcept; // move constructor
		//Dictionary& operator=(Dictionary&& dictionary); // move assignment operator
		virtual ~Dictionary(); // destructor

		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.
	};
	std::ostream& operator << (std::ostream& ostr, const Dictionary& dictionary); // insertion operator overload

}
#endif //! SDDS_DICTIONARY_H



