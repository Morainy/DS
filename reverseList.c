/*************************************************************************
    > File Name: reverseList.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月01日 星期一 16时40分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct linkList
{
	ElemType val;
	struct linkList * next;
} linkList;

linkList* createList()
{
	linkList * head = NULL;
	return head;
}
void addNode(linkList * & head, ElemType val)
{
	linkList * pNode = (linkList *) malloc(sizeof(linkList));
	pNode->val = val;
	pNode->next = NULL;
	if(head == NULL)
	{
		head = pNode;
		//printf("head== %d\n" ,(unsigned int) head);
		return ;
	}
	linkList * p;
	for(p = head ; p->next != NULL ; p = p->next );
	p->next = pNode;
}
void showList(linkList * head)
{
	linkList * p;
	for(p = head ; p != NULL ; p = p->next)
	{
		printf("%d ",p->val );
	}
	printf("\n");

}
void deleteList(linkList * head)
{
	linkList * pCur , * pNext;
	for(pCur = head ; pCur != NULL ; pCur = pNext)
	{
		pNext = pCur->next;
		free(pCur);
	}
}

void reverseList(linkList *& head)
{
	if(head == NULL || head->next == NULL)
	{
		return;
	}
	linkList * pPre , * pCur , * pNext;
	pPre = head;
	pCur = head->next;
	pNext = NULL;
	while(pCur != NULL)
	{
		pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	head->next = NULL;
	head = pPre;
}

/**********************************************************
*
*find the preNode of p
*
**********************************************************/

linkList * findPre(linkList * head , linkList *p)
{
	linkList * tmp = head;
	while(tmp != NULL)
	{
		if(tmp->next == p)
		{
			break;
		}
		tmp = tmp->next;
	}
	return tmp;
}

/****************************************************
*
*swap the p1 and p2
*
*****************************************************/
void swap(linkList* head,  linkList * &p1 , linkList * &p2)
{
	if( p1 == head || p2 == head)
	{
		return ;
	}
	if(p1 == p2)
	{
		return ;
	}
	linkList * pPre1 = findPre(head , p1);
	linkList * pPre2 = findPre(head , p2);
	linkList * pPost1 = p1->next;
	linkList * pPost2 = p2->next;
	if(p1->next == p2)
	{
		pPre1->next = p2;
		p2->next = p1;
		p1->next = pPost2;
		return;
	}
	if(p2->next == p1)
	{
		pPre2->next = p1;
		p1->next = p2;
		p2->next = pPost1;
		return;
	}


	pPre1->next = p2;
	p2->next = pPost1;
	pPre2->next = p1;
	p1->next = pPost2;
}

linkList * findK(linkList * head , int k)
{
	int i;
	linkList * p = head;
	for( i = 0 ; i < k ; i++)
	{
		if( p == NULL)
			break;
		p = p->next;
	}
	return p;
}
int main(int argc , char * argv[])
{
	int i;
	linkList * h = createList();
	for( i = 0 ; i < 20 ; i++)
	{
		addNode(h , i);
	}
	showList(h);
	//reverseList(h);
	linkList * node1 = findK(h , 4);
	linkList * node2 = findK(h , 5);
	swap(h , node1 , node2);
	showList(h);
	deleteList(h);
}
