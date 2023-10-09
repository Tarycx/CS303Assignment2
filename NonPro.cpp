
#include "NonPro.h"
#include <iostream>
#include <iomanip>
#include <string>


NonPro::NonPro() : Employee() {
	hourlyRate = 0.0; //hourly pay
	weeklyHours = 0; //hours worked per week
	weeksWorked = 0;
}

NonPro::NonPro(string n, int id, double hr, int wh, int ww) : Employee(n, id) {
	hourlyRate = hr; //pay rate for hour
	weeklyHours = wh; //hours worked
	weeksWorked = ww; //weeks worked
}

void NonPro::printInfo() const {
	cout << "Employee: " << name << endl;
	cout << "ID: " << employeeID << endl;
	cout << "Employee Type: Nonprofessional" << endl;
	cout << "Hourly Pay: " << hourlyRate << endl;
	cout << "Weeks Worked: " << weeksWorked << endl;
	cout << "Avarge Weekly hours: " << weeklyHours << endl;
	cout << "Weekly Salary: " << fixed << setprecision(2) << calcWeeklySalary() << endl; //Test setprecison
	cout << "Vacation Days: " << vacationDays() << endl;
	cout << "Annual Healthcare Contribition: " << fixed << setprecision(2) << healthCare() << endl;

}

//setters and getters for nonpro
void NonPro::setHourlyRate(double hr) {
	hourlyRate = hr;
}

void NonPro::setWeeklyHours(int wh) {
	weeklyHours = wh;
}
void NonPro::setWeeksWorked(int ww) {
	weeksWorked = ww;
}
double NonPro::getHourlyRate() {
	return hourlyRate;
}
int NonPro::getWeeklyHours() {
	return weeklyHours;
}
int NonPro::getWeeksWorked() {
	return weeksWorked;
}




//Required virtual functions:
double NonPro::calcWeeklySalary() const {
	double weekly;
	weekly = hourlyRate * weeklyHours;
	return weekly;
}


double NonPro::healthCare() const {
	int annualHours = (weeklyHours * weeksWorked);
		if (annualHours < 1000) {
			return 3500.0;
		}
		else if (annualHours < 1500) {
			return 4500.0;
		}
		else if (annualHours < 2000) {
			return 5500.0;
		}
		else {
			return 6500.0;
		}
		
	
	
}

int NonPro::vacationDays() const {
	//12 vaction hours for every 175 worked hours
	int annualHours;
	int vacationDays;
	annualHours = weeklyHours * weeksWorked;
	vacationDays = annualHours / 175;
	if (annualHours <= 175) {
		return 0;
	}
	else {
		return vacationDays; //out put vaction days
	}
		
}
