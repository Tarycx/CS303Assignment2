
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;


Employee::Employee() {
	name = "NONE";
	employeeID = -1111;
	numEmployees = 0;
}


Employee::Employee(string n, int id) {
	name = n;
	employeeID = id;
	numEmployees = 1;
}


void Employee::printInfo() const {
	cout << "Employee: " << name << endl;
	cout << "ID Number: " << employeeID << endl;
}


string Employee::getName() {
	return name;
}

int Employee::getID() {
	return employeeID;
}

void Employee::setName(string n) {
	name = n;
}

void Employee::setID(int id) {
	employeeID = id;
}

//virtual int healthCare() const = 0;
//virtual int vacationDays() const = 0;