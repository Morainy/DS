// Stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "stack_implements.h"
#include "./stack_implements.cpp"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<"s.top()="<<s.top()<<endl;
	s.pop();
	cout<<"s.top()="<<s.top()<<endl;
	s.pop();
	cout<<"s.top()="<<s.top()<<endl;
	s.pop();
	cout<<"s.top()="<<s.top()<<endl;
	return 0;
}


