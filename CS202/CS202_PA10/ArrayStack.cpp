// Name: ArrayStack.cpp
// Purpose: To define the functions of the ArrayStack.h file
// Author: Andrew Bechdolt
// Date: November 21 2019

#include"ArrayStack.h"

friend std::ostream & operator<<<>(std::ostream & os, const ArrayStack<T> & arrayStack){
	serialize(os);
	return os;
}



ArrayStack()
:m_container(T()), m_top(0)
{
};



ArrayStack(size_t count, const T & value = T() ){
	if(count > 0)
	{
		m_top = count;
		for int (i = 0; i < count; i++)
		{
			m_container[i] = value;
		}
	}
};	


T & top(){
	return m_top;
}



const T & top() const{
	return m_top;
}


void push(const T & value){
	if(m_top < MAX_STACKSIZE)
	{
		m_top++;
		m_container[m_top];
	}
}


void pop(){
	if(m_top > 0)
	{
		m_container[m_top] = NULL;
		m_top--;
	}

}




size_t size() const{
	return m_top;
}



bool empty() const{
	if m_top <= 0{
		return true;
	}
	return false;
}


bool full() const { 
	if(m_top >= MAX_STACKSIZE)
	{
		return true;
	}
	return false;
}



bool clear() { 
	if(m_top > 0)
	{
		for (i = 0; i < m_top; i++)
		{
			m_container[i] = NULL;
		}
	}
	m_top = 0;
}


void serialize(std::ostream & os) const { 
	if m_top > 0;
	{
		for(int i = 0; i < m_top i++)
		{
			os << m_container[i] << " ";
		}
	}
	os << std::endl;
}


