/* ------------------------------------------------------
Workshop 1 part 2
Module: Carads
Filename: carads.h
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    14th September, 2022
-----------------------------------------------------------*/
#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

extern double g_taxrate; // taxrate, global variable
extern double g_discount; // dicsount global variable
namespace sdds
{


	void listArgs(int argc, char* argv[]); // lists out the arguments put into the program from the command line
	void alocpy(char*& destination, const char* source);


	class Cars
	{
		char* m_brandOfCar; // Brand of car
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

		//Rule of three
		Cars(const Cars& cars); // copy constructor
		Cars& operator=(const Cars& cars); // assignment operator
		virtual ~Cars(); // destructor, not sure if it should be virtual or not

		operator bool() const; // returns true if the car is new
	};
	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);


}
#endif //! SDDS_CARADS_H