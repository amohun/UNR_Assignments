	// Name: NodeList.cpp
	// Purpose: To define the functions for NodeList.h
	// Author: Andrew Bechdolt
	// Date: November 6 2019


	#include<iostream>
	#include"NodeList.h"

	using namespace std;

	//(i)
	ostream& operator<<(ostream& os, const NodeList& nodeList)
	{
 		if(!nodeList.m_head)
 		{
    			os << "No list to display" << endl;
    			return os;
  		}

   		Node * current = nodeList.m_head;
   		os << endl;

    		size_t i = 1;
    		while(current)
    		{
      			os << "Value of Node " << i << ": " 
			   << current->getData()<< endl;
      			++i;
     			current = current->getNext();
    			}
   	 return os;
  }


	//(1)
	NodeList::NodeList() {
		cout << "Node default ctor" << endl;
		m_head = NULL;
		cout << "Default Constructor works" << endl;
	}
		
	//(2)
	NodeList::NodeList(size_t count, const DataType& value) {
		cout << "Node parameterized ctor" << endl;

		Node* curr = m_head;
		for (size_t i = 0; i < count; i++) {
			try{
				curr = NULL;
				curr = new Node;
				curr ->getData() = value;
				curr = curr->getNext(); 
			}
			catch(bad_alloc&)
			{
				cout << "Err: faulty assignment\n";
			}
		}
	}


	//(3)
	NodeList::NodeList(const NodeList& other) {
		cout << "Node copy ctor" << endl;
		Node* curr = m_head;
		cout << "1";
		for (Node* var = other.m_head; var != NULL; var = var->m_next) 
		{
			try { 
			curr = new Node(var->getData());
			curr = curr->getNext();
			}
			catch(bad_alloc&)
			{
				cout << "Err: Bad Alloc\n";
			}
		}

	}


	//(4)
	NodeList::~NodeList() {
		cout << "Node dtor\n";
		for (Node* curr = m_head; curr != NULL; curr = curr->m_next) {
			m_head = m_head->m_next; 
			delete curr;
			curr = NULL; 
			curr = m_head;
		}
		cout << "destruct" << endl;
	}

	//(5)
	NodeList& NodeList::operator= (const NodeList& rhs) {
		cout << "Node assignment operator" << endl;
		if (m_head != NULL) { 
			for (Node* curr = m_head; curr != NULL; curr = curr->m_next) {
				m_head = m_head->m_next;
				delete curr;
				curr = NULL;
				curr = m_head;
			}
		}

		Node* curr2 = m_head;
		for (Node* curr = rhs.m_head; curr != NULL; curr = curr->m_next) {
			curr2 = new Node(curr->m_data);
			curr2 = curr2->m_next;
		}

		return *this;
	}


	//(6)
	Node* NodeList::front() {
		cout << "Node front function\n";
		return m_head;
	}


	//(7)
	Node* NodeList::back() {
		cout << "Node back function\n";
		if (m_head != NULL)
		{
			Node* curr = m_head;
			for (; curr->m_next != NULL; curr = curr->m_next);
			return curr;
		}
		return NULL;
	}



	//(8)
	Node* NodeList::find(const DataType& target, Node * & previous, const Node* start) {
		cout << "Node find function\n";
		if (m_head == NULL) {
			return NULL;
		}
		Node* curr = m_head;
		Node* temp = m_head;

		for (; curr->m_next != NULL; curr = curr->m_next) {
			if (target == curr->m_next->m_data) {
				previous = curr;
				return curr->m_next;
			}
			temp = curr;

		}



		if (target == curr->m_next->m_data) {
			previous = temp;
			return curr;
		}


		previous = NULL;
		return NULL;
	}

	//(9)			
	Node* NodeList::insertAfter(const DataType& target, const DataType& value) {
		cout << "Node insert after function\n";
		for (Node* curr = m_head; curr != NULL; curr = curr->m_next) {
			if (target == curr->m_data) { 
				curr->m_next = new Node(value, curr->m_next);
				return curr->m_next;
			}
		}
		return NULL;
	}



	//(10)		
	Node* NodeList::insertBefore(const DataType& target, const DataType& value) {
		cout << "Node insert before function\n";
		for (Node* curr = m_head; curr != NULL; curr = curr->m_next) {
			if (target == curr->m_next->m_data) { 
				curr->m_next = new Node(value, curr->m_next);
				return curr->m_next;
			}
		}

		return NULL;
	}
		

	//(11)
	Node* NodeList::erase(const DataType& target) {
		cout << "Node erase function\n";
		Node* curr = m_head;
		if (target == m_head->m_data) {
			Node* nextptr = m_head->m_next;
			delete m_head;
			m_head = nextptr;
			return m_head;
		}

		for (; curr->m_next != NULL; curr = curr->m_next) {
			if (target == curr->m_next->m_data) {
				Node* next = curr->m_next->m_next;
				delete curr->m_next; 
				curr->m_next = next;
				return curr->m_next;
			}

		}



		if (target == curr->m_data) {
			delete curr;
			curr = NULL;
		}
		return NULL;
	}



	//(12a)
	DataType& NodeList::operator[] (size_t position) {
		cout << "Node operator [] function\n";
		Node* place = m_head;
		for (size_t i = 0; i < position; i++) {
			place++;
		}
		return place->m_data;
	}


	//(12b)
	const DataType& NodeList::operator[] (size_t position) const {
		cout << "Node const operator [] function\n";			
		Node* curr = m_head;
		for (size_t i = 0; i < position; i++) {
			curr++;
		}

		return curr->m_data;
	}

	//(13)
	size_t NodeList::size() const {
		cout << "Node size function\n";
		size_t length = 0;
		cout << "1";
		Node *curr = m_head;
		cout << "2";
		while (curr != NULL) {
			length++;
 			curr = curr->m_next;
		}
		cout << "3";
		return length;
	}

	//(14)
	bool NodeList::empty() const {
		cout << "Node empty check function\n";
		if (m_head == NULL) {
			return true;
		}
		return false;
	}

	//(15)
	void NodeList::clear() {
		cout << "Node clear function\n";
		for (Node* curr = m_head; curr != NULL; curr = curr->m_next) {
			m_head = m_head->m_next;
			delete curr; // same as dstructor function
			curr = NULL;
			curr = m_head;
		}
	}




