/*************************************************************************
    > File Name: prim.cpp
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月21日 星期三 08时59分16秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define N 9            //vertexNum
#define MAX 0x7fffffff
enum color{WHITE , BLACK};

class Vertex
{
	public:
		int id;
		int weight;
		Vertex * next;
		Vertex()
		{
			this->id = 0;
			this->weight = 0;
			this->next = NULL;
		}
		Vertex(int end , int weight)
		{
			this->id = end;
			this->weight = weight;
			this->next =NULL;
		}
};
/*class Line
{
	public:
	int start;
	int end;
	int weight;
	Line(int s , int e , int w)
	{
		this->start = s;
		this->end = e;
		this->weight = w;
	}
}*/
class Graph
{
	public:
		int edgeNum;
		Vertex * Adj[N+1];
		Graph()
		{
			edgeNum = 0;
			int i;
			for(i=1 ; i<=N ; i++)
			{
				Adj[i] = new Vertex;
				Adj[i]->id = i;
			}
		}
		void insertLine(int start , int end , int weight);
		void initGraph();
		void showGraph();
		~Graph()
		{
			int i;
			for(i=1 ; i<=N ; i++)
			{
				delete Adj[i];
			}
		}
};
void Graph::insertLine(int start , int end , int weight)
{
	//Line * l = new Line(start , end , weight);
	Vertex * v = new Vertex(end , weight);
	/*if(this->Adj[start]->next == NULL)
	{
		delete this->Adj[start];
		this->Adj[start] = v;
	}*/
	Vertex * temp;
	/*for(temp = this->Adj[start] ; temp->next != NULL ; temp = temp->next)
	{

	}*/
	temp = this->Adj[start];
	while(temp->next)
	{
		temp = temp ->next;
	}
	temp->next = v ;
	edgeNum++;
}
void Graph::initGraph()
{
	insertLine(1 , 2 , 4);
	insertLine(2 , 1 , 4);
	insertLine(2 , 3 , 8);
	insertLine(3 , 2 , 8);
	insertLine(3 , 4 , 7);
	insertLine(4 , 3 , 7);
	insertLine(4 , 5 , 9);
	insertLine(5 , 4 , 9);
	insertLine(5 , 6 , 10);
	insertLine(6 , 5 , 10);
	insertLine(6 , 7 , 2);
	insertLine(7 , 6 , 2);
	insertLine(7 , 8 , 1);
	insertLine(8 , 7 , 1);
	insertLine(8 , 9 , 7);
	insertLine(9 , 8 , 7);
	insertLine(3 , 9 , 2);
	insertLine(9 , 3 , 2);
	insertLine(2 , 8 , 11);
	insertLine(8 , 2 , 11);
	insertLine(8 , 1 , 8);
	insertLine(1 , 8 , 8);
	insertLine(9 , 7 , 6);
	insertLine(7 , 9 , 6);
	insertLine(3 , 6 , 4);
	insertLine(6 , 3 , 4);
	insertLine(4 , 6 , 14);
	insertLine(6 , 4 , 14);

}
void Graph::showGraph()
{
	int i;
	Vertex * temp;
	for(i =1 ; i<=N ; i++)
	{
		//cout<<i<<"--->";
		temp = Adj[i];
		while(temp->next)
		{
			cout<<temp->id<<"(weight="<<temp->weight<<")"<<"--->";
			temp = temp->next;
		}
		cout<<temp->id<<"(weight="<<temp->weight<<")"<<endl;
	}
	cout<<"edgeNum = "<<edgeNum<<endl;
}
class treeNode
{
	public:
		int start;
		int end;
		int weight;
};
class tree
{
	public:
		int treeNodeNum ;
		color c[N+1];
		treeNode t[N];
		treeNode * searchMin(Vertex ** Adj , int n);
		void showTree(treeNode *t);
		void prim(treeNode *t , Vertex ** Adj);
		tree()
		{
			int i;
			for(i=1;i<=N;i++)
			{
				c[i] = WHITE;
			}
			treeNodeNum =0;
		}
};
treeNode * tree::searchMin(Vertex ** Adj , int n)
{
	treeNode * p = new treeNode();
	int i , j;
	int flag = 1;
	int min = MAX;
	for(j = 1 ; j<=n ; j++)
	{
		if(c[j] == BLACK)
		{
			flag = 0 ;
		}
	}
	if(flag)  //all vertex are WHITE
	{
		Vertex * temp;
		for(i=1 ; i<=n ; i++)
		{
			min = MAX;
			temp = Adj[i];
			while(temp != NULL)
			{
				if(temp->id == i)
				{
					temp = temp->next;
					continue;
				}
				if(temp->weight < min)
				{
					min = temp->weight;
					p->start = i;
					p->end = temp->id;
					p->weight = min;
				}
				temp = temp->next;
			}
		}
	}
	else
	{
		for(i=1 ; i<=treeNodeNum ; i++)
		{
			Vertex * temp;
			min = MAX;
			for(temp = Adj[t[i].start] ; temp != NULL ;temp = temp->next)
			{
				if(temp->id == t[i].start)
				{
					continue;
				}
				if( c[t[i].start] == BLACK && c[temp->id] == BLACK)
				{
					continue;
				}
				else
				{
					if(temp->weight < min)
					{
						min = temp->weight;
						p->start = t[i].start;
						p->end = temp->id;
						p->weight = min;
					}
				}
			}
			for(temp = Adj[t[i].end] ; temp != NULL ;temp = temp->next)
			{
				if(temp->id == t[i].end)
				{
					continue;
				}
				if( c[t[i].end] == BLACK && c[temp->id] == BLACK)
				{
					continue;
				}
				else
				{
					if(temp->weight < min)
					{
						min = temp->weight;
						p->start = t[i].end;
						p->end = temp->id;
						p->weight = min;
					}
				}
			}
		}
	}
	return p;
}
void tree::showTree(treeNode *t)
{
	int i;
	for(i =1 ; i<N ;i++)
	{
		cout<<t[i].start<<"--->"<<t[i].end<<" ("<<t[i].weight<<")"<<endl;
	}
}
void tree::prim(treeNode *t , Vertex ** Adj)
{
	while(treeNodeNum < N)
	{
		treeNode * p = searchMin(Adj, N);
		treeNodeNum++;
		t[treeNodeNum].start =  p->start;
		t[treeNodeNum].end = p->end;
		t[treeNodeNum].weight = p->weight;
		c[p->start] = BLACK;
		c[p->end] = BLACK;
	}
}
int main(int argc ,char * argv[])
{
	Graph g;
	g.initGraph();
	//g.showGraph();
	tree T;
	T.prim(T.t , g.Adj);
	T.showTree(T.t);
}
