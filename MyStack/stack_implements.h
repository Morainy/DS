#pragma once
//#ifndef stack_implements_h
//#define stack_implements_h

template <typename T> 
class Node
{
	template <typename T> 
	friend  class stack;
private:
	T Data;
	Node * next;
	Node()
	{
		setData(0);
		this->next=NULL;
	}
	Node(T a)
	{
		setData(a);
		this->next=NULL;
	}
	T getData()
	{
		return this->Data;
	}
	void setData(T a)
	{
		this->Data=a;
	}
	Node * getNext()
	{
		return this->next;
	}
	void setNext(Node * p)
	{
		this->next=p;
	}
};


template <typename T> 
class stack
{
private:
	Node<T>* tPointer;
public:
	void push(T a);
	void pop();
	T top();
	stack()
	{
		this->tPointer=NULL;
	}
};
//#endif