// Name: Project 9
// Purpose: To test the classes
// Author: Andrew Bechdolt
// Date: November 19 2019

#include<iostream>
#include"ArrayQueue.h"
#include"NodeQueue.h"
#include"DataType.h"
using namespace std;


int main() {
	cout <<"		#################################################\n"
		 <<"		#Testing Arrray Based Queue and Node Based Queue#\n"
		 <<"		#################################################\n";



	cout << endl << endl;

	cout << "Testing the Array Queue:\n";

	cout << "------------------------\n\n";

	//Testing Default Constructor
	cout << "Default Constructor\n";
	ArrayQueue defaultArray;
	defaultArray.serialize(cout);
	cout << endl;

	//Testing Parameterized Constructor
	cout << "Parameterized Constructor with 3 entries of 12,6.472\n";
	DataType parArrayTest(12,6.472);
	ArrayQueue parArray(3, parArrayTest);
	parArray.serialize(cout);
	cout << endl;

	//Testing Copy Constructor
	cout << "Copy Constructor with previous Array Queue\n";
	ArrayQueue copyArray(parArray);
	copyArray.serialize(cout);
	cout << endl;


	//Testing Operator =
	cout << "Operator = with previous value and new array\n";
	DataType tempData(10, 13.12);
	ArrayQueue asgmtArray(3, tempData);
	cout << "Array Before: ";
	asgmtArray.serialize(cout);
	
	cout << endl;

	asgmtArray = copyArray;
	cout << "Array After: ";
	asgmtArray.serialize(cout);

	cout << endl;

	// Testing front
	cout << "Front Function, it should return 12, 6.472\n";
	cout << copyArray.front();
	cout << endl;
	
	// Testing Back
	cout << "Back Function, it should retrun 12, 6.472\n";
	cout << copyArray.front();
	cout << endl;

	// Testing Push
	ArrayQueue pushArray(copyArray);
	cout << "This is the array before: ";
	pushArray.serialize(cout);
	cout << endl;

	cout << "This is the array after adding another data element: ";
	pushArray.push(tempData);
	pushArray.serialize(cout);
	cout << endl;

	// Testing Pop
	cout << "Pop function: (same array)\n";
	pushArray.pop();
	pushArray.serialize(cout);
	cout << endl;

	// Testing Size
	cout << "Size Function (same array)\n";
	cout << pushArray.size();
	cout << endl;

	// Testing Empty
	cout << "Empty Function (same array)\n Original Array\n";
	pushArray.serialize(cout);
	cout << endl;
	cout << "Clearing the Array\n";
	pushArray.clear();
	pushArray.serialize(cout);
	cout << endl;
	if (pushArray.empty())
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}
	cout << endl;

	//Testing Full
	cout << "Full Function\n";
	if(copyArray.full())
	{
		cout << "True it is the max size";
	}
	else
	{
		cout << "False it is only " << copyArray.size() << " out of 1000";
	}	
	

	cout << endl << endl;
	cout << "Testing the Node Queue:\n";
	cout << endl << endl;



	//Testing Default Constructor
	cout << "Default Constructor\n";
	NodeQueue defaultNode;
	defaultNode.serialize(cout);
	cout << endl << endl;

	//Testing Parameterized Constructor
	cout << "Parameterized Constructor with 5 entries of 1.05\n";
	DataType parNodeTest(3, 1.05);
	NodeQueue parNode(5, parNodeTest);
	parNode.serialize(cout);
	cout << endl << endl;


	//Testing Copy Constructor
	cout << "Copy Constructor with previous Node Queue\n";
	NodeQueue copyNode(parNode);
	copyNode.serialize(cout);
	cout << endl << endl;



	//Testing Operator =
	cout << "Operator = with previous value and new node\n";
	DataType tempData2(100, 10.055);
	NodeQueue asgmtNode(3, tempData2);
	cout << "Node Queue Before: ";
	asgmtNode.serialize(cout);
	cout << endl << endl;

	asgmtNode = copyNode;
	cout << "Node After: ";
	asgmtNode.serialize(cout);
	cout << endl << endl;


	// Testing front
	cout << "Front Function, it should return 3, 1.05\n";
	cout << copyNode.front();
	cout << endl << endl;


	// Testing Back
	cout << "Back Function, it should retrun 3, 1.05\n";
	cout << copyNode.front();
	cout << endl << endl;


	// Testing Push
	NodeQueue pushNode(copyNode);
	cout << "This is the queue before: ";
	pushNode.serialize(cout);
	cout << "This is the queue after adding another data element: ";
	pushNode.push(tempData2);
	pushNode.serialize(cout);
	cout << endl << endl;


	// Testing Pop
	cout << "Pop function: (same queue)\n";
	pushNode.pop();
	pushNode.serialize(cout);
	cout << endl << endl;


	// Testing Size
	cout << "Size Function (same queue)\n";
	cout << pushNode.size();
	cout << endl << endl;


	// Testing Empty
	cout << "Empty Function (same queue)\n Original Queue\n";
	pushNode.serialize(cout);
	cout << "Clearing the node queue\n";
	pushNode.clear();
	pushNode.serialize(cout);


	if (pushNode.empty())
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}
	cout << endl << endl;

	//Testing Full
	cout << "Full Function (This function should return false)\n";
	if (copyNode.full())
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}
	cout << endl << endl;
	return 0;
}




