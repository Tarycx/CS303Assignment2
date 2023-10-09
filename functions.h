#pragma once

#include <iostream>
#include <string>
#include "singleLinkedList.h"
#include "Employee.h"
#include "Professional.h"
#include "NonPro.h"


Professional* createPro(int listSize);

NonPro* createNonPro(int listSize);

void linkedListOptionsP(Professional* newEmp, Linked& myList);

void linkedListOptionsNP(NonPro* newEmp, Linked& myList);