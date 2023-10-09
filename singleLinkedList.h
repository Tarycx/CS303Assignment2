#pragma once
#include <iostream>
//include <stdexcept> //for runtime error
#include "Employee.h"
using namespace std;


/*struct dataType { //FIXME: Add variable data
	string value; //Test variable
};*/


//Node data is a struct, data.value to access (use TemplateClass)
struct Node {
	
	Employee* data; //data is a pointer to a class type, class type is a virtual function with 2 children: Pro , NonPro
	Node* nextPtr = nullptr; //value needed to be initiated, was causing errors
};


class Linked {
//Data Members
private:
	Node* headPtr; //front of the LL
	Node* tailPtr; // not required for a Single-LL
	int num_items; //counts number of items in LL
	
//Member Functions
public://FIXME: Add member functions

	Linked(); //Constructor
	Linked(Employee* d);
	
	//Testing functions:
	int getListSize();
	void getHeadTailVals();
	void printLinkedList();


	//Required functions:
	void push_front(Employee* data); //Tested
	void push_back(Employee* data); //Tested
	void pop_front(); //Tested
	void pop_back(); //Tested
	Employee* front(); //Tested
	Employee* back(); //Tested
	bool empty(); //Tested
	void insert(Employee* d, int insertPos); //Tested
	bool remove(int removePos); //Tested
	int find(int id); 


};