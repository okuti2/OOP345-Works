/* ------------------------------------------------------
Workshop 3 part 2
Module: Dictionary
Filename: Dictionary.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    29th September, 2022
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

		virtual ~Dictionary(); // destructor
		bool operator==(const Dictionary& dictionary) const;
	};
	std::ostream& operator << (std::ostream& ostr, const Dictionary& dictionary); // insertion operator overload

}
#endif //! SDDS_DICTIONARY_H




