#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

/* 
REFERENCE DOCUMENTS: 
Vectors : http://www.cplusplus.com/reference/vector/vector/

Sorting Algorithms: 
Bubble Sort - https://www.geeksforgeeks.org/bubble-sort/
*/

void vectorStuff(); 
void bubbleSort(vector<int> & list);
void printVector(vector<int> & list);
void userInput();

int main() {
	vector<int> list = { 5, 9, 2, 4, 1, 5, 7, 0, 2, 0, 3, 9, 6, 6, 2 };
	bubbleSort(list);
	printVector(list);
	userInput();
}



void bubbleSort(vector<int> & list) {
	int size = list.size(); 
	for (int i = 0; i < size - 1; i++) {
	// for int (j = i; j < size - 1; j++) Problem here is that it thinks the beginning is sorted
	// It's not. Don't forget!
		for (int j = 0; j < size - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
				cout << "Swapping " << list[j] << " and " << list[j + 1] << endl;
			}
		}
	}
}

void printVector(vector<int> & list) {
	for (int i = 0; i < list.size(); i++) {
		cout << "[" << i << "]: " << list[i] << endl; 
	}
}

void userInput() {
	string wait = "";
	cin >> wait; 
}

void vectorStuff() {
	string str_End = " ";
	vector<int> vector_int{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "Lets Begin!";
	cout << endl;
	vector_int.push_back(11);
	vector_int.push_back(12);
	vector_int[11] = 21321313;
	cout << vector_int.size() << endl;
	cout << "Vector [11] is: " << vector_int[11] << endl;
	cin >> str_End;
}