#include <iostream>

using namespace std;

#define MAX 1000
#define Min(a,b) a<b?a:b

class Orienteering
{
public:
	void main();
	long long  factorical(int n);
	int searchI (int *a ,int n);
	int searchJ (int * a ,int i, int n);
	void swap(int *a,int *b);
	void reverse (int *a , int start ,int end);
};

long long Orienteering:: factorical(int n)
{
	int i;
	long long  res = 1;
	for(i =1 ; i<=n ; i++)
	{
		res = res * i;
	}
	return res;
}
int Orienteering::searchI (int *a ,int n)
{
	int k ,i = 1;
	for(k=2 ; k<=n ;k++)
	{	
		if(a[k]>a[k-1] && (i<k))
		{
			i = k;
		}
	}
	return i;
}
int Orienteering::searchJ (int * a ,int i, int n)
{
	int k , j =1;
	for(k=1 ; k<=n ;k++)
	{
		if((a[i-1] <a[k]) && (j<k) )
		{
			j = k;
		}
	}
	return j;
}

void Orienteering::swap(int *a,int *b)
{
	if(*a!=*b)
	{
		*a=*a^*b;
		*b=*b^*a;
		*a=*a^*b;
	}
}
void Orienteering::reverse (int *a , int start ,int end)
{
	int i = start;
	int j = end;
	while (j > i)
	{
		swap(&a[i] , &a[j]);
		i++;
		j--;
	}

}
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
/*******************************************************
*PERMUTAION
**********************************************************/

	 
/*****************************************************
*resolve problem
*****************************************************/
	
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

	int *a = new int[checkpointsNum+1];
	j=1;
	for(i = 0 ; i<=vertexNum ;i++)
	{
		if(n[i].ch == checkpoints)
		{
			a[j] = i;
			//cout<<a[j]<<" ";
			j++;
		}
	}
	
	//cout<<endl;
	int index = S_index;
	int result =0x7fffffff;
	int resulttemp = 0;
	for(i = 1 ; i<= factorical(checkpointsNum) ;i++)
	{
		index = S_index;
		resulttemp = 0;
		for(j =1 ; j<= checkpointsNum; j++)
		{
			resulttemp +=Dcur[index][a[j]];
			index = a[j];
		}
		for(j =0 ; j<vertexNum ;j++)
		{
			if(n[j].ch == goal)
			{
					resulttemp +=Dcur[index][j];
			}
		}
		if(resulttemp < result)
		{
			result = resulttemp;
		}

		itemp = searchI(a , checkpointsNum);
		jtemp = searchJ(a , itemp , checkpointsNum);
		swap(&a[itemp-1] , &a[jtemp]);
		reverse(a , itemp , checkpointsNum);
	}
	cout<<result<<endl;
	delete a;
}
int main(int argc, char* argv[])
{
	Orienteering o;
	o.main();
	return 0;
}
