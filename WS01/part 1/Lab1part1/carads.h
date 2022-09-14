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
namespace sdds
{
	extern double g_taxrate;
	extern double g_discount;

	void listArgs(int argc, char* argv[], char* env[]);

	class Cars
	{
		char m_brandOfCar[10];
		char m_modelOfCar[15];
		int m_manYear;
		double m_priceOfCar;
		char m_statusOfCar;
		bool m_promDiscount;
	public:
		Cars();
		void read(std::istream& is);
		void display(bool reset) const;
		char getStatus() const;
		
	};


}
#endif //! SDDS_CARADS_H