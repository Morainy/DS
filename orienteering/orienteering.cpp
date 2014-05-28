#include <iostream>

using namespace std;

#define MAX 1000
#define Min(a,b) a<b?a:b

class Orienteering
{
public:
	void main();
};
void Orienteering::main()
{
	int width , height;
	enum map{path , wall , start , goal , checkpoints};
	int vertexNum =0;
	typedef struct node
	{
		map ch;  
		int x ;
		int y;
	}node;
	cin>>width>>height;
	map ** m;
	m = new map * [height];
	int i , j;
	for( i =0 ; i<width ;i++)
	{
		m[i] = new map [width];
	}

	char ch;
	for(i =0 ; i<height ;i++)
	{
		for(j =0; j <width ;j++)
		{
			cin>>ch;
			if('#' == ch)
			{
				m[i][j] = wall;
			}
			else if('.' == ch)
			{
				m[i][j] = path;
				vertexNum++;
			}
			else if('S' == ch)
			{
				m[i][j] = start;
				vertexNum++;
			}
			else if('G' == ch)
			{
				m[i][j] = goal;
				vertexNum++;
			}
			else if('@' == ch)
			{
				m[i][j] = checkpoints;
				vertexNum++;
			}
		}
	}




	node * n = new node[vertexNum];
	int k =0;
	for( i=0 ; i<height ; i++)
	{
		for( j=0 ; j<width ;j++)
		{
			if(m[i][j] != wall)
			{
				n[k].ch = m[i][j];
				n[k].x = i;
				n[k].y = j;
				k++;
			}
		}
	}
	
	/***********************************
	*construct a adjArray
	************************************/
	int ** Dpre;
	int itemp , jtemp;
	Dpre = new int*[vertexNum];
	for(i = 0 ; i<vertexNum ;i++)
	{
		Dpre[i] = new int[vertexNum];
	}
	for(i=0 ; i<vertexNum ;i++)
	{
		for(j =0; j<vertexNum ;j++)
		{
			Dpre[i][j] = MAX;
			if(i == j)
			{
				Dpre[i][j] = 0;
			}
		}
	}
	for(i =0 ;i<height ;i++)
	{
		for(j =0 ; j<width ; j++)
		{
			if(m[i][j] != wall)
			{
				for(k =0 ;k<vertexNum;k++)
				{
					if(n[k].x == i && n[k].y == j)
					{
						itemp = k;
						break;
					}
				}
				if(m[i-1][j] != wall)   //UP
				{
					for(k =0 ;k<vertexNum;k++)
					{
						if(n[k].x == i-1 && n[k].y == j)
						{
							jtemp = k;
							Dpre[itemp][jtemp] = 1;
							break;
						}
					}
				}
				if(m[i+1][j] != wall)  //DOWN
				{
					for(k =0 ;k<vertexNum;k++)
					{
						if(n[k].x == i+1 && n[k].y == j)
						{
							jtemp = k;
							Dpre[itemp][jtemp] = 1;
							break;
						}
					}
				}
				if(m[i][j-1] != wall)  //LEFT
				{
					for(k =0 ;k<vertexNum;k++)
					{
						if(n[k].x == i && n[k].y == j-1)
						{
							jtemp = k;
							Dpre[itemp][jtemp] = 1;
							break;
						}
					}
				}
				if(m[i][j+1] != wall)  //RIGHT
				{
					for(k =0 ;k<vertexNum;k++)
					{
						if(n[k].x == i && n[k].y == j+1)
						{
							jtemp = k;
							Dpre[itemp][jtemp] = 1;
							break;
						}
					}
				}
				else    //default
				{

				}
			}
		}
	}

	/*************************************************
	*Floyd-warshell
	**************************************************/

	int ** Dcur;
	Dcur = new int*[vertexNum];
	for(i = 0 ; i<vertexNum ;i++)
	{
		Dcur[i] = new int[vertexNum];
	}
	for(i=0 ; i<vertexNum ;i++)
	{
		for(j =0; j<vertexNum ;j++)
		{
			Dcur[i][j] = 0;
		}
	}
	for(k = 0 ; k<vertexNum ; k++)
	{
		for( i =0 ;i<vertexNum ;i++)
		{
			for (j = 0; j < vertexNum; j++)
			{
				Dcur[i][j] = Min(Dpre[i][j] ,(Dpre[i][k] + Dpre[k][j]));
			}
		}
		for( i =0 ;i<vertexNum ;i++)
		{
			for (j = 0; j < vertexNum; j++)
			{
				Dpre[i][j] = Dcur[i][j];
			}
		}
	}

/*****************************************************
resolve problem
*****************************************************/
	int result =0;
	int S_index =0;
	int G_index =0;
	int minindex = 0;
	int checkpointsNum = 0;
	for( i =0 ; i < vertexNum ;i++)
	{
		if(n[i].ch == goal)
		{
			G_index = i;
		}
		if(n[i].ch == start)
		{
			S_index = i;
		}
		if(n[i].ch == checkpoints)
		{
			checkpointsNum++;
		}
	}

	int index = S_index;
	for (i =0; i<checkpointsNum ; i++)
	{
		j = 0;
		while(n[j].ch != checkpoints) j++;
		minindex = j;
		for(j = minindex+1; j<vertexNum ;j++)
		{
			if(n[j].ch == checkpoints && Dcur[index][j] < Dcur[index][minindex])
			{
				minindex = j;
			}
		}
		result +=Dcur[index][minindex];
		index = minindex;
		n[minindex].ch = path;
	}
	for(j =0 ; j<vertexNum ;j++)
	{
		if(n[j].ch == goal)
		{
				result +=Dcur[index][j];
		}
	}
	cout<<"result =  " << result<<endl;
	/*
	while(1)
	{
		for(i =0 ;i<vertexNum ;i++)
		{
			if(n[i].ch == start)
			{
				S_index = i;
			}
		}
		if(i>= vertexNum || S_index == G_index)
		{
			cout<<result<<endl;
			return;
		}
		else
		{
			for( i =0 ;i<vertexNum ; i++)
			{
				if(n[i].ch ==checkpoints && Dcur[S_index][i] <= Dcur[S_index][minindex])
				{
					minindex = i;
					//n[S_index].ch = path;
					//n[i].ch = start;
				}

			}
			n[S_index].ch = path;
			n[minindex].ch = start;
			result += Dcur[S_index][minindex];
		}
	}*/
	/*for( i=0 ; i<vertexNum ;i++)
	{
		for(j =0 ; j<vertexNum ;j++)
		{
			cout<<Dcur[i][j]<<" ";
		}
		cout<<endl;
	}*/
	/*for(i=0 ; i<vertexNum ;i++)
	{
		for(j =0 ;j<vertexNum ;j++)
		{
			cout<<Dpre[i][j]<<" ";
		}
		cout<<endl;
	}*/


	/*for( k =0 ; k<vertexNum ;k++)
	{
		cout<<n[k].ch<<" "<<n[k].x<<" "<<n[k].y<<" "<<endl;;
	}*/
	/*for( i=0 ; i<height ; i++)
	{
		for( j=0 ; j<width ;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"vertexNum = "<<vertexNum<<endl;*/


}
int main(int argc, char* argv[])
{
	Orienteering o;
	o.main();
	return 0;
}