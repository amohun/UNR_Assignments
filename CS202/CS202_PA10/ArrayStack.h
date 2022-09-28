// Name: ArrayStack.h
// Purpose: To define the Array Stack in terms of template
// Author: Andrew Bechdolt
// Date: November 25 2019

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include<iostream>
using namespace std;  

const size_t MAX_STACKSIZE = 1000;

template<class T>
class ArrayStack{
	template<class U>
	friend std::ostream& operator<< (std::ostream & os, const ArrayStack<T> & arrayStack);

	public:
		ArrayStack();
		ArrayStack(size_t count, const T & value = T() );

		T & top();
		const T & top() const;
		
		void push(const T & value);
		void pop();

		size_t size() const;
		bool empty() const;
		bool full() const;

		void clear();
		void serialize(std::ostream & os) const;

	private:
		T m_container[MAX_STACKSIZE];
		size_t m_top;
};

#endif

template<class T> 
std::ostream & operator<<(std::ostream & os, const ArrayStack<T> & arrayStack){
        arrayStack.serialize(os);
        return os;
}


template<class T>
ArrayStack<T>::ArrayStack()
:m_top(0)
{
	m_container[0] = 0;
};


template<class T>
ArrayStack<T>::ArrayStack(size_t count, const T & value){
        if(count > 0)
        {
                m_top = count;
                for (int i = 0; i < count; i++)
                {
                        m_container[i] = value;
                }
        }
};

template<class T>
T & ArrayStack<T>:: top(){
        return m_container[m_top];
}


template<class T>
const T & ArrayStack<T>::top() const{
        return m_top;
}

template<class T>
void ArrayStack<T>::push(const T & value){
        if(m_top < MAX_STACKSIZE)
        {
		size_t temp = m_top;
		temp++;
		m_container[temp] = value;
		m_top = temp;
		
        }
}

template<class T>
void ArrayStack<T>::pop(){
        if(m_top > 0)
        {
                m_container[m_top] =0;
                m_top--;
        }

}



template<class T>
size_t ArrayStack<T>::size() const{
        return m_top;
}


template<class T>
bool ArrayStack<T>::empty() const{
        if (m_top <= 0){
                return true;
        }
        return false;
}

template<class T>
bool ArrayStack<T>::full() const {
        if(m_top >= MAX_STACKSIZE)
        {
                return true;
        }
        return false;
}


template<class T>
void ArrayStack<T>::clear() {
        if(m_top > 0)
        {
                for (size_t i = 0; i < m_top; i++)
                {
                        m_container[i] = 0;
                }
        }
        m_top = 0;
}

template<class T>
void ArrayStack<T>::serialize(std::ostream & os) const {
        if (m_top > 0)
        {
                for(int i = 0; i < m_top; i++)
                {
                        os << m_container[i] << " ";
                }
        }
        os << std::endl;
}
