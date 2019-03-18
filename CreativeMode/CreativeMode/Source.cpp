#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

/* 
REFERENCE DOCUMENTS: http://www.cplusplus.com/reference/vector/vector/

*/
void vectorStuff(); 

int main() {
	vectorStuff();
}

void vectorStuff() {
	string str_End = " ";
	vector<int> vector_int{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << "Lets Begin!";
	std:cout << endl;
	vector_int.push_back(11);
	vector_int.push_back(12);
	vector_int[11] = 21321313;
	std::cout << vector_int.size() << std::endl;
	std::cout << "Vector [11] is: " << vector_int[11] << endl;
	std::cin >> str_End;
}

void mergeSort(vector<int> list) {

}