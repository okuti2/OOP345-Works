/* ------------------------------------------------------
Workshop 1 part 2
Module: Carads
Filename: carads.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    14th September, 2022
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
			cout << "  " << i + 1 << ": " << argv[i] << endl;
		}
		cout << "--------------------------\n" << endl;
	}

	Cars::Cars() { // setting all members to a safe and empty state
		m_brandOfCar = nullptr;
		m_modelOfCar[0] = '\0';
		m_manYear = 0;
		m_priceOfCar = 0.0;
		m_statusOfCar = '\0';
		m_promDiscount = false;
	}

	Cars::Cars(const Cars& cars) 
	{
		*this = cars;
	}

	Cars& Cars::operator=(const Cars& cars)
	{
		if (this != &cars) {
			if (cars.m_brandOfCar!= nullptr) {
				alocpy(m_brandOfCar, cars.m_brandOfCar); // re used this function from my milestone 5 in OOP244
				/*m_brandOfCar = new char[strlen(cars.m_brandOfCar) + 1];
				strcpy(m_brandOfCar, cars.m_brandOfCar);*/
				strncpy(m_modelOfCar, cars.m_modelOfCar, 15);
				m_manYear = cars.m_manYear;
				m_priceOfCar = cars.m_priceOfCar;
				m_promDiscount = cars.m_promDiscount;
			}
		}
		return *this;
	}
	Cars::~Cars() {
		delete[] m_brandOfCar;
		m_brandOfCar = nullptr;
	}

	void Cars::read(std::istream& is) {
		char s = '\0';
		char p = '\0';
		char carBrand[31];
		delete[] m_brandOfCar;
		m_brandOfCar = nullptr;
		if (!is.fail()) { //ensuring the istream is in a good state before data is accepted
			is >> s;
			if (s == 'N' || s == 'U') this->m_statusOfCar = s; //only N or U are allowed in the member. should add an else statement for if it is not N nor U
			is.ignore(); //extracting the ","
			is.getline(carBrand, 30, ',');
			alocpy(m_brandOfCar, carBrand); // re used this function from my milestone 5 in OOP244
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

	void Cars::display(bool reset)const {
		static int Counter = 0;
		if (reset) Counter = 0; // if the argument passed is true we reset the counter to zero

		Counter++; // we start counting from the number 1

		if (m_brandOfCar[0] != '\0') {
			cout << left << setw(2) << Counter << ". ";
			cout << left << setw(10) << this->m_brandOfCar << "| ";
			cout << left << setw(15) << this->m_modelOfCar << "| ";
			cout << m_manYear << " |";

			double priceTax = (this->m_priceOfCar) * (g_taxrate + 1); // calculate the price tax using the tax rate
			double specialPrice = priceTax - (priceTax * g_discount); // calculate the special price after the discount is applied 

			cout << right << setw(12) << setprecision(2) << fixed << priceTax << "|";
			if (m_promDiscount) {
				cout << right << setw(12) << setprecision(2) << fixed << specialPrice << endl;
			}
			else {
				cout << endl;
			}
		}
		else {
			cout << setw(2) << Counter << ". " << "No Car" << endl;
		}
	}

	char Cars::getStatus()const {
		return m_statusOfCar;
	}


	// returns true if the Car is new
	Cars::operator bool() const
	{
		return m_statusOfCar == 'N';
	}

	std::istream& operator>>(std::istream& is, Cars& car) {
		car.read(is);
		return is;
	}

	void operator>>(const Cars& car1, Cars& car2) {
		car2 = car1;
	}

	void alocpy(char*& destination, const char* source) {
		delete[] destination;
		destination = nullptr;
		if (source != nullptr)
		{
			destination = new char[strlen(source) + 1];
			strcpy(destination, source);
		}
	}
}
