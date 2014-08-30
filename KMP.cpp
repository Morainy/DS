// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <string>

using namespace std;

void getNext(const char * p , int next[])
{
	int k = -1;
	int j = 0;
	next[0] = -1;
	int plen = strlen(p);
	while(j < plen -1)
	{
		if( k == -1 || p[j] == p[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMPMatcher(const char * s , const char * p , int * next)
{
	int slen = strlen(s);
	int plen = strlen(p);
	int i = 0 , j= 0;
	for(i = 0 , j = 0; i < slen && j < plen ; i++ , j++)
	{
		if( j != -1 && s[i] != p[j])
		{
			j = next[j];
		}
	}
	/*while(i < slen && j <plen)
	{
		if(j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}*/
	if(j == plen)
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}
int main(int argc, char const *argv[])
{
	const char * s = "BBC ABCDAB ABCDABCDABDE";
	const char * p = "ABCDABD";
	int plen = strlen(p);
	int * next = new int[plen];
	getNext(p , next);
	/*for(int i = 0; i <plen ; i ++)
	{
		cout<<next[i] <<" ";
	}
	cout<<endl;
	*/
	int pos = KMPMatcher(s , p , next);
	cout<<"pos= "<<pos<<endl; 

	delete []next;
	return 0;
}
