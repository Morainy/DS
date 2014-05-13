/*************************************************************************
    > File Name: linkList.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月12日 星期一 21时39分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LIST_HEAD_INIT(name) {&name,&name}
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)
#define INIT_LIST_HEAD(ptr) do{   \
    (ptr)->next = (ptr) ; (ptr)->prev = (ptr); \
}while(0)
//#define offset(TYPE , MEMBER) (size_t) ((TYPE *)0)->MEMBER
//#define container_of(ptr, type , member)   (type *)(((char *)ptr) - offset(type , member))
#define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)  
#define container_of(ptr,type,member) ({   \
		const typeof(((type *)0)->member )*__mptr = (ptr);  \
		(type *) ((char *)__mptr - offsetof(type,member));  \
		})
#define list_entry(ptr,type,member) container_of(ptr,type,member)
/******************************************************
 *循环链表头部数据结构的定义
 *prev指向前驱节点
 *next指向后继节点
 ******************************************************/
struct  list_head
{
	struct list_head * prev , * next;
};
/*****************************************************
 *myList为自己所定义的链表
 *myData指向链表中所要包含的数据部分
 *list包含了所需要的指针
 ****************************************************/
struct myList
{
	//void * myData;
	int myData;
	struct list_head list;
};
/*****************************************************
 *检测链表是否为空
 *输入：链表头节点指针域
 *输出：为空返回1，否则，返回0
 ****************************************************/
int list_empty(struct list_head mylist_head)
{
	if(mylist_head.prev == mylist_head.next)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/**************************************************
 *add node in linklist
 *input:pointer to new node , pointer to prev node , pointer to next node
 *output:void
 *************************************************/
static inline void __list_add(struct list_head * new , struct list_head *prev,struct list_head* next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}
/*************************************************
 *add node at after head of linklist
 *input:pointer of new node , pointer of head 
 *output:void
 ************************************************/
static inline void list_add (struct list_head *new , struct list_head *head)
{
	__list_add(new , head , head->next);
}
/*************************************************
 *add node at before head of linklist
 *input:pointer of new node , pointer of head 
 *output:void
 ************************************************/
static inline void list_add_tail (struct list_head *new , struct list_head *head)
{
	__list_add(new , head->prev , head);
}
/************************************************
 *traversal each node of linklist
 *input:pointer of head of linklist
 *output:void 
 ************************************************/
void each_of_list(struct list_head * head)
{
	struct list_head * pos;
	struct myList * p;
	for(pos = (head) ->next ; pos!=(head) ; pos = pos->next)
	{
		p =  container_of(pos,struct myList,list);
		//printf("%d ",*((int *)(p->myData))  );
		printf("%d ",p->myData);
	}
	printf("\n");
}
int main (int argc , char * argv[])
{
	int i;
	//struct list_head *head = (struct list_head *) malloc (sizeof(struct list_head));
	LIST_HEAD(head);
	//INIT_LIST_HEAD(head);
	for( i=0 ; i<10 ; i++)
	{
		//int temp = i;
		struct myList* new = (struct myList *) malloc(sizeof(struct myList));
		new->myData = i;
		list_add ( &(new->list) , &head);
		//list_add_tail(&(new.list) , &head);
	}
	each_of_list(&head);
	return 0;
}
