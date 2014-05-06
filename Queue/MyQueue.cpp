#include "stdafx.h"
#include  "MyQueue.h"
#include <iostream>

#define MAX 1024
using namespace std;

template <typename T>
queue <T>::queue()
{
	this->Data = new T [MAX];
	this->head = 0 ;
	this->tear = 0;
}

template <typename T>
queue<T>::~queue()
{
	delete [] Data;
}

template <typename T>
void queue<T>::enqueue(T a)
{
	if((this->tear+1)%MAX==this->head)
	{
		cout<<"The queue is full!"<<endl;
		return ;
	}
	else
	{
		this->Data[this->tear]=a;
		this->tear=(this->tear+1)%MAX;

	}
}

template <typename T>
T queue<T> ::dequeue()
{
	T temp;
	if(this->head==this->tear)
	{
		cout<<"The queue is empty!\n"<<endl;
		return (T) -1;
	}
	else
	{
		temp=Data[this->head];
		this->head= (this->head + 1) % MAX;
		return temp;
	}
}