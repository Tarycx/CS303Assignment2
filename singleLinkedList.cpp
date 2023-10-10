#include "singleLinkedList.h"

//TEST ALL FUNCTIONS!!!
//using namespace std;
Linked::Linked() {
    headPtr = nullptr;
    tailPtr = nullptr;//Need to implanment into SLL(Not required)
    num_items = 0;

    
}

Linked::Linked(Employee* d) {
    Node* tempPtr = new Node;
    tempPtr->data = d;
    tempPtr->nextPtr = nullptr;
    headPtr = tempPtr;
    tailPtr = tempPtr; // Need to implament into SLL(Not required)
    num_items = 1;

}





//Testing Functions:


//gets number of items in Linked List. Testing
int Linked::getListSize() {
    return num_items;
}


//prints number value of head and tail pointers. TESTING
void Linked::getHeadTailVals() {
    if (empty()) {
        cout << "List is empty(getHeadTailVals)" << endl;
        return;
    }
    cout << "Head:"  << headPtr->data->getName() << endl;
    cout << "Tail: " << tailPtr->data->getName() << endl;
}


//prints linked list data and repestive index postion //Testing
void Linked::printLinkedList() {
    if (empty()) {
        cout << "List is empty(printLinkedList)" << endl;
        return;
    }

    int index = 0; //counts index positions for output
    Node* position = headPtr;
    while (position->nextPtr != nullptr) {
        cout << "Index: " << index << endl;
        position->data->printInfo();
        cout << endl;
        position = position->nextPtr;
        index++;
    }

    cout << "Index: " << index << endl; //prints last index in linked list
    position->data->printInfo();//prints last element in linked list
    cout << endl;
             
}






//Required Functions:


//Func: Inserts element at front of list
void Linked::push_front(Employee* d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->nextPtr = headPtr;
    headPtr = newNode;

    //Case: list was empty
    if (tailPtr == nullptr) {
        tailPtr = newNode;
    }
    num_items++;
}


//Func: Appends to rear of list
void Linked::push_back(Employee* d) {
    Node* newNode = new Node;
    newNode->data = d;
    //Case: empty list, creates list of 1 element
    if (empty()) {
        headPtr = newNode; 
        tailPtr = newNode;
    }
    else {
        Node* element = headPtr;
        while (element->nextPtr != nullptr) {
            element = element->nextPtr;
        }

        element->nextPtr = newNode;//FixMe
        tailPtr = newNode;//FixMe
    
    }
    num_items++;
}


//removes element from front of list
void Linked::pop_front() {

    //Case: empty list
    if (empty()) {
        cout << "List is empty(pop_front)" << endl; //Testing
        return;
    }
    
    if (headPtr == tailPtr) { //Case: one element in list
        delete headPtr;
        headPtr = nullptr;
        tailPtr = nullptr;
        num_items--;
        return;
    }

    Node* tempNode = headPtr;
    headPtr = headPtr->nextPtr;
    delete tempNode;
    num_items--;
}

//removes element from rear of list
void Linked::pop_back() {

    //Case: empty lsit
    if (empty()) {
        cout << "List is empty(pop_back)" << endl; 
        return;
    }


    //Case: one element in list
    if (headPtr == tailPtr) { 
        delete headPtr;
        headPtr = nullptr;
        tailPtr = nullptr;
        num_items--;
        return;
    }

    Node* element = headPtr;
    while (element->nextPtr->nextPtr != nullptr) {
        element = element->nextPtr;
    }

    delete tailPtr;
    element->nextPtr = nullptr;
    tailPtr = element;
    num_items--;
}


//FUNC: returns a reference to first element in list. empty() func will check if container is null
Employee* Linked::front() {
    //Case: empty list
    if (empty()) {
        throw runtime_error("List is empty(front)\n");
    }
    return headPtr->data; //first element of the linked list
}



//FUNC: returns a reference to the first element in list. emptry() func will check if container is null
Employee* Linked::back() {

    //code block used when tail is not included in SLL.
    /* Node* element = headPtr;
    while (element->nextPtr != nullptr) {
        element = element->nextPtr;
    }
    return element->data;//last element of the linked list*/

    //Case: empty list
    if (empty()) {
        throw runtime_error("List is empty(back)\n");
    }
    return tailPtr->data; //Test: tail
}

//FUNC: returns true if linked list is empty, false if linked list has at least one element.
bool Linked::empty() {
    if (headPtr == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

//inserts node in Linked List at specified position, TEST:For insertion at last element
void Linked::insert(Employee* d, int insertPos) {
    int index = num_items - 1; //converts # of items in list to repsective index position

    //Case: insert position is less than 0.
    if (insertPos < 0) {
        cout << "Invaild index position entered" << endl;
        return;
    }

    //Case: insert position is first element of the list.
    if (insertPos == 0) { 
        push_front(d);
    }

    //Case: insert position is greater than list size
    else if (insertPos > index) { 
        push_back(d);
    }
    else {
        Node* newNode = new Node;
        newNode->data = d;
        Node* element = headPtr;
        for (int i = 0; i < insertPos - 1; i++) { //TEST: insertion at last elemetn
            element = element->nextPtr;
        }
        newNode->nextPtr = element->nextPtr;
        element->nextPtr = newNode;
        num_items++;  
    }
}

//FUNC: removes element, deincrements, given index, returns true or false base on success
bool Linked::remove(int removePos) {

    int index = num_items - 1;

    //Case: empty list
    if (empty()) {
        cout << "List is empty(remove)" << endl; //Testing
        return false; 
    }

    //Case: removal positions is out of index range of List
    if ((removePos < 0) || (removePos > index)) {
        return false;
    }

    //Case: removal position is first element
    else if (removePos == 0) {
        pop_front();
        return true;
    }

    //Case: removal position is last element    
    else if (removePos == index) {
        pop_back();
        return true;
    }

    else {  
        Node* element = headPtr;
        for (int i = 0; i < removePos - 1; ++i) {
            element = element->nextPtr;
        }
        Node* TempPtr = element->nextPtr;
        element->nextPtr = element->nextPtr->nextPtr;
        delete TempPtr;
       
        num_items--;
        return true; 
        
    }
}

//FUNC: Takes data finds first occure returns index position, otherwise returns list size
int Linked::find(int id) {

    //Case: empty list
    if (empty()) {
        throw runtime_error("List is empty(find)\n");
    }

    int index = 0;
    Node* position = headPtr;
    while (position->nextPtr != nullptr) {
        if (position->data->getID() == id) {
            return index;
        }
        position = position->nextPtr;
        index++;
    }
    return num_items; //list size returned if match could not be found.

}
