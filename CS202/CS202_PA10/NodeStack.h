// Name: NodeStack.h
// Purpose: To define the node stack in terms of templates
// Author: Andrew Bechdolt
// Date: November 25 2019

#include<iostream>


template <typename T>
class NodeStack;

template<class T>
class Node{
	friend class NodeStack<T>;
	public:
		Node():m_next(NULL){}
		Node(const T & data, Node<T> * next = NULL):m_next(next),m_data(data){}
		Node(const Node<T> & other):m_next(other.m_next),m_data(other.m_data){}
		T & data(){return m_data;}
		const T & data() const {return m_data;}

	public:
		Node<T> * m_next;
		T m_data;
};



template<class T>
class NodeStack{

template<class U>
friend std::ostream & operator<< (std::ostream & os, const NodeStack<T> & nodeStack);

public:
	NodeStack();
	NodeStack(size_t count, const T & value = T() );
	NodeStack(const NodeStack<T> &other);
	~NodeStack();

	NodeStack<T> & operator=(const NodeStack<T> & rhs);

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
	Node<T>* m_top;
};

template<class T>
std::ostream & operator<< (std::ostream & os, const NodeStack<T> & nodeStack)
{
nodeStack.serialize(os);
return os;
}



template<class T>
NodeStack<T>::NodeStack()
:m_top(NULL)
{};

template<class T>
NodeStack<T>::NodeStack(size_t count, const T & value)
{
if(count > 0)
{
	try{
		this->m_top = new Node<T>;
		for(int i = 0; i < count; i++)
		{
			m_top->m_data = value;
			m_top->m_next = new Node<T>;
			m_top = m_top->m_next;
		}
	}
	catch(std::bad_alloc&)
	{
		std::cout << "Error: Bad Allocation";
	}	
}

};


template<class T>
NodeStack<T>::NodeStack(const NodeStack<T> &other)
{
 Node<T>* temp = m_top;
                try{
                        this->m_top = new Node<T>;
                        for(int i = 0; i < other.size(); i++)
                        {
                                temp->m_data = other.m_top->m_data;
                                temp->m_next = new Node<T>;
                                temp = temp->m_next;
                        }                                                                                               
		    }
                catch(std::bad_alloc&)
                {
                        std::cout << "Error: Bad Allocation";
                }
        
};


template<class T>
NodeStack<T>::~NodeStack(){
Node<T> * temp = NULL;
if(this->size() > 0)
{
	while(m_top->m_next != NULL)
	{
		if(m_top != NULL)
		{
			temp = m_top->m_next;
			delete(m_top);
			m_top = temp;
		}
	}
}	
	
}


template<class T>
NodeStack<T> & NodeStack<T>::operator=(const NodeStack<T> & rhs)
{
if(rhs.size() > 0)  
        {
		Node<T>* temp = m_top;
        	try{
			this->m_top = new Node<T>;
                        for(int i = 0; i < rhs.size(); i++)
                        {
                                temp->m_data = rhs.m_top->m_data;
                                temp->m_next = new Node<T>;
                                temp = temp->m_next;
                        }                                                                                               }
                catch(std::bad_alloc&)
                {
                	std::cout << "Error: Bad Allocation";
                }
        }	
	return *this;
};


template<class T>
T & NodeStack<T>::top()
{
	return m_top->m_data;
}

template<class T>
const T & NodeStack<T>::top() const
{
	return m_top->m_data;
}

template<class T>
void NodeStack<T>::push(const T & value)
{
	Node<T>* temp = m_top;
	try{
		m_top = new Node<T>;
		m_top->m_next = temp;
		m_top->m_data = value;
	}
	catch(std::bad_alloc&)
	{
		std::cout << "Error: Bad Allocation\n";
	}	
}

template<class T>
void NodeStack<T>::pop()
{
if(!empty())
	{
		Node<T> * temp = m_top->m_next;
		delete m_top;
		m_top = temp;
	}
}


template<class T>
size_t NodeStack<T>::size() const
{
	size_t size;

	if(empty())
	{
		return 0;
	}
	
	Node<T>* temp = m_top;
	while (m_top != NULL)
	{
		size++;
		temp = temp->m_next;
	}	
}

template<class T>
bool NodeStack<T>::empty() const
{
	if(m_top == NULL)
	{
		return true;
	}
	return false;
}



template<class T>
bool NodeStack<T>::full() const
{
	return false;
}



template<class T>
void NodeStack<T>::clear()
{
	Node<T> * temp = NULL;
	if(!empty())
	{
		temp = m_top;
		Node<T>* temp2 = m_top;
		while(temp->m_next != NULL)
		{
			temp2 = temp->m_next;
			delete temp;
			temp = temp2;
		}
	}
	temp = NULL;
}

template<class T>
void NodeStack<T>::serialize(std::ostream & os) const
{
	Node<T>* temp = m_top;
	if(!empty())
	{
		while(temp->m_next != 0);
		{
			os << temp << " ";
			temp = temp->m_next;
		}
	}
}



