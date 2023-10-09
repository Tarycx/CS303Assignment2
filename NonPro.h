#pragma once
#include "Employee.h"
#include <iostream>
#include <string>



class NonPro : public Employee {
private:
	double hourlyRate; //hourly pay
	int weeklyHours; //hours worked for the year;
	int weeksWorked; //weeks worked for the year;

public:
	NonPro();
	NonPro(string n, int id, double hr, int wh, int ww);

	void printInfo() const override;

	void setHourlyRate(double hr);
	void setWeeklyHours(int wh);
	void setWeeksWorked(int ww);
	double getHourlyRate();
	int getWeeklyHours();
	int getWeeksWorked();




	//required virtual funcitons
	double calcWeeklySalary() const override;
	double healthCare() const override;
	int vacationDays() const override;


};