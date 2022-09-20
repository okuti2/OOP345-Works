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


namespace sdds
{ 
	TennisLog::TennisLog(const std::string &filename) {
		static int numOfMatches = -1;
		string line;
		ifstream file(filename.c_str());
		while (file) numOfMatches += (file.get() == '\n');
		
		delete[] m_tennisMatch;
		m_tennisMatch = new TennisMatch[numOfMatches+ 1];
		
		file.seekg(0, ios::beg);
		file.ignore(2000, '\n'); //extracts the newline character

		
		for (int i = 0; i < numOfMatches; i++) {
			if (file) {
				getline(file, line, ',');
				m_tennisMatch[i].m_tournamentId = line;
				file.ignore();
				line.clear();
				getline(file, line, ',');
				m_tennisMatch[i].m_tournamentName= line;
				file.ignore();
				line.clear();
				getline(file, line, ',');
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

	TennisMatch::TennisMatch() {
		m_tournamentId = '\0';
		m_tournamentName = '\0';
		m_matchId = 0;
		m_winner = '\0';
		m_loser = '\0';
	}

	TennisMatch::operator bool() const
	{
		return (m_tournamentId.length() == 0 ? false : true);
	}

	ostream& operator<<(std::ostream& ostr, const TennisMatch& TM)
	{
		if (TM.operator bool()) {
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
			ostr << "Empty Match" << endl;
		}
		return ostr;
	}

}