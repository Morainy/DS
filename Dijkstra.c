/*************************************************************************
    > File Name: Dijkstra.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月22日 星期四 10时03分56秒
 ************************************************************************/

#include <stdio.h>

#define edgeNum 10
#define vertexNum 5
#define MAX 0x7fffffff
enum color{WHITE , BLACK};

typedef struct edge
{
	int start;
	int end;
	int weight;
}edge;

edge e[edgeNum];
int d[vertexNum];
enum color col[vertexNum];

void initEdge()
{
	e[0].start =0;
	e[0].end = 1;
	e[0].weight =10;
	e[1].start =1;
	e[1].end = 2;
	e[1].weight =1;
	e[2].start =2;
	e[2].end = 3;
	e[2].weight =4;
	e[3].start =3;
	e[3].end = 2;
	e[3].weight =6;
	e[4].start =1;
	e[4].end = 4;
	e[4].weight =2;
	e[5].start =4;
	e[5].end = 1;
	e[5].weight =3;
	e[6].start =4;
	e[6].end = 3;
	e[6].weight =2;
	e[7].start =4;
	e[7].end = 2;
	e[7].weight =9;
	e[8].start =0;
	e[8].end = 4;
	e[8].weight =5;
	e[9].start =3;
	e[9].end = 0;
	e[9].weight =7;

	/*
	e[0] = {0 , 1 , 10};
	e[1] = {1 , 2 , 1};
	e[2] = {2 , 3 , 4};
	e[3] = {3 , 2 , 6};
	e[4] = {1 , 4 , 2};
	e[5] = {4 , 1 , 3};
	e[6] = {4 , 3 , 2};
	e[7] = {4 , 2 , 9};
	e[8] = {0 , 4 , 5};
	e[9] = {3 , 0 , 7};
	*/
}
void initSingleSource(edge * e , int source)
{

	int i;
	for(i =0 ; i<vertexNum ; i++)
	{
		d[i] = MAX;
		col[i] = WHITE;
	}
	d[source] =0;
}
void relax(edge * ep)
{
	if(d[ep->end] > d[ep->start] + ep->weight)
	{
		d[ep->end] = d[ep->start] + ep->weight;
	}
}
int extractMin(int * d)
{
	int minIndex;
	int i;
	for(i =0; i<vertexNum ;i++)
	{
		if(col[i] == WHITE)
		{
			minIndex = i;
			break;
		}
	}
	for(i =0 ; i<vertexNum ;i++)
	{
		if(col[i] == WHITE)
		{
			if(d[i] < d[minIndex])
			{
				minIndex = i;	
			}
		}
	}
	return minIndex;
}
int allIsBlack (enum color * c)
{
	int i;
	for(i =0; i<vertexNum ; i++)
	{
		if(c[i] == WHITE)
		{
			return 0;
		}
	}
	return 1;
}
void Dijkstra(edge * e, int source)
{
	int u;
	initSingleSource(e , source);
	while(!allIsBlack( col ) )
	{
		u = extractMin(d);
		col[u] = BLACK;
		int i;
		for( i =0 ; i < edgeNum ; i++)
		{	
			relax(&e[i]);
		}
	}
}

int main (int argc , char * argv[])
{
	initEdge();
	Dijkstra(e , 0);
	int i;
	for(i =0 ; i<vertexNum ;i++)
	{
		printf("%d ", d[i]);
	}
	printf("\n");
	return 0;
}
