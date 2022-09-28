// Name: ArrayList.cpp
// Puprose: To define the functions of ArrayList.h
// Author: Andrew Bechdolt
// Date: November 6 2019


#include<iostream>
#include "ArrayList.h"
using namespace std;

//(i)
std::ostream& operator<<(std::ostream& os, const ArrayList& arrayList) {
	for (size_t i = 0; i < arrayList.m_size; i++)
	{
		os << "[" << arrayList.m_array[i] << "]" << endl;
	}
	return os;
}



//(1)
ArrayList::ArrayList() {
	cout << "Array default ctor\n";
	m_maxsize = 0;
	m_size = 0;
	m_array = NULL;
}



//(2)
ArrayList::ArrayList(size_t count, const DataType& value) {
	cout << "Array parameterized ctor\n";
	m_size = count;
	m_maxsize = count;
	
	try {
		m_array = new DataType[m_maxsize];
		for (size_t i = 0; i < m_maxsize; i++)
		{
			m_array[i] = value;
		}
	}
	catch (bad_alloc&)
	{
		cout << "Err: Bad Allocation" << endl;
	}	
}



	
//(3)
ArrayList::ArrayList(const ArrayList& other) {
	m_size = other.size();
	m_maxsize = other.size();
	cout << "Array copy ctor\n";

	if (!other.empty())
	{
		try {
			m_array = new DataType[m_size];
			for (size_t i = 0; i < m_size; i++)
			{
				m_array[i] = other.m_array[i];
			}
		}
		catch(bad_alloc&) {
			cout << "Err: Bad Allocation\n";
		}
	}

}
	
	
															
//(4)
ArrayList::~ArrayList() {
	if (m_array != NULL)
	{
		delete m_array;
		m_array = NULL;
	}
	
	m_maxsize = 0;
	m_size = 0;
}



//(5)
ArrayList& ArrayList::operator= (const ArrayList& rhs) {
	
	if (this != &rhs)
	{
		m_maxsize = rhs.m_maxsize;
		m_size = rhs.m_size;

		for (size_t i = 0; i < m_size; i++) {
			m_array[i] = rhs.m_array[i];
		}
	}
	return *this;
}




//(6)
DataType* ArrayList::front() {
	if (m_array != NULL) {
		return m_array;
	}
	return NULL;

	
}
	



	
//(7)
DataType* ArrayList::back() {

	DataType* back = m_array;
	if(m_array != NULL){
		for (size_t i = 0; i < m_size - 1; i++)
		{
			back++;
		}
	return back;
	}
	return NULL;
}

	

//(8)
DataType* ArrayList::find(const DataType& target, DataType*& previous, const DataType* start) {
	
	DataType* Found = m_array;

	if (*Found == target)
	{
		previous = NULL;
		return Found;
	}

	for (size_t i = 1; i < m_size; i++)
	{
		if (*Found == target)
		{
			previous = Found - 1;
			return Found;
		}
	}

	previous = NULL;
	return NULL;

}


	
//(9)
DataType* ArrayList::insertAfter(const DataType& target, const DataType& value) {
	for (size_t i = 0; i < m_size; i++)
	{
		if (m_array[i] == target) {
			m_size++;

			if (m_size > m_maxsize)
			{
				m_maxsize = m_size;
				resize(m_size);
			}

			for (size_t j = m_size - 1; i < j; j--) {
				m_array[j] = m_array[j - 1];
			}

			m_array[i + 1] = value;
			return &m_array[i + 1];
		}
	}
	return NULL;
}
	


//(10)
DataType* ArrayList::insertBefore(const DataType& target, const DataType& value) {
	for (size_t i = 0; i < m_size; i++) {
		if (m_array[i] == target) {
			m_size++;
			if (m_size > m_maxsize)
			{
				m_maxsize = m_size;
				resize(m_size);
			}
			for (size_t j = m_size - 1; i <= j; j--) {
				m_array[j] = m_array[j - 1];
			}
			m_array[i] = value;
			return &m_array[i];
		}
	}
	return NULL;

}



//(11)
DataType* ArrayList::erase(const DataType& target) {
	for (size_t i = 0; i < m_size; i++) {
		if (m_array[i] == target)
		{
			m_maxsize--;
			m_size--; // finds target and deletes it 

			if (m_size == 0) {
				delete[] m_array;
				return NULL;
			}

			for (size_t j = (i + 1); i < m_size; j++) {

				m_array[j - 1] = m_array[j]; // moves all values after deletion 

			}

			return m_array;
		}

	}
return NULL;
}




//(12)
DataType& ArrayList::operator[](size_t position) {
		
	return m_array[position];
}



//(13)
size_t ArrayList::size() const {
	return m_size;
}
	


//(14)
bool ArrayList::empty() const {
	if (m_size == 0 && m_array == NULL)
	{
		return true;
	}
	return false;

}
	


//(15)	
void ArrayList::clear()
{

	if (m_array != NULL) {

		delete[] m_array; // deletes each element in array 

		m_array = NULL;

	}

	m_size = 0;

	m_maxsize = 0;
}



//(16)		
void ArrayList::resize(size_t count) {

	DataType* tempVar = new DataType[m_size];

	for (size_t i = 0; i < m_size; i++) { // allocates and copies

		tempVar[i] = m_array[i];

	}



	if (m_array) {

		delete[] m_array; // deletes previous array

	}



	m_maxsize = count;

	m_array = new DataType[m_maxsize]; //allocates for new size



	if (m_maxsize <= m_size) {

		m_size = m_maxsize; // changes size if needed

	}



	for (size_t i = 0; i < m_size; i++) {

		m_array[i] = tempVar[i]; // copies back the array 

	}

}

			    
