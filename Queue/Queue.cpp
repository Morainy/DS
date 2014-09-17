// Queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyQueue.h"
#include "iostream"
#include "./MyQueue.cpp"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	queue<int> Q;
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	cout<<Q.dequeue()<<endl;
	cout<<Q.dequeue()<<endl;
	cout<<Q.dequeue()<<endl;
	cout<<Q.dequeue()<<endl;
	return 0;
}

