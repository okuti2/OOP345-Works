/* ------------------------------------------------------
Workshop 2 part 1
Module: TennisLog
Filename: TennisLog.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    19th September, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "TennisLog.h"

using namespace std;
//static int numOfMatches = -1; if I use this take away the numOfMatches--
//static int numOfMatches{ 0 };


namespace sdds
{ 
	int TennisLog::m_numOfMatches{ 0 }; // look at Fardad's Lab notes for today

	TennisLog::TennisLog() {
		//m_tennisMatch = nullptr;
		m_tennisMatch->m_tournamentId = {};
		m_tennisMatch->m_tournamentName = {};
		m_tennisMatch->m_matchId = 0;
		m_tennisMatch->m_winner = {};
		m_tennisMatch->m_loser = {};
	}

	TennisLog::TennisLog(const char*filename) {
		string line;
		ifstream file(filename);
		while (getline(file,line))
			++m_numOfMatches; // counts the number of newlines in the csv file
		m_numOfMatches--;
		
		delete[] m_tennisMatch;
		m_tennisMatch = new TennisMatch[m_numOfMatches+1]; // why does removing the +1 take away the error from m_tennisMatch[i].m_tournamentId = line;
		
		file.seekg(0, ios::beg); //takes is back to the beginning of the file to read the data
		file.ignore(2000, '\n'); //extracts the newline character

		
		for (int i = 0; i < m_numOfMatches; i++) {
			if (file && !m_tennisMatch) {
				getline(file, line, ',');
				m_tennisMatch[i].m_tournamentId = line;
				file.ignore();
				line.clear();
				getline(file, line, ',');
				m_tennisMatch[i].m_tournamentName = line;
				file.ignore();
				line.clear();
				file >> m_tennisMatch[i].m_matchId;
				file.ignore();
				getline(file, line, ',');
				m_tennisMatch[i].m_winner = line;
				file.ignore();
				line.clear();
				getline(file, line, ',');
				m_tennisMatch[i].m_loser = line;
				file.ignore(2000, '\n'); //extracts the newline character
			}
		}
	}

	TennisLog::TennisLog(const TennisLog& tLog) {
		*this = tLog;
	}

	TennisLog& TennisLog::operator=(const TennisLog& tennisLog) {
		if (this != &tennisLog) {
			if (m_numOfMatches != 0) {
				for (int i = 0; i < tennisLog.m_numOfMatches; i++) {
					m_tennisMatch[i] = tennisLog.m_tennisMatch[i];
				}
				m_numOfMatches = tennisLog.m_numOfMatches;
			}
		}
		return *this;
	}

	void TennisLog::addMatch(TennisMatch& TM) {
		if (TM.m_tournamentId[0] != '\0') {
			m_numOfMatches++;
			m_tennisMatch[m_numOfMatches].m_tournamentId = TM.m_tournamentId;
			m_tennisMatch[m_numOfMatches].m_tournamentName= TM.m_tournamentName;
			m_tennisMatch[m_numOfMatches].m_matchId = TM.m_matchId;
			m_tennisMatch[m_numOfMatches].m_winner= TM.m_winner;
			m_tennisMatch[m_numOfMatches].m_loser= TM.m_loser;
		}
	}

	TennisLog& TennisLog::findMatches(const char* name) const{
		TennisLog Matches;
		for (int i = 0; i < m_numOfMatches; i++) {
			if (strcmp(name, m_tennisMatch[i].m_loser.c_str()) == 0 || strcmp(name, m_tennisMatch[i].m_winner.c_str()) == 0) {
				int matches = 0;
				Matches.addMatch(m_tennisMatch[i]);
			}
		}
		return Matches;
	}

	TennisMatch& TennisLog::operator[](size_t i) const {
		/*if (&m_tennisMatch[i] != nullptr) {
			return m_tennisMatch[i];
		}
		else {
			TennisMatch emptyMatch{};
			return emptyMatch;
		}*/

		TennisMatch Result{};
		if (i <= this->operator size_t()) {
			Result = m_tennisMatch[i];
		}
		return Result;
	}

	TennisLog::operator size_t() const
	{
		return m_numOfMatches;
	}

	TennisLog::~TennisLog() {
		size_t num = m_numOfMatches;
		for (size_t i = 0; i < num; i++) {
			delete[] &m_tennisMatch[i];
			m_numOfMatches--;
		}
	}

	/*TennisMatch::TennisMatch(const char* tourneyId, const char* tourneyName, int matchID, const char* winner, const char* loser): m_tournamentId(tourneyId)  {
		if (tourneyId != nullptr) {
			m_tournamentId = tourneyId;
			m_tournamentName = tourneyName;
			m_matchId = matchID;
			m_winner = winner;
			m_loser = loser;
		}
	}
	*/
	// returns true if it is not empty
	TennisMatch::operator bool() const {
		bool ans;
		m_tournamentId.c_str() != nullptr? ans =  true : ans = false;
		return ans;
	}

	ostream& operator<<(std::ostream& ostr, const TennisMatch& TM)
	{
		if (TM) {
			ostr << right << setfill('.') << setw(20) << "Tourney ID : ";
			ostr << left << setw(30) << TM.m_tournamentId << endl;
			ostr << right << setfill('.') << setw(20) << "Match ID : ";
			ostr << left << setw(30) << TM.m_matchId << endl;
			ostr << right << setfill('.') << setw(20) << "Tourney : ";
			ostr << left << setw(30) << TM.m_tournamentName<< endl;
			ostr << right << setfill('.') << setw(20) << "Winner : ";
			ostr << left << setw(30) << TM.m_winner<< endl;
			ostr << right << setfill('.') << setw(20) << "Loser : ";
			ostr << left << setw(30) << TM.m_loser<< endl;
		}
		else {
			ostr << "Empty Match";
		}
		return ostr;
	}

}