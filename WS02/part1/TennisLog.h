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
		unsigned m_matchId{0};
		std::string m_winner{};
		std::string m_loser{};
		operator bool() const; // checks if the object is in a safe and empty state
		TennisMatch();
	};
	std::ostream& operator << (std::ostream& ostr, const TennisMatch& tm); // insertion operator overload

	class TennisLog
	{
		TennisMatch* m_tennisMatch{};
	public:
		TennisLog() {}; // default constructor
		TennisLog(const std::string& filename);
		~TennisLog();
		void addMatch();
		TennisLog& findMatches() const;
		TennisMatch& operator[](size_t);
		operator size_t();
	};

}
#endif //! SDDS_TENNISLOG_H
