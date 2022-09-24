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
   TennisLog::TennisLog() {
      m_tennisMatch = nullptr;
      m_tennisMatch = new TennisMatch[m_numOfMatches + 1];
      if (m_numOfMatches == 0) {
         m_tennisMatch[0].m_tournamentId[0] = '\0';
         m_tennisMatch[0].m_tournamentName[0] = '\0';
         m_tennisMatch[0].m_matchId = 0;
         m_tennisMatch[0].m_winner[0] = '\0';
         m_tennisMatch[0].m_loser[0] = '\0';
      }
   }

   TennisLog::TennisLog(const char* filename) {
      string line;
      ifstream file(filename);
      while (getline(file, line))
      ++m_numOfMatches; // counts the number of newlines in the csv file
      m_numOfMatches--;

      delete[] m_tennisMatch;
      m_tennisMatch = new TennisMatch[m_numOfMatches + 1]; 

      file.close();
      file.open(filename);
      file.ignore(2000, '\n'); // removes the header line

      for (size_t i = 0; i < m_numOfMatches; i++) {
         if (file) {
            getline(file, line, ',');
            m_tennisMatch[i].m_tournamentId = line;
            //file.ignore();
            line.clear();
            getline(file, line, ',');
            m_tennisMatch[i].m_tournamentName = line;
            //file.ignore();
            line.clear();
            file >> m_tennisMatch[i].m_matchId;
            file.ignore();
            getline(file, line, ',');
            m_tennisMatch[i].m_winner = line;
            //file.ignore();
            line.clear();
            getline(file, line, '\n');
            m_tennisMatch[i].m_loser = line;
         }
      }
   }

   TennisLog::TennisLog(const TennisLog& tLog) {
      *this = tLog;
   }

   TennisLog& TennisLog::operator=(const TennisLog& tennisLog) {
      if (this != &tennisLog) {
         delete[] m_tennisMatch;
         m_tennisMatch = new TennisMatch[tennisLog.m_numOfMatches + 1];
         if (tennisLog.m_numOfMatches != 0) {
            for (size_t i = 0; i < tennisLog.m_numOfMatches; i++) { // supposed to deep copy but I get a writing error
              /*m_tennisMatch[i].m_tournamentId = tennisLog.m_tennisMatch[i].m_tournamentId;
              m_tennisMatch[i].m_tournamentName = tennisLog.m_tennisMatch[i].m_tournamentName;
              m_tennisMatch[i].m_matchId = tennisLog.m_tennisMatch[i].m_matchId;
              m_tennisMatch[i].m_winner = tennisLog.m_tennisMatch[i].m_winner;
              m_tennisMatch[i].m_loser = tennisLog.m_tennisMatch[i].m_loser;*/
               m_tennisMatch[i] = tennisLog.m_tennisMatch[i];
            }

            //m_tennisMatch = tennisLog.m_tennisMatch; //only does a shallow copy ?
            m_numOfMatches = tennisLog.m_numOfMatches;
         }
      }
      return *this;
   }

   void TennisLog::addMatch(TennisMatch& TM) {
      if (TM.m_tournamentId[0] != '\0') {
         TennisMatch* temp = new TennisMatch[m_numOfMatches+1];
         if (m_numOfMatches == 0) {
            m_numOfMatches++;
            temp[0] = TM;
         }
         else {
            for (size_t i = 0; i < size_t(m_numOfMatches); i++) {

               temp[i] = m_tennisMatch[i];
            }
            m_numOfMatches++;

            temp[m_numOfMatches-1].m_tournamentId = TM.m_tournamentId;
            temp[m_numOfMatches-1].m_tournamentName = TM.m_tournamentName;
            temp[m_numOfMatches-1].m_matchId = TM.m_matchId;
            temp[m_numOfMatches-1].m_winner = TM.m_winner;
            temp[m_numOfMatches-1].m_loser = TM.m_loser;
         }
         delete[] m_tennisMatch;
         m_tennisMatch = temp;
      }
   }

   TennisLog TennisLog::findMatches(const char* name) const {
      TennisLog Matches{};
      //Matches.m_tennisMatch = new TennisMatch[m_numOfMatches];
      for (size_t i = 0; i < m_numOfMatches; i++) {
         if (strcmp(name, m_tennisMatch[i].m_loser.c_str()) == 0 || strcmp(name, m_tennisMatch[i].m_winner.c_str()) == 0) {
            Matches.addMatch(m_tennisMatch[i]);
         }
      }
      return Matches;
   }

   TennisMatch TennisLog::operator[](size_t i) const {
      TennisMatch Result{};
      if (i >= 0 && i <= size_t(m_numOfMatches)) {
         Result = m_tennisMatch[i];
      }
      return Result;
   }

   TennisLog::operator size_t() const
   {
      return m_numOfMatches;
   }

   TennisLog::~TennisLog() {
      delete[] m_tennisMatch;
      m_tennisMatch = nullptr;
      m_numOfMatches = 0;
   }

   TennisMatch& TennisMatch::operator=(const TennisMatch& TM) {
      if (this != &TM) {
         if (TM.m_matchId != 0) {
            m_tournamentId = TM.m_tournamentId;
            m_tournamentName = TM.m_tournamentName;
            m_matchId = TM.m_matchId;
            m_winner = TM.m_winner;
            m_loser = TM.m_loser;
         }
      }
      return *this;
   }

   void TennisMatch::display(std::ostream& ostr)const {
      if (m_matchId != 0) {
         ostr << right << setfill('.') << setw(23) << "Tourney ID : ";
         ostr << left << setw(30) << m_tournamentId << endl;
         ostr << right << setfill('.') << setw(23) << "Match ID : ";
         ostr << left << setw(30) << m_matchId << endl;
         ostr << right << setfill('.') << setw(23) << "Tourney : ";
         ostr << left << setw(30) << m_tournamentName << endl;
         ostr << right << setfill('.') << setw(23) << "Winner : ";
         ostr << left << setw(30) << m_winner << endl;
         ostr << right << setfill('.') << setw(23) << "Loser : ";
         ostr << left << setw(30) << m_loser << endl;
      }
      else {
         ostr << "Empty Match";
      }
   }

   ostream& operator<<(std::ostream& ostr, const TennisMatch& TM)
   {
      TM.display(ostr);
      return ostr;
   }

}