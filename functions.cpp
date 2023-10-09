#include <iostream>
#include <string>
#include "functions.h"
#include "singleLinkedList.h"
#include "Employee.h"
#include "Professional.h"
#include "NonPro.h"

//Creates an pro employee
//Professional(string n, int id, double s, int m, int v);
Professional* createPro(int idVal) {
	string name;
	int id;
	double salary;
	int months;
	int vacation = 25; //defualt days for pros

	cout << "Enter employee last name: ";
	cin >> name;
	cout << endl;

	id = idVal;

	cout << "Enter salary amount: ";
	cin >> salary;
	cout << endl;

	cout << "Enter number of months worked at company: ";
	cin >> months;
	cout << endl;

	return new Professional(name, id, salary, months, vacation);

}

//Creates an nonpro employee
//NonPro(string n, int id, double hr, int wh, int ww);
NonPro* createNonPro(int idVal) {
	string name;
	int id;
	double hourlyRate;
	int weeklyHours;
	int weeksWorked;

	cout << "Enter employee last name: ";
	cin >> name;
	cout << endl;

	id = idVal;

	cout << "Enter hourly rate amount: ";
	cin >> hourlyRate;
	cout << endl;

	cout << "Enter number of hours worked per week ";
	cin >> weeklyHours;
	cout << endl;

	cout << "Enter number of weeks worked at company for the year (0-52): ";
	cin >> weeksWorked;
	cout << endl;

	return new NonPro(name, id, hourlyRate, weeklyHours, weeksWorked);

}

//Options for adding new Pro data to linked list
void linkedListOptionsP(Professional* newEmp, Linked& myList) {
	int index;
	char userInput = 'q';
	cout << "Choose what you would like to do with new employee data" << endl;
	cout << "1 - push_front " << endl;
	cout << "2 - push_back " << endl;
	cout << "3 - insert " << endl;
	cout << "q - Quit to Menu" << endl;
	cout << "Enter Choice: ";
	cin >> userInput;
	cout << endl;

	switch (userInput) {
		case('q'):
			return;
		case('1'):
			myList.push_front(newEmp);
			return;
		case('2'):
			myList.push_front(newEmp);
			return;
		case('3'):
			cout << "Choose index position to insert at: ";
			cin >> index; 
			cout << endl;
			myList.insert(newEmp, index);
			return;
		default:
			cout << "Invailed Response" << endl;
			return;


	}

}

//options for adding new NonPro data to linked list
void linkedListOptionsNP(NonPro* newEmp, Linked& myList) {
	int index;
	char userInput = 'q';
	cout << "Choose what you would like to do with new employee data" << endl;
	cout << "1 - push_front " << endl;
	cout << "2 - push_back " << endl;
	cout << "3 - insert " << endl;
	cout << "q - Quit to Menu" << endl;
	cout << "Enter Choice: ";
	cin >> userInput;
	cout << endl;

	switch (userInput) {

	case('q'):
		delete newEmp;
		return;

	case('1'):
		myList.push_front(newEmp);
		return;

	case('2'):
		myList.push_front(newEmp);
		return;

	case('3'):
		cout << "Choose index position to insert at: ";
		cin >> index;
		cout << endl;
		myList.insert(newEmp, index);
		return;

	default:
		cout << "Invailed Response" << endl;
		return;


	}

}


