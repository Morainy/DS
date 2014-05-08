/*************************************************************************
    > File Name: huffman.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年ê05月?07日? 星?期ú三▂ 09时骸?4分?27秒?
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct huffmanTreeNode
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}huffmanTreeNode, *huffmanTree;

typedef struct huffmanCode
{
	int ch;
	char * code;
}huffmanCode;

void create_huffman_tree(huffmanTree * root,int weight[],int n);
void huffman_encode(huffmanTree root,huffmanCode *code ,int n);
void sel_2_min(huffmanTreeNode *pNode,int n,int * a1,int *a2);

void create_huffman_tree(huffmanTree *root,int weight[],int n)
{
	huffmanTreeNode * p = NULL;
	int s1,s2;
	int i,n_nodes=0;
	if(n<1)
	{
		return;
	}
	n_nodes =2*n-1;
	p=(huffmanTreeNode *)malloc(sizeof(huffmanTreeNode)*n_nodes);
	
	for(i=0;i<n_nodes;i++)
	{
		if(i<n)
		{
			p[i].weight = weight[i];
		}
		else
		{
			p[i].weight = 0;
		}
		p[i].parent=0;
		p[i].lchild =0;
		p[i].rchild=0;
	}
	for(i=n;i<n_nodes;i++)
	{
		sel_2_min(p,i,&s1,&s2);
		p[s1].parent=i;
		p[s2].parent=i;
		p[i].lchild=s1;
		p[i].rchild=s2;
		p[i].weight=p[s1].weight+p[s2].weight;
	}
	*root = p;
}

inline int max(int a,int b)
{
	return a > b ? a : b;
}

void sel_2_min(huffmanTreeNode *pNode,int n,int * a1,int *a2)
{
	int i;
	int min1,min2,min;
	min1 = min2 = 1000;
	for(i=0;i<n;i++)
	{
		if(pNode[i].parent==0)
		{
			min = max(min1,min2);
			if(pNode[i].weight < min)
			{
				if(min == min1)
				{
					min1 = pNode[i].weight;
					*a1 = i;
				}
				else
				{
					min2 = pNode[i].weight;
					*a2 = i;
				}
			}
		}
	}
}
void huffman_encode(huffmanTree root,huffmanCode *hcode,int n)
{
	int i,j,k,parentID;
	huffmanTreeNode * p= root;
	char * code = (char *) malloc(sizeof(char) * n);
	memset(code ,'\0',sizeof(char)*n);

	//hcode = (huffmanCode *)malloc(sizeof(huffmanCode)*n);
	for(i=0;i<n;i++)
	{
		hcode[i].ch=p[i].weight;
		hcode[i].code=(char *)malloc(sizeof(char)*n);
		memset(hcode[i].code,0,sizeof(char) *n);
	}
	for(i=0;i<n;i++)
	{
		k=n-1;
		code[k]='\0';
		j=i;
		while(p[j].parent!=0)
		{
			parentID=p[j].parent;
			if(p[parentID].lchild == j)
			{
				code[--k]='0';
			}
			else
			{
				code[--k]='1';
			}
			j=parentID;
		}
		strcpy(hcode[i].code, &code[k]);
	}
}

int  main(int argc,char * argv[])
{
	int i;
	int nodeWeight[]= {5,9,12,13,16,45};
	int length = sizeof(nodeWeight)/sizeof(nodeWeight[0]);
	huffmanTreeNode *root = NULL;
	huffmanCode * code = (huffmanCode *)malloc(sizeof(huffmanCode)*length);
	create_huffman_tree(&root,nodeWeight,length);
	huffman_encode(root,code,length);
	for(i=0;i<length;i++)
	{
		printf("%d:%s \n", code[i].ch,code[i].code); 
	}
	return 0;
}
