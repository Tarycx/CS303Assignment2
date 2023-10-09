#pragma once
#include "Employee.h"


class Professional : public Employee {
private:
	double salary; //annual salary
	int vacation; //25 vacation days for professionals
	int monthsWorked; //months worked at company 





public:
	//constructors
	Professional();
	Professional(string n, int id, double s, int m, int v);

	//setters and getters
	double getSalary();
	int getMonthsWorked();
	void setSalary(double s);
	//void setVacation(int v);
	void setMonthsWorked(int m);
	void printInfo() const override;

	//virtual Employee required functions
	double calcWeeklySalary() const override;
	double healthCare() const override;
	int vacationDays() const override;



};
