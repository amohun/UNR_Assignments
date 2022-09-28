//Name: Proj8.cpp
//Purpose: To test all of the code form project 8
//Author: Andrew Bechdolt
//Date: November 13 1999

#include <iostream>
#include "ArrayList.h"
#include "NodeList.h"
using namespace std;

int main() {
	    
   cout << "Testing Default ctors" << endl;
	    
   ArrayList array;
   cout << array << endl;
    
    NodeList node;
    cout << node << endl;
    
    cout << "Testing Parameterized ctor's"<< endl;
   
    DataType testValue1(140, 100.0);
    DataType testValue2(220, 210.0);

    ArrayList paraArrayTest(11, testValue1);
    cout << paraArrayTest << endl;
    
    NodeList paraNodeTest(11, testValue2);
    cout << paraNodeTest << endl;
    
  
	cout << "Testing copy constructors:\n";
	
	ArrayList copyArrayTest(paraArrayTest);
    cout << copyArrayTest << endl;
    
    NodeList copyNodeTest(paraNodeTest);
    cout << copyNodeTest << endl;
    
    cout << "Testing the destructors" << endl;
     
    DataType null(0, 0.0);
    ArrayList* arrayPtr = new ArrayList(10, null);
    NodeList* nodePtr = new NodeList(10, null);
    
    delete arrayPtr;
    arrayPtr = NULL;

    delete nodePtr;
    nodePtr = NULL;
    
	
	cout << "Testing the assignment operator" << endl;            
	DataType assigntestValue1(740, 100.0), assigntestValue2(98, 22.0), assigntestValue3(129, 25.6);
    ArrayList array1(8, assigntestValue1);
    
	array1 = ArrayList(8, assigntestValue2);
    cout << array1 << endl;
    
	ArrayList array2(8, assigntestValue2);
    cout << array2 << endl;
	
	NodeList node1(6, assigntestValue3);
    node1 = NodeList(6, assigntestValue1);
    cout << node1 << endl;
    
	NodeList node2(6, assigntestValue1);
    cout << node2 << endl;
    
    
	cout << "testing the front function" ;      
    
    ArrayList AfirstElement(array1), AlastElement(array1);
    DataType* AshowFront = AfirstElement.front();
    cout << *AshowFront << endl;
    
	DataType* AshowBack = AlastElement.back();
    cout << *AshowBack << endl;
	
	NodeList nlFront(node1), nlBack(node1);
    Node* showFnode = nlFront.front();
	
	if (showFnode != NULL)
    {
		cout << "FRONT" << endl;
    }
	    else
    {
		cout << "NOT FRONT" << endl;
    }



	cout << "Testing the back function\n";
	    
	Node* showBnode = nlBack.back();
	if (showBnode != NULL)
    {
		cout << "BACK" << endl;
    }
	else
    {
		cout << "NOT BACK" << endl;
    }


	cout << "Testing the find function\n";

    DataType* prev_data = NULL;
    DataType* find_data = array1.find(assigntestValue1, prev_data);
    cout << *find_data << endl;
    
	Node* prev_node = NULL;
    Node* find_node = node1.find(assigntestValue1, prev_node);
    
	if (find_node != NULL)
    {
		cout << "FOUND\n";
    }
    else
    {
		cout << "NOT FOUND\n";
    }
  
 


	cout << "Testing Erase Function\n";
    
	DataType* eraser = array1.erase(assigntestValue1);
    cout << *eraser << endl;
    cout << "Test1" << endl;
    
	Node* erasernode = node1.erase(assigntestValue1);
    cout << "Test2" << endl;
	    
	if (erasernode != NULL)
    {
		cout << "TRUE" << endl;
    }

	else
    {
		cout << "FALSE" << endl;
    }

return 0;
}
 
