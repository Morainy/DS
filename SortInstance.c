// qsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>


int cmp(const void * a ,const void * b)
{
	return (*(int *)a - *(int *)b);
}
void swap(int * a , int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int division(int * a , int p , int  r)
{
	int x = a[r -1];
	int i = p-1;
	int j;
	for(j = p ; j < r-1 ; j++)
	{
		if(a[j] <= x)
		{
			i++;
			swap(&a[i] , &a[j]);
		}
	}
	swap(&a[i + 1] , &a[r - 1]);
	return i + 1;
}

void quiksort(int * a , int p , int r )
{
	if(p < r)
	{
		int q = division(a , p , r);
		quiksort(a , p ,q -1 );
		quiksort(a , q+1 , r);
	}
}

int merge(int *s1 ,int n1 , int *s2 ,int n2, int *des)
{
	int i , j , k = 0;
	for(i = 0 , j = 0 ; (i < n1) && (j < n2) ;)
	{
		if(s1[i] <= s2[j])
		{
			des[k++] = s1[i++];
		}
		else
		{
			des[k++] = s2[j++];
		}
	}
	while(i < n1)
	{
		des[k++] = s1[i++];
	}
	while(j < n2)
	{
		des[k++] = s2[j++];
	}
	return k;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {5 , 3 , 76 , 34 ,  89 , 55, 325 , 564};
	int lengthA = sizeof(a)/sizeof(a[0]);
	//qsort(a  , lengthA , sizeof(a[0]) , cmp );
	quiksort(a , 0 , lengthA);
	int b[] = {2 , 5 , 6 , 9 , 10};
	int lengthB = sizeof(b)/sizeof(b[0]);
	int * des =(int *) malloc((lengthA + lengthB) * sizeof(int) );
	memset(des , 0 , (lengthA + lengthB) * sizeof(int));
	int lengthDes = merge(a , lengthA , b , lengthB , des);
	int i;
	for(i = 0 ; i <lengthDes ; i++ )
	{
		printf("%d ", des[i]);
	}
	printf("\n");
	free(des);
	/*
	void * keyPointer;
	int key = 89;
	keyPointer = bsearch(&key , a , lengthA , sizeof(a[0]) , cmp);
	printf("keyPointer = 0x%x \n" , keyPointer);
	printf("*keyPointer = %d \n" , (*(int *)keyPointer));
	*/
	system("pause");
	return 0;
}

