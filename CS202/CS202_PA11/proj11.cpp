// Name: proj11.cpp
// Purpose: To train in understanding of the std library and recursion
// Author: Andrew Bechdolt
// Date: 2 December 2019

#include<iostream>
#include<fstream>
#include<vector>
#include"VectorRecursion.h"
using namespace std;

int main()
{
	VectorRecursion<int> testVector;

	cout << "Testing vector:\n";
	testVector.print_vector();

	cout << "Testing vector copy:\n";
	testVector.print_cpyvector();

	cout << "Testing sort vector:\n";
	testVector.vector_resort(testVector.vecInt);
	testVector.print_vector();

	cout << "Testing find function to find 110 (should return 110)\n";
	int i = *testVector.vector_research(testVector.vecInt, 110, testVector.vecInt.begin(), testVector.vecInt.end());
	cout << i << endl << endl;

	cout << "All Tests Successfull\n";

	return 0;
}


