#include "stdafx.h"
#include "stack_implements.h"

#include <iostream>

using namespace std;


template <typename T>
void stack<T>::push(T a)
{
	Node <T>* pNode=new Node <T> (a);
	if(!tPointer)
	{
		tPointer=pNode;
	}
	else
	{
		pNode->setNext(tPointer);
		tPointer=pNode;
	}
}
template <typename T>
void stack<T>::pop()
{
	if(tPointer)
	{
		Node <T> * temp=tPointer;
		tPointer=tPointer->getNext();
		delete temp;
	}
}

template <typename T>
T stack<T>::top()
{
	if(tPointer)
	{
		return tPointer->getData();
	}
	else
	{
		return 0;
	}
}