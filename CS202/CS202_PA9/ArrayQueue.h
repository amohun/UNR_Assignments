// Name: ArrayQueue.h
// Purpose: To set up the Array Queue class
// Author: Andrew Bechdolt
// Date: Nov 16 2019

#include<iostream>
#include"DataType.h"
using namespace std;

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

const size_t ARRAY_MAX = 1000;

class ArrayQueue {
	public:
		//Constructors
		ArrayQueue(); // Default-ctor
		ArrayQueue(size_t count, const DataType& value); // Parameterized-ctor

		ArrayQueue& operator=(const ArrayQueue& rhs); // Operator = overload


		//Front Functions
		DataType& front(); // Non-const
		const DataType& front() const; //const

		// Back Functions
		DataType& back(); // Non-const
		const DataType& back() const; //const

		// Functions to push and pop
		void push(const DataType& value); //Non-const
		void pop();// Const

		//Element Checking Functions
		size_t size() const; //size function
		bool empty() const; // Empty function
		bool full() const; // Full function
		
		//Element Interacting Functions
		void clear(); // Clear Function
		void serialize(std::ostream& os);//Serialize Function

	private:
		DataType m_array[ARRAY_MAX];
		size_t m_size;

		size_t m_front;
		size_t m_back;

};

#endif
