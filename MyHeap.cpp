// MyHeap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;


#define PARENT(i) i/2
#define LEFT(i)  2*i+1
#define RIGHT(i) 2*i+2

void swap(int & a , int & b)
{
	int tmp;
	tmp = b;
	b = a;
	a = tmp;
}
void MIN_HEAPIFY(int A[] ,int k , int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int smallest = i;
	if(l < k && A[l] < A[smallest] )
	{
		smallest = l ;
	}
	if(r < k && A[r] < A[smallest] )
	{
		smallest = r;
	}
	if(smallest != i)
	{
		swap(A[i] , A[smallest]);
		MIN_HEAPIFY(A , k , smallest);
	}
}
void BUILD_MIN_HEAP(int A[] , int k)
{
	for (int i = k / 2 ; i >= 0 ; i-- )
	{
		MIN_HEAPIFY(A , k , i);
	}
}

void top_k(ifstream & fin , int A[] , int k)
{
	int val;
	int min_index = 0;
	for(int i = 0 ; i < k ; i++)
	{
		fin>>A[i];
	}
	BUILD_MIN_HEAP(A , k);

	int count = 0 ;

	while(fin >> val)  
	{

		count++;
		min_index = 0;

		if(val > A[0])
		{
			A[0] = val;
			BUILD_MIN_HEAP(A , k);
		}
	}

	cout<<"count = "<<count<<endl;
}

void heap_sort(int A[] , int k)
{
	int heap_size = k;
	BUILD_MIN_HEAP(A , k);
	for (int i = k-1 ; i >= 1 ; i--)
	{
		swap(A[0] , A[i]);
		heap_size--;
		MIN_HEAPIFY(A , heap_size , 0);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{

	int k = 10;
	int *A = new int[k]; 
	memset(A , 0 , k);

	ofstream fout("in.dat");
	for( int i = 0 ; i < 10000 ; i++)
	{
		fout<<i<<" ";
	}
	fout.close();
	
	ifstream fin("in.dat");
	top_k(fin , A , k);
	fin.close();
	cout<<"top_k = ";
	for( int i = 0 ; i < k ; i++)
	{
		cout<< A[i] << " ";
	}
	cout<<endl;

	heap_sort(A , k);

	for( int i = 0 ; i < k ; i++)
	{
		cout<< A[i] << " ";
	}
	cout<<endl;
	delete A;
	return 0;
}

