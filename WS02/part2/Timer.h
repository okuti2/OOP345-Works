#pragma once
/* ------------------------------------------------------
Workshop 2 part 2
Module: Timer
Filename: Timer.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    24th September, 2022
-----------------------------------------------------------*/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

namespace sdds
{
	class Timer
	{
      std::chrono::time_point<std::chrono::steady_clock> m_startTime;
		std::chrono::time_point<std::chrono::steady_clock> end;
		std::chrono::duration<long long> m_endTime;
	public:
		void start();
		long long stop();
	};
}
#endif //! SDDS_TIMER_H


