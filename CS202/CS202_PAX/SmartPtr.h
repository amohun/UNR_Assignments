// Name: SmartPtr.h
// Purpose: To be able to manipulate smart style pointers
// Author: Andrew Bechdolt
// Date: November 4 2019

#include<iostream>
#include"Datatype.h"


class SmartPtr{
public:
	SmartPtr(); //(1)
	SmartPtr(DataType*data); //(2)
	SmartPtr(const SmartPtr&other);//(3)
	
	~SmartPtr(); //(4)
	
	SmartPtr&operator=(const SmartPtr& rhs); //(5)
	
	DataType&operator*(); //(6)
	DataType*operator->(); //(7)

private:
	size_t*m_refcount;//(8)
	DataType *m_ptr; //(9)
};
