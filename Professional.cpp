#include "Professional.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

/// <summary>
/// Test all funcitons
/// </summary>

Professional::Professional() : Employee() {
	salary = 0.0; //annual salary
	vacation = 0;
	monthsWorked = 0;
	
}

Professional::Professional(string n, int id, double s = 50000.0, int m = 0, int v = 25) : Employee(n, id) {
	salary = s; //annual salary
	monthsWorked = m;// months worked at company
	vacation = v; //vacation days
}

void Professional::printInfo() const {
	cout << "Employee: " << name << endl;
	cout << "ID: " << employeeID << endl;
	cout << "Employee Type: Professional" << endl;
	cout << "Annual Salary: " << salary << endl;
	cout << "Weekly Salary: " << fixed << setprecision(2) << calcWeeklySalary() << endl; //Test setprecison
	cout << "Vacation Days: " << vacationDays() << endl;
	cout << "Annual Healthcare Contribition: " << fixed << setprecision(2) << healthCare() << endl;
}



void Professional::setSalary(double s) {
	salary = s;
}

void Professional::setMonthsWorked(int m) {
	monthsWorked = m;
}

double Professional::getSalary() {
	return salary;
}

int Professional::getMonthsWorked() {
	return monthsWorked;
}



//required virtual funcitons

//returnss weekly salary taking annual salary divided by 52 weeks
double Professional::calcWeeklySalary() const {
	return salary / 52.0; 
}

//annaul healthcare benefits contribution
double Professional::healthCare() const {
	if (monthsWorked <= 18) { //1.5 years contribution
		return 5500.0;
	}
	else if (monthsWorked <= 36) {// 3 year contribution
		return 7500.0;
	}
	else if (monthsWorked > 36) {// greater than 3 years contrubiton
		return 9000.0;
	}
	
}	

int Professional::vacationDays() const {
	return vacation; //returns standard 25 days for pro employees
}




