// Title: NodeQueue.h
// Purpose: To instantiate the node queue class
// Author: Andrew Bechdolt
// Date: November 16 2019

#ifndef NODEQUEUE_H
#define NODEQUEUE_H
#include"DataType.h"
using namespace std;

class Node{

  friend class NodeQueue;  //allows direct accessing of link and data from class NodeList

  public:
    Node() 
    :m_next( NULL )
    {}
	
    Node(const DataType & data, Node * next = NULL) 
    :m_next( next ), m_data( data )
    {}
	
    Node(const Node & other) 
    :m_next( other.m_next ), m_data( other.m_data )
    {}
	
    DataType & data(){  //gets non-const reference, can be used to modify value of underlying data
      //return const_cast<DataType &>(static_cast<const Node &>(*this).getData());  //an alternative implementation, just for studying reference
	  return m_data;
    }
    const DataType & data() const{  //gets const reference, can be used to access value of underlying data
      return m_data;
    }

  private:
    Node * m_next; 						
    DataType m_data;
};



class NodeQueue {
	public:
		// Constructors
		NodeQueue(); // Default-ctor
		NodeQueue(size_t size, const DataType& value); // Parameterized-ctor
		NodeQueue(const NodeQueue& other); // Copy-ctor
		
		// Destructors
		~NodeQueue(); // Destructor

		// Operator Overloads
		NodeQueue& operator=(const NodeQueue& rhs); // Operator = overload

		//Front functions
		DataType& front(); // Non-const
		const DataType& front() const; // const

		//Back functions
		DataType& back(); // Non-const
		const DataType& back() const; // const

		//Push and pop functions
		void push(const DataType& value); // Push function
		void pop(); //Pop function

		// Functions to measure array
		size_t size() const;
		bool empty() const;
		bool full() const;

		// Function to interact with arrays
		void clear();
		void serialize(std::ostream& os) const;

	private:
		Node* m_front;
		Node* m_back;
		size_t m_size;


};

#endif
