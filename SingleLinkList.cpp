// SingleLinkList.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>

using namespace std;

/*单链表的节点*/
typedef struct Node
{
	int data;//数据域
	struct Node *next;//指针域
}Node;

/*单链表*/
typedef struct List
{
	Node *head;//头节点指针
	int len;
}List;


/**
* 创建带头节点的单链表
* 不带头节点的操作if..else太烦，所以建议除了考试非得要求不带头节点的单链表，其他都建立有头节点的
* @ list 链表
* @ return 单链表
*/
List *createLinkList(List *list);


/**
* 插入元素
* @ list 链表
* @ value 插入值
* @ pos 插入的位置，即插入后value的索引值
*/
void insert(List *list, int value,int pos);

/**
* 删除元素
* @ list 链表
* @ value 删除值
*/
void delet(List *list, int value);

int _tmain(int argc, _TCHAR* argv[])
{
	List *list = NULL;
	list = createLinkList(list);
	
	cout<<"创建的空链表的长度为："<<list->len<<endl;
	insert(list,1,0);
	insert(list,2,0);
	insert(list,3,0);
	cout<<"插入元素后链表长度为："<<list->len<<endl;
	Node *p;
	for(p = list->head->next; p != NULL; p = p->next)
		cout<<p->data<<" ";
	cout<<endl;
	delet(list,2);
	cout<<"删除元素后链表的长度为："<<list->len<<endl;
	for(p = list->head->next; p != NULL; p = p->next)
		cout<<p->data<<" ";
	cout<<endl;
	return 0;
}

List *createLinkList(List *list)
{
	//创建一个空链表
	list = new List();
	//为头节点分配空间，并初始化链表
	list->head = new Node();
	list->head->data = -1;
	list->head->next = NULL;
	list->len = 0;

	return list;
}

void insert(List *list, int value, int pos)
{
	if(pos > list->len)
	{//位置越界
		cout<<"pos error"<<endl;
		return;
	}
	//查找value想要插入位置的前驱
	Node *p = list->head;
	for(int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	Node *v = new Node();
	//包装value值到一个节点，并且插入
	v->data = value;
	v->next = p->next;
	p->next = v;
	list->len ++;
}

void delet(List *list, int value)
{
	Node *p1,*p2;
	p1 = list->head;
	p2 = p1->next;
	while(p2 != NULL)
	{
		if(p2->data == value)
		{
			p1->next = p2->next;
			delete p2;
			list->len --;
		}
		else
			p1 = p1->next;
		p2 = p1->next;
	}
}