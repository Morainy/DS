/*************************************************************************
    > File Name: heap.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月06日 星期二 14时47分56秒
 ************************************************************************/

#include <stdio.h>
/*
 *求取第i个节点的父节点索引
 */
int PARENT (int i);
/*
 *求取左孩子索引
 * */
int LEFT (int i);
/*
 *求取右孩子索引
 * */
int RIGHT(int i);
/*
 *交换两个数的值
 * */
void swap(int *pa,int *pb);
/*
 *保持最大堆性质,i为节点索引，n为数组长度
 * */
void MAX_HEAPIFY(int *A,int i,int n);
//int HEAP_SIZE(int A[]);
/*
 *建立大端堆
 * */
void BUILD_MAX_HEAP(int *A,int n);

int main (int argc,char * argv[])
{ 
    int A[10]={4,1,3,2,16,9,10,14,8,7};
	int length = sizeof(A)/sizeof(A[0]);
	printf("length= %d \n",length);
    BUILD_MAX_HEAP(A,length);
    int i;
    for(i=0;i<length;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
	return 0;
}
int PARENT (int i)     //This is an error  ,  modified
{
	if(i % 2 == 0)
		return i/2 -1;
	else
		return i/2;
}
int LEFT (int i)
{
	return 2*i+1;
}
int RIGHT(int i)
{
	return 2*i+2;
}
void swap(int *pa,int *pb)
{
	int tmp;
	tmp=*pa;
	*pa=*pb;
	*pb=tmp;
}
void MAX_HEAPIFY(int *A,int i,int n)
{
	int l=LEFT(i);
	int r=RIGHT(i);
    int largest;
    if(l<n && A[l]>A[i])
    {
        largest = l;
    }    
    else
    {
        largest = i;
    }
    if(r<n && A[r]>A[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
		swap(&A[i],&A[largest]);
        MAX_HEAPIFY(A,largest,n);
    }
}
void BUILD_MAX_HEAP(int *A,int n)
{
    int i;
	//int length = HEAP_SIZE(A);
	//printf("length= %d \n",length);
    for(i=(n/2 -1);i>0;i--)            //This is another error, modified
    {
        MAX_HEAPIFY(A,i-1,n);
    }
}
