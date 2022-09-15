/* ------------------------------------------------------
Workshop 1 part 1
Module: Carads
Filename: carads.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    12th September, 2022
-----------------------------------------------------------*/
#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

extern double g_taxrate; // taxrate, global variable
extern double g_discount; // dicsount global variable
namespace sdds
{
	

	void listArgs(int argc, char* argv[]); // lists out the arguments put into the program from the command line

	class Cars
	{
		char m_brandOfCar[10]; // Brand of car
		char m_modelOfCar[15]; // Model of the car
		int m_manYear; // manufacture year of car
		double m_priceOfCar; // price of car
		char m_statusOfCar; // New or Used car
		bool m_promDiscount; // Y or N for discount
	public:
		Cars(); // default constructor
		void read(std::istream& is); // reads files from the istream and stores the information into the Car Object
		void display(bool reset) const; // prints out the contents of the Car object
		char getStatus() const; // returns if the car is new or used 
		
	};

	
}
#endif //! SDDS_CARADS_H