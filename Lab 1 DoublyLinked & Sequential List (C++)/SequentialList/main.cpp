#include <iostream>
#include <string>
using namespace std;

#include "Lab1Tests.hpp"

string get_status_str(bool status)
{
	return status ? "Pass" : "Fail";
}

int main()
{
	DoublyLinkedList linked;

	// check insert front
	cout << "Capacity is: " << linked.capacity() << endl;
	cout << linked.insert_front(1) << endl;
	cout << linked.insert_front(2) << endl;
	cout << linked.insert_front(3) << endl;
	cout << linked.insert_front(4) << endl;
	cout << linked.insert_front(5) << endl;
	cout << linked.insert_front(6) << endl;
	cout << linked.size() << endl;
	linked.print();
	system("pause");
	// Another Test
	/*
	cout << "At 4: " << linked.select(4) << endl;
	cout << "At -1: " << linked.select(-1) << endl;
	cout << "At 5: " << linked.select(5) << endl;
	cout << "search for 123456: " << linked.search(123456) << endl;
	linked.remove_front();
	cout << linked.insert(9999, 2);
	linked.print();
	linked.remove_back();
	linked.print();
	linked.insert(9191, 4);
	linked.print();
	//	cout << linked_test.size() << endl;
	//	cout << linked_test.empty() << endl;
	*/

	/*
	SequentialListTest seq_test;
	DoublyLinkedListTest linked_test;

	bool seq_test1_passed = seq_test.test1();
	bool seq_test2_passed = seq_test.test2();
	bool seq_test3_passed = seq_test.test3();

	bool linked_test1_passed = linked_test.test1();
	bool linked_test2_passed = linked_test.test2();
	bool linked_test3_passed = linked_test.test3();

	cout << "---Sequential List Tests---" << endl;
	cout << "Test1: " << get_status_str(seq_test1_passed) << endl;
	cout << "Test2: " << get_status_str(seq_test2_passed) << endl;
	cout << "Test3: " << get_status_str(seq_test3_passed) << endl;
	cout << endl;
	cout << "---Linked List Tests---" << endl;
	cout << "Test1: " << get_status_str(linked_test1_passed) << endl;
	cout << "Test2: " << get_status_str(linked_test2_passed) << endl;
	cout << "Test3: " << get_status_str(linked_test3_passed) << endl;
	system("pause");
	*/
	return EXIT_SUCCESS;
}
