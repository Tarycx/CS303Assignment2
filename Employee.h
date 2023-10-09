#pragma once
#include <iostream>
#include <string>
using namespace std;


//Abstract Employee class, base class for professional and nonprofessional
class Employee {

protected:
	int numEmployees;
	int employeeID; //act as numEmployees
	string name;




public: 
	
	Employee();
	Employee(string n, int id);

	
	string getName();
	int getID();
	void setName(string n);
	void setID(int id);

	virtual void printInfo() const;

	//Employee required functions
	virtual double calcWeeklySalary() const = 0;
	virtual double healthCare() const = 0;
	virtual int vacationDays() const = 0;

	

};
