#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
// From https://gist.github.com/charlierm/5691020

using namespace std; 

class Node
{
public:
    Node* next;			// Pointer of type "Node" which points to the next node
    int data;			// Integer which holds the data
};

class LinkedList
{
public:
    int length;			// See how long the length of the list is
    Node* head;			// Pointer to the head of the list [ head -> node -> node -> ... -> NULL ]

    LinkedList();		// Constructor for class LinkedList
    ~LinkedList();		// Destructor for class LinkedList 
    void add(int data); // Member function which adds data to the list
    void print();		// Member function which allows us to see the data in the list
};

LinkedList::LinkedList(){		// Constructor
    this->length = 0;
    this->head = NULL;			// Points to NULL because it is an empty list
}

LinkedList::~LinkedList(){			// Destructor 
    std::cout << "LIST DELETED";	// State that the list is deleted	
}

void LinkedList::add(int data){		// Adding new data
    Node* node = new Node();		// Create a pointer to a Node, 
    node->data = data;				// Set the data in the NEW NODE to the NEW DATA
    node->next = this->head;		
    this->head = node;
    this->length++;
}

void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}

int main(int argc, char const *argv[])
{
	string test = " ";
    LinkedList* list = new LinkedList();
    /* 
	for (int i = 0; i < 100; ++i)
    {
        list->add(rand() % 100);
    }
	*/
	list->add(1);
	list->add(2);
	list->add(3);
	list->print();
    std::cout << "List Length: " << list->length << std::endl;
	delete list;
	std::cout << std::endl;
	std::cout << "Does this work?!!?"; 
	std::cin >> test;
    return 0;
}
