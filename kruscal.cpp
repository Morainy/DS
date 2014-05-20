/*************************************************************************
    > File Name: kruscal.cpp
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月18日 星期日 10时04分52秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define vertexNum 9
#define edgeNum 14

class Edge
{
public:
	int start;
	int end;
	int weight;
	Edge(int s , int e , int w)
	{
		this->start = s;
		this->end = e;
		this->weight = w;
	}
	Edge()
	{

	}
};

class Graph
{
public:
	Edge edge[edgeNum+1] , tree[vertexNum];
	int vertextArray[vertexNum+1];
	void initEdge();
	void insertEdge(int index , Edge & e)
	{
		this->edge[index] = e;
	}
	void showEdge();
	void sortEdge(Edge * e , int n);
	void kruscal(Edge * e , Edge * t , int m , int n);
	void showTree();
};
void Graph::initEdge()
{
	Edge e1(1 , 2 , 4);
	Edge e2(2 , 3 , 8);
	Edge e3(3 , 4 , 7);
	Edge e4(4 , 5 , 9);
	Edge e5(5 , 6 , 10);
	Edge e6(6 , 7 , 2);
	Edge e7(7 , 8 , 1);
	Edge e8(8 , 9 , 7);
	Edge e9(9 , 7 , 6);
	Edge e10( 9 , 3 , 2);
	Edge e11(8 , 2 , 11);
	Edge e12( 3 , 6 , 4);
	Edge e13( 4 , 6 , 14);
	Edge e14(8, 1, 8);
	this->insertEdge(1 , e1 );
	this->insertEdge(2 , e2 );
	this->insertEdge(3 , e3 );
	this->insertEdge(4 , e4 );
	this->insertEdge(5 , e5 );
	this->insertEdge(6 , e6 );
	this->insertEdge(7 , e7 );
	this->insertEdge(8 , e8 );
	this->insertEdge(9 , e9 );
	this->insertEdge(10 , e10);
	this->insertEdge(11 , e11);
	this->insertEdge(12 , e12 );
	this->insertEdge(13 , e13 );
	this->insertEdge(14 , e14 );
}
void Graph::showEdge()
{
	int i;
	for( i =1 ; i<=edgeNum ; i++)
	{
		cout<<edge[i].start<<"--->"<<edge[i].end<<"("<<edge[i].weight<<")"<<endl;
	}
}

void Graph::sortEdge(Edge * e , int n)
{
	int i , j ,k;
	Edge s;
	for( i=1 ; i< n+1 ;i++)
	{
		for( j=i ; j<n+1 ; j++)
		{
			if(e[i].weight > e[j].weight)
			{
				s = e[i];
				e[i] = e[j];
				e[j] = s;
			}
		}
	}
}

void Graph::kruscal(Edge * e , Edge * t , int m , int n) //m:edgenum  ,  n:vertexnum
{
	int i , j , k , h ;
	int sec[n+1];
	for(i=1 ; i<n+1 ; i++)
	{
		sec[i] = i;
	}
	j = 0;
	for(i =1 ; i<m+1 ; i++)
	{
		if(sec[e[i].start] == sec[e[i].end])
		{
			continue;
		}
		else
		{
			j++;
			t[j] = e[i];
			h = sec[e[i].start];
			for(k=1 ; k<n+1 ;k++)
			{
				if(sec[k] == h)
				{
					sec[k] = sec[e[i].end];
				}
			}
		}
	}
}

void Graph::showTree()
{
	int i;
	for( i =1 ; i<vertexNum ; i++)
	{
		cout<<tree[i].start<<"--->"<<tree[i].end<<"("<<tree[i].weight<<")"<<endl;
	}
}

int main (int argc , char * argv[])
{
	Graph g;
	g.initEdge();
	//g.showEdge();
	g.sortEdge(g.edge , edgeNum);
	cout<<endl;
	g.showEdge();
	cout<<endl;
	g.kruscal(g.edge ,g.tree, edgeNum , vertexNum);
	g.showTree();
	return 0;
}
