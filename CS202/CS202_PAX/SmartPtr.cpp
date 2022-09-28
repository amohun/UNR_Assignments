// Name: SmartPtr.cpp
// Purpose: To be able to manipulate smart style pointers
// Author: Andrew Bechdolt
// Date: November 4 2019


#include<iostream>

#include"SmartPtr.h"
#include "DataType.h"

//(1)
SmartPtr::SmartPtr() {
	try {
		m_ptr = new char;
		m_refcount = new size_t;

		size_t* new_size_t = new size_t;
		*new_size_t = 1;

		*m_refcount += *new_size_t;

	}

	catch (bad_alloc&) {
		std::cout << "Error: Unable to Allocate";
		m_ptr = NULL;
		m_refcount = NULL;

	}

	std::cout << "SmartPtr Default Constructor for new allocation, RefCount = <"
		<< m_refcount << ">\n"
};


//(2)
SmartPtr::SmartPtr(DataType* data)
{
	m_ptr = data;

	try {
		size_t* new_size_t = new size_t;
		if (new_size_t == NULL)
		{
			new_size_t = 0;
		}
		else
		{
			new_size_t = 1;
		}

		m_refcount = m_refcount + new_size_t;
	}
	catch (bad_alloc&)
	{
		std::cout << "Error: Unable to allcoate";
		new_size_t = NULL;
	}	

	std::cout << "RefCount=<" << m_refcount;
};

//(3)
SmartPtr::SmartPtr(const SmartPtr& other) 
{
	m_ptr = other.m_ptr;
	
	try {
		size_t* new_size_t = new size_t;

		if (other.m_ptr = NULL)
		{
			*new_size_t = 0;
		}
		else
		{
			*new_size_t = 0;
		}

		m_refcount = m_refcount + new_size_t;
	}
	catch (bad_alloc&)
	{
		std::cout << "Error: Unable to allocate";
		size_t* new_size_t = 0;
	}

};


//(4)
SmartPtr::~SmartPtr() {
	*m_refcount--;
	if (*m_refcount == 0)
	{
		std::cout << "SmartPtr Destructor, RefCount=<" << m_refcount;
		delete m_refcount;
		delete m_ptr;
		m_refcount = NULL;
		m_ptr = NULL;
	}
};


//(5)
SmartPtr& SmartPtr::operator=(const SmartPtr& rhs) {
	m_ptr = NULL;
	m_refcount = NULL
	size_t* new_size_t = NULL;
	
	try { 
		m_ptr = new char;
		m_refcount = new size_t;
		new_size_t = new size_t;

		*m_ptr = *rhs.m_ptr;
		*new_size_t = 1 + *rhs.m_refcount;

		if (rhs.m_ptr == NULL)
		{
			*new_size_t = 0;
		}

	m_refcount += new_size_t
	}

}


//(6)
DataType& SmartPtr::operator*() {
	return *m_ptr;
}


//(7)
DataType* SmartPtr::operator->() {
	return m_ptr
}