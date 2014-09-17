/*************************************************************************
    > File Name: floyd.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月23日 星期五 10时19分01秒
 ************************************************************************/

#include <stdio.h>

#define Min(a ,b) a<b?a:b
#define vertexNum 5
#define INF 100000

int w[vertexNum][vertexNum];
void initW (int w[][vertexNum])
{
	w[0][1] = 3;
	w[0][2] = 8;
	w[0][3] = INF;
	w[0][4] = -4;
	w[1][0] = INF;
	w[1][2] = INF;
	w[1][3] = 1;
	w[1][4] = 7;
	w[2][0] = INF;
	w[2][1] = 4;
	w[2][3] = INF;
	w[2][4] = INF;
	w[3][0] = 2;
	w[3][1] = INF;
	w[3][2] = -5;
	w[3][4] = INF;
	w[4][0] = INF;
	w[4][1] = INF;
	w[4][2] = INF;
	w[4][3] = 6;
}

int main( int argc ,char * argv[])
{
	initW(w);
	int Dpre[vertexNum][vertexNum];
	int Dcur[vertexNum][vertexNum];
	int i ,j ,k;
	for( i=0 ; i<vertexNum ;i++)
	{
		for(j =0 ; j<vertexNum ;j++)
		{
			Dpre[i][j] = w[i][j];
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

	for( i=0 ; i<vertexNum ;i++)
	{
		for(j =0 ; j<vertexNum ;j++)
		{
			printf("%d    " , Dcur[i][j]);
		}
		printf("\n");
	}
	return 0;
}