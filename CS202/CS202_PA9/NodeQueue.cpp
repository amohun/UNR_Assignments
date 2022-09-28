// Title: NodeQueue.cpp
// Purpose: To define the node queue class
// Author: Andrew Bechdolt
// Date: November 16 2019

#include<iostream>
#include "NodeQueue.h"

using namespace std;





// Default-ctor
NodeQueue::NodeQueue()
{
	m_front = m_back = NULL;
	m_size = 0;
}

// Parameteried-ctor
NodeQueue::NodeQueue(size_t size, const DataType& value) 
{
	if (size != 0)
	{
		m_size = size;
		try {
			m_front = new Node;
			Node* temp = m_front;
			Node* temp2 = NULL;
			for (size_t i = 0; i < size; i++)
			{
				temp->m_data = value;
				temp2 = new Node;
				temp->m_next = temp2;
				temp = temp->m_next;
			}
			m_back = temp;
		}
		catch (bad_alloc&)
		{
			cout << "Err: Bad Allocation\n";
		}
	}

}


// Copy-ctor
NodeQueue::NodeQueue(const NodeQueue& rhs) {
	if (rhs.size() != 0)
	{
		try {
			m_front = new Node;
			Node* temp = m_front;
			Node * temp2 = NULL;
			for (size_t i = 0; i < rhs.size(); i++)
			{
                                temp2 = new Node;
                                temp->m_next = temp2;
                                temp = temp->m_next;
				m_size = i;
			}
			
			m_back = temp;
			m_back -> m_next = NULL;
			temp = m_front;
			temp2 = rhs.m_front;

			while(temp!= m_back)
			{
				temp->m_data = temp2->m_data;
				temp = temp->m_next;
				temp2 = temp2->m_next;					
			}
			
			
			
		}
		catch (bad_alloc&)
		{
			cout << "Err: Bad Allocation\n";
		}
	}
}

NodeQueue::~NodeQueue() {
	cout << "Dtor\n";
	if (m_front != m_back)
	{
		clear();
		m_front = m_back = NULL;
	}
	m_size = 0;
}

// Operator = overload
NodeQueue& NodeQueue::operator=(const NodeQueue& rhs) 
{
	if (this != &rhs);
	{
		if (!rhs.empty())
		{
			if (!this->empty())
			{
				this->clear();
			}

 			try {
                        this->m_front = new Node;
                        Node* temp = this->m_front;
                        Node * temp2 = NULL;
                        for (size_t i = 0; i < rhs.size(); i++)
                        {
                                temp2 = new Node;
                                temp->m_next = temp2;
                                temp = temp->m_next;
                                this->m_size = i;
                        }

                        this->m_back = temp;
                        this->m_back -> m_next = NULL;
                        temp = this->m_front;
                        temp2 = rhs.m_front;

                        while(temp!= m_back)
                        {
                                temp->m_data = temp2->m_data;
                                temp = temp->m_next;
                                temp2 = temp2->m_next;
                        }



                }
                catch (bad_alloc&)
                {
                        cout << "Err: Bad Allocation\n";
                }

			

		}
	}

	return *this;

}


// Front Function
DataType& NodeQueue::front() {
	return m_front->m_data;
}


// Back Function
const DataType& NodeQueue::back() const {
	return m_back->m_data;
}


// Push Function
void NodeQueue::push(const DataType& value) {
	Node* temp = NULL;
	try {
		temp = new Node;
		temp->m_data = value;
	}
	catch (bad_alloc&)
	{
		cout << "Error: Bad Alloc\n";
	}
	if (!empty())
	{
		m_back -> m_next = temp;
		m_back = temp;
	}
	else
	{
		m_front = m_back = temp;
	}
	m_size++;
}


// Pop Function
void NodeQueue::pop() {
	if (!empty())
	{
		Node* temp = m_front->m_next;
		delete m_front;
		m_front = temp;
		m_size--;
	}
}


// Size Function
size_t NodeQueue::size() const{
	size_t zize = 0;
	Node* temp = m_front;

	while(temp!=m_back)
	{
		zize++;
		temp = temp->m_next;
	}

	return zize;
}


// Empty Function
bool NodeQueue::empty() const{
	if (m_front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
		

	
}


// Full Function
bool NodeQueue::full() const {
	return false;
}



// Clear Function
void NodeQueue::clear() {
	if (!empty())
	{
		Node* temp = m_front;
		Node* temp2 = m_front->m_next;
		while(temp2 != NULL)
		{
			delete temp;
			temp = temp2;
			temp2 = temp->m_next;
		}
		m_back = m_front = NULL;
		
	}
}


// Serialize Function
void NodeQueue::serialize(std::ostream& os) const {
	if (!empty())
	{
		Node* temp = m_front;

		while (temp != m_back)
		{
			os << temp->m_data << " ";
			temp = temp->m_next;
		}
		cout << endl;
	}
	else
	{
		cout << "Empty Array!\n";
	}
}
