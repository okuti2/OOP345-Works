/* ------------------------------------------------------
Workshop 1 part 1
Module: Carads
Filename: carads.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    12th September, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "carads.h"
using namespace std;

namespace sdds
{
	void listArgs(int argc, char* argv[], char* env[]) {
		cout << "Command Line:" << endl;
		cout << "--------------------------" << endl;
		cout << "1: "<< argc << endl;
		cout << "2: " << argv << endl;
		cout << "3: " << env << endl;
		cout << "4: ..." << endl;
	}
}
