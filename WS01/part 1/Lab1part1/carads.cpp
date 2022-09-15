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
#include <iomanip>
#include <cstring>
#include "carads.h"
using namespace std;
double g_taxrate;
double g_discount;


namespace sdds
{
	void listArgs(int argc, char* argv[]) {
		cout << "Command Line:" << endl;
		cout << "--------------------------" << endl;
		for (int i = 0; i < argc; i++) {
			cout <<"  " << i + 1 << ": " << argv[i] << endl;
		}
		cout << "--------------------------\n"<<endl;
	}

	Cars::Cars() { // setting all members to a safe and empty state
		m_brandOfCar[0] = '\0';
		m_modelOfCar[0] = '\0';
		m_manYear = 0;
		m_priceOfCar = 0.0;
		m_statusOfCar = '\0';
		m_promDiscount = false;
	}

	void Cars::read(std::istream& is){
		char s{ 0 };
		char p{ 0 };
		if (!is.fail()) { //ensuring the istream is in a good state before data is accepted
			is >> s;
			if (s == 'N' || s == 'U') this->m_statusOfCar = s; //only N or U are allowed in the member
			is.ignore(); //extracting the ","
			is.getline(m_brandOfCar, 10, ',');
			is.getline(m_modelOfCar, 25, ',');
			is >> this->m_manYear;
			is.ignore(); //eating the comma
			is >> this->m_priceOfCar;
			is.ignore(); //eating the comma
			is >> p;
			this->m_promDiscount = (p == 'Y' ? true : false);
			is.ignore(2000, '\n'); //extracts the newline character
		}
	}
	
	void Cars::display(bool reset)const{
		static int Counter = 0;
		if (reset) Counter = 0; // if the argument passed is true we reset the counter to zero

		Counter++; // we start counting from the number 1

		if (m_brandOfCar[0] != '\0') {
			cout << left << setw(2) << Counter << ". ";
			cout << left << setw(10) << this->m_brandOfCar << "| ";
			cout << left << setw(15) << this->m_modelOfCar << "| ";
			cout << m_manYear<<" |";
			
			double priceTax = (this->m_priceOfCar) * (g_taxrate + 1); // calculate the price tax using the tax rate
			double specialPrice = priceTax - (priceTax* g_discount); // calculate the special price after the discount is applied 

			cout << right << setw(12) << setprecision(2) << fixed << priceTax<<"|";
			if (m_promDiscount) {
				cout << right << setw(12) << setprecision(2) << fixed << specialPrice << endl;
			}
			else {
				cout << endl;
			}
		}
		else {
			cout <<setw(2)<< Counter << ". " << "No Car" << endl;
		}

	}

	char Cars::getStatus()const{
		return m_statusOfCar;
	}






}
