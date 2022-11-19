/* ------------------------------------------------------
Workshop 8 part 1
Module: WritingRecord
Filename: WritingRecord.cpp
Version 1
Author:	Olutoyosi Kuti; 102633211; okuti2@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date    18th November, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		// using raw pointers
		bool validate = false;
		for (size_t i = 0u; i < emp.size(); i++)
		{
			for (size_t j = 0u; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{
					validate = activeEmp.validateSIN(sal[j].id);
					if (validate)
					{
						EmployeeWage* empWage = new EmployeeWage(emp[i].name, sal[j].salary);
						try
						{
							empWage->rangeValidator();
							activeEmp += empWage;
							delete empWage;
						}
						catch (std::string msg)
						{
							delete empWage;
							throw;
						}
					}
					else {
						throw std::string("*** Employee SIN is not valid");
					}
				}
				
			}
		}		
		return activeEmp;
	}
}