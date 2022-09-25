/* ------------------------------------------------------
Workshop 2 part 1
Module: TennisLog
Filename: TennisLog.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    19th September, 2022
-----------------------------------------------------------*/
#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include <string>

namespace sdds
{
	struct TennisMatch
	{
		std::string m_tournamentId{};
		std::string m_tournamentName{};
		unsigned m_matchId{ 0 };
		std::string m_winner{};
		std::string m_loser{};
		TennisMatch& operator=(const TennisMatch& TM); // assignment operator
		void display(std::ostream& ostr) const;
	};
	std::ostream& operator << (std::ostream& ostr, const TennisMatch& tm); // insertion operator overload

	class TennisLog
	{
		TennisMatch* m_tennisMatch{}; // holds an array of TennisMatch objects
		unsigned m_numOfMatches{ 0 };
	public:
		TennisLog(); // default constructor
		TennisLog(const char* filename); //reads the data from the file
		TennisLog(const TennisLog& tennisLog); // copy constructor
		TennisLog& operator=(const TennisLog& tennisLog); // copy assignment operator
		virtual ~TennisLog(); // destructor
		TennisLog(TennisLog&& src) noexcept;// move constructor
		TennisLog& operator=(TennisLog&& src) noexcept;// move assignment operator
		void addMatch(TennisMatch& TM);
		TennisLog findMatches(const char* name) const;
		TennisMatch operator[](size_t) const;
		operator size_t() const; // returns 
	};

}
#endif //! SDDS_TENNISLOG_H

