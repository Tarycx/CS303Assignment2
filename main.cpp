//CS303 Data Structures
//Assignment 2
//Thomas Reilly
//Instruction: Syed Jawad Hussain Shah
//Due: Tue Oct 10, 2023 11:59pm


#include <iostream>
#include <string>
#include "functions.h"
#include "singleLinkedList.h"
#include "Employee.h"
#include "Professional.h"
#include "NonPro.h"
using namespace std;


int main() {
	char userInput;
	int idCount = 1004; //Current last employee number
	Linked myList;

	//Creating employees for Linked List
	//Professional(string n, int id, double s, int m, int v);
	Professional* emp1 = new Professional("Johnson", 1001, 50000.0, 12, 25);
	//emp1->printInfo();
	//cout << endl;

	Professional* emp2 = new Professional("Adams", 1002, 55000.0, 20, 25);
	//emp2->printInfo();
	//cout << endl;

	NonPro* worker1 = new NonPro("Kuffman", 1003, 20.0, 35, 52);
	//worker1->printInfo();
	//cout << endl;

	NonPro* worker2 = new NonPro("Kendy", 1004, 15.0, 30, 40);
	//worker2->printInfo();
	//cout << endl;

	myList.push_back(emp1);
	myList.push_back(emp2);
	myList.push_back(worker1);
	myList.push_back(worker2);
	
	//Intro Inforamtion:
	cout << "CS303 Data Structures" << endl;
	cout << "Assignment 2" << endl;
	cout << "Name: Thomas Reilly" << endl;
	cout << "Instruction: Syed Jawad Hussain Shah" << endl;
	cout << "Due: Tue Oct 10, 2023 11:59pm" << endl << endl;

	
	while (true) {
		idCount++;
		cout << endl;
		cout << "Menu Options:" << endl;
		cout << "1 - Print List of Employee data" << endl;
		cout << "2 - Add/Create New Professional Employee(push/insert)" << endl;
		cout << "3 - Add/Create New Nonprofessional Employee(push/insert)" << endl;
		cout << "4 - Check if List is Empty (empty) " << endl; //Fix need?
		cout << "5 - Remove from Front of List (pop_front)" << endl;
		cout << "6 - Remove from Back of List (pop_back)" << endl;
		cout << "7 - Get First Value (front)" << endl;
		cout << "8 - Get Last Value (back)" << endl;
		cout << "9 - Remove Item from List (remove)" << endl;
		cout << "f - Find Index Position of Employee(find)" << endl;
		cout << "Q - Quit Program " << endl;
		cout << "Enter your selection: ";
		cin >> userInput;
		cout << endl;
		
		switch (tolower(userInput)) {
			case 'q':
				cout << "Have a nice day! GoodBye!" << endl;
				break;

			case '1':
				myList.printLinkedList();
				break;

			case '2':
				//myList.push_back(createPro(idCount));
				linkedListOptionsP(createPro(idCount), myList);
				break;

			case '3':
				//myList.push_back(createNonPro(idCount));
				linkedListOptionsNP(createNonPro(idCount), myList);
				break;

			case '4':
				if (myList.empty()) { cout << "List Empty" << endl; }
				else { cout << "List is not empty" << endl; }
				break;

			case '5': 
				myList.pop_front();
				break;

			case '6':
				myList.pop_back();
				break;

			case '7':
				myList.front()->printInfo();
				break;

			case '8':
				myList.back()->printInfo();
				break;

			case '9':
				int removeIndexPos;
				cout << "Enter Index Position to Remove: ";
				cin >> removeIndexPos;
				cout << endl;
				if (myList.remove(removeIndexPos)) { cout << "Removal Seccessful" << endl; }
				else { cout << "Removal Failed" << endl; }
				break;

			case 'f':
				int idToFind;
				cout << "Enter Employee ID Number to Find: ";
				cin >> idToFind;
				cout << endl;
				cout << "Index: " << myList.find(idToFind) << endl;
				cout << "List Size: " << myList.getListSize() << endl;
				cout << "*Falure if Index == Size" << endl;
				break;

			default:
				cout << "Invlid Choice" << endl;
				break;

		}

		if (tolower(userInput) == 'q') {
			cout << "Program Exited" << endl;
			break;
		}
	
	}


	

	/*cout << "Empty: " << myList.empty() << endl;//
	cout << "Size: " << myList.getListSize() << endl; //
	cout << "Find ID: "  << myList.find(1005) << endl;

	NonPro* worker3 = new NonPro("Oliva", 1004, 23.0, 30, 35);
	cout << endl;
	
	myList.insert(worker3, 2);
	cout << "Find ID: " << myList.find(1004) << endl;

	myList.printLinkedList();
*/



	/*///////////////////////////////////////////////////
	//LINKED LIST TESTING:
	Linked myList;
	dataType myName;
	cout << "Testing Start:" << endl << endl;
	cout << "List Size: " << myList.getListSize() << endl;


	//
	cout << "Testing1 push_back" << endl;
	myName.value = "Tom";
	myList.push_back(myName);

	myName.value = "Danny";
	myList.push_back(myName); 

	myName.value = "Oliva";
	myList.push_back(myName);

	myName.value = "Julie";
	myList.push_back(myName);

	cout << "Test Print 1:" << endl;

	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl;
	myList.getHeadTailVals();


	//
	cout << endl << "Testing2 push_front" << endl;
	myName.value = "Konxhe";
	myList.push_front(myName);

	myName.value = "Olson";
	myList.push_front(myName);

	cout << endl << "Test Print 2:" << endl;
	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl;
	myList.getHeadTailVals();

	//
	cout << endl << "Testing3 pop_front" << endl;
	myList.pop_front();
	myList.pop_front();
	cout << "Test print 3:" << endl;
	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl;
	myList.getHeadTailVals();

	//
	cout << endl << "Testing4 pop_back" << endl;
	myList.pop_back();
	myList.pop_back();
	cout << "Test print 4:" << endl;
	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl;
	myList.getHeadTailVals();

	////

	cout << endl << "Testing5 back and front" << endl;
	cout << "Front Value: " << myList.front().value << endl;
	cout << "Back Value: " << myList.back().value << endl;


	

	//
	cout << "Tesing6 empty" << endl;
	myList.pop_front();
	myList.pop_back();
	myList.pop_back();
	myList.pop_front();

	myList.empty();


	cout << "Test print 4:" << endl;
	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl;
	

	//
	cout << endl << "list was repopulated" << endl;
	cout << "Testing7 insert" << endl;
	myName.value = "Konxhe";
	myList.push_front(myName);

	myName.value = "Olson";
	myList.push_front(myName);

	myName.value = "Tom";
	myList.push_back(myName);

	myName.value = "Danny";
	myList.push_back(myName);

	myName.value = "Oliva";
	myList.push_back(myName);

	myName.value = "Julie";
	myList.push_back(myName);

	cout << "Pretest print 5:" << endl;
	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl << endl;

	//insert values:

	myName.value = "Ben";
	myList.insert(myName, 3);

	myName.value = "Stan";
	myList.insert(myName, 5);

	myName.value = "Kyle";
	myList.insert(myName, 0);

	myName.value = "Amanda";
	myList.insert(myName, -1);


	cout << "Test print 5:" << endl;
	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl;

	//
	cout << endl << "Testing8 remove" << endl;//FixMe:error
	//cout << myList.remove(0) << endl;
	//cout << myList.remove(7) << endl;
	//cout << myList.remove(-1) << endl; //fail case
	//cout << myList.remove(10) << endl; //fail case
	myList.remove(4); //FixMe:error
	myList.remove(4);
	myList.remove(1);

	cout << "Test print 6:" << endl;
	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl;


	//
	cout << endl << "Testing9 find" << endl;
	dataType myName1;

	myName1.value = "Tom";
	cout << myList.find(myName1) << endl;

	myName1.value = "Konxhe";
	cout << myList.find(myName1) << endl;

	myName1.value = "Danny"; 
	cout << myList.find(myName1) << endl;;

	cout << "Test print 7:" << endl;
	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl;


	//
	cout << endl << "Testing End:" << endl;
	myList.printLinkedList();
	cout << "List Size: " << myList.getListSize() << endl;
	myList.getHeadTailVals();
	/////////////////////////////////////////////////////*/

	return 0;
}