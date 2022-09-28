// Name: proj10.cpp
// Purpose: To test the classes made in this project
// Author: Andrew Bechdolt
// Date: November 26 2019

#include<iostream>
#include"ArrayStack.h"
#include"NodeStack.h"

using namespace std;

int main()
{
	cout <<"		#########################################################\n"
	     <<"		#Testing Arrray Templated Stack and Node Templated Stack#\n"
	     <<"		#########################################################\n";



	cout << endl << endl;

	cout << "Testing the Array Stack:\n";

	cout << "------------------------\n\n";

	//Testing Default Constructor
	cout << "Default Constructor\n";
	ArrayStack<int> defaultArray;
	defaultArray.serialize(cout);
	cout << endl;

	//Testing Parameterized Constructor
	cout << "Parameterized Constructor with 3 entries of 12";
	ArrayStack<int> parArray(3, 12);
	parArray.serialize(cout);
	cout << endl;

        //Testing Parameterized Constructor
        cout << "Parameterized Constructor with 3 entries of a";
        ArrayStack<char> parArray2(3, 'a');
        parArray2.serialize(cout);
        cout << endl;  

	//Testing Copy Constructor
	cout << "Copy Constructor with previous Array Stack\n";
	ArrayStack<char> copyArray(parArray2);
	copyArray.serialize(cout);
	cout << endl;


	//Testing Operator =
	cout << "Operator = with integer value and new array\n";
	ArrayStack<char> asgmtArray(3, 'b');
	cout << "Array Before: ";
	asgmtArray.serialize(cout);
	
	cout << endl;

	asgmtArray = copyArray;
	cout << "Array After: ";
	asgmtArray.serialize(cout);

	cout << endl;

	// Testing Top
	cout << "Top Function, it should return 12\n";
	cout << copyArray.top();
	cout << endl;
	

	// Testing Push
	ArrayStack<char> pushArray(copyArray);
	cout << "This is the array before: ";
	pushArray.serialize(cout);
	cout << endl;

	cout << "This is the array after adding another data element: ";
	pushArray.push('c');
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
	NodeStack<int> defaultNode;
	defaultNode.serialize(cout);
	cout << endl << endl;

	//Testing Parameterized Constructor
	cout << "Parameterized Constructor with 5 entries of 1.05\n";
	NodeStack<float> parNode(5, 1.05);
	parNode.serialize(cout);
	cout << endl << endl;


	//Testing Copy Constructor
	cout << "Copy Constructor with previous Node Queue\n";
	NodeStack<float> copyNode(parNode);
	copyNode.serialize(cout);
	cout << endl << endl;



	//Testing Operator =
	cout << "Operator = with previous value and new node\n";
	NodeStack<float> asgmtNode(3, 1.03);
	cout << "Node Queue Before: ";
	asgmtNode.serialize(cout);
	cout << endl << endl;

	asgmtNode = copyNode;
	cout << "Node After: ";
	asgmtNode.serialize(cout);
	cout << endl << endl;


	// Testing front
	cout << "Top Function, it should return 3, 1.05\n";
	cout << copyNode.top();
	cout << endl << endl;


	// Testing Push
	NodeStack<float> pushNode(copyNode);
	cout << "This is the stack before: ";
	pushNode.serialize(cout);
	cout << "This is the stack after adding another data element: ";
	pushNode.push(1.602);
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

