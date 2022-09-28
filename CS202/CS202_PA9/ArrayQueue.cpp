// Name: ArrayQueue.cpp
// Purpose: To define the Array Queue class
// Author: Andrew Bechdolt
// Date: Nov 16 2019

#include<iostream>
#include"ArrayQueue.h"

using namespace std;

// Default-ctor
ArrayQueue::ArrayQueue() 
	:m_size(0), m_front(-1), m_back(ARRAY_MAX-1)
{};



// Parameterized-ctor
ArrayQueue::ArrayQueue(size_t count, const DataType& value)
{
	if (count > 0 && count <= ARRAY_MAX)
	{
			m_size = count;
			m_front = 0;
			for (size_t i = m_front; i < m_front + m_size; i++)
			{
				m_array[i] = value;
			}
			m_back = m_size-1;
	}
	else {
		cout << "Err: Improper size\n";
	}
};

//No Need to implement copy constructor or the destructor, due to the fact that we are dealing with static variables


//Operator = overload
ArrayQueue& ArrayQueue::operator=(const ArrayQueue& rhs) {
	if (this != &rhs)
	{
		if (rhs.size() != 0)
		{
			if (!empty())
			{
				clear();
			}

			size_t i = rhs.m_front;
			while (i <= rhs.m_back)
			{
				m_array[i] = rhs.m_array[i];
				i++;
			}

			{
				m_array[i] = rhs.m_array[i];
			}
			this->m_size = rhs.size();
			this->m_front = rhs.m_front;
			this->m_back = rhs.m_back;

		}
	}

	return *this;
}


// Front Function (Non-const)
DataType& ArrayQueue::front() {
	if (!empty())
	{
		return m_array[m_front];
	}
	cout << "Empty Array\n";
	return m_array[0];
}


// Front Function (const)
const DataType& ArrayQueue::front() const {
	if (!empty())
	{
		return m_array[m_front];
	}
	cout << "Empty Array\n";
	return m_array[0];
}

// Front Function (Non-const)
DataType& ArrayQueue::back() {
	if (!empty())
	{
		return m_array[m_back];
	}
	cout << "Empty Array\n";
	return m_array[0];
}

// Back Function (const)
const DataType& ArrayQueue::back() const {
	if (!empty())
	{
		return m_array[m_back];
	}
	cout << "Empty Array\n";
	return m_array[0];
}


//Push Function
void ArrayQueue::push(const DataType& value) {
	if (!full())
	{
		m_back = (m_back+1) % ARRAY_MAX;
		m_array[m_back] = value;
		++m_size;
	}
}



//Pop Function
void ArrayQueue::pop() {
	if (!empty())
	{
		
		m_front = (m_front + 1) % ARRAY_MAX;
		--m_size;
	}


}



//Size Function
size_t ArrayQueue::size() const {
	return m_size;
}



// Empty function
bool ArrayQueue::empty() const {
	if (m_front == m_back)
	{
		return true;
	}
	return false;
}



// Full function
bool ArrayQueue::full() const {
	if (m_size == ARRAY_MAX)
	{
		return true;
	}
	return false;
}


// Clear Function
void ArrayQueue::clear() {
	if (!empty())
	{
		DataType emptyData;
		for (size_t i = m_front; i < m_back; i++)
		{
			m_array[i] = emptyData;
		}
		m_size = 0;
		m_front = -1;
		m_back = m_front;
	}

}

// Serialize Function
void ArrayQueue::serialize(std::ostream& os) {
	if (!empty())
	{
		size_t i = m_front;
		while (i <= m_back)
		{
			os << m_array[i] << " ";
			i++;
		}

		os << endl;
	}
}
