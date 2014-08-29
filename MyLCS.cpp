#include <stdafx.h>
#include <string>
#include <iostream>
using namespace std;


int LCS(const char * str1 , const char * str2 , char  * &subStr)
{
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	int  ** tempArray;
	int maxlength = -1 ;
	tempArray = new int * [length1];
	for( int i = 0 ; i < length1 ; i++)
	{
		tempArray[i] = new int [length2];
	} 
	for( int i = 0 ; i < length1 ; i++)
	{
		for( int j = 0 ; j < length2 ; j++)
		{
			tempArray[i][j] = 0;
		}
	}
	for( int i = 0 ; i < length1 ; i++)
	{
		for( int j = 0 ; j < length2 ; j++)
		{
			int k ;
			int maxtemp;
			if(str1[i] == str2[j] )
			{
				if( (i-1) >= 0 && (j - 1) >= 0)
				{
					tempArray[i][j] = tempArray[i-1][j-1] + 1;
					if(maxlength < tempArray[i][j])
					{
						maxlength = tempArray[i][j];
						maxtemp = maxlength;
						k = i;
						while(maxtemp >= 0)
						{
							subStr[--maxtemp] = str1[--k];
						}
					}
				}
			}
		}
	}

	for( int i = 0 ; i < length1 ; i++)
	{
		delete tempArray[i];
	}
	delete tempArray;
	return maxlength;
}
int main(int argc , char * argv[])
{
	const char *str1 = "abacaba";
	const char *str2 = "caba";
	char *sub;
	sub = new char[256];
	memset(sub , 0 , 256 );
	int max;
	max = LCS(str1 , str2 , sub);

	cout<<"max = "<<max<<endl;
	cout<<"sub = "<<sub<<endl;
}