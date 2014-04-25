// SingleLinkList.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>

using namespace std;

/*������Ľڵ�*/
typedef struct Node
{
	int data;//������
	struct Node *next;//ָ����
}Node;

/*������*/
typedef struct List
{
	Node *head;//ͷ�ڵ�ָ��
	int len;
}List;


/**
* ������ͷ�ڵ�ĵ�����
* ����ͷ�ڵ�Ĳ���if..else̫�������Խ�����˿��Էǵ�Ҫ�󲻴�ͷ�ڵ�ĵ�����������������ͷ�ڵ��
* @ list ����
* @ return ������
*/
List *createLinkList(List *list);


/**
* ����Ԫ��
* @ list ����
* @ value ����ֵ
* @ pos �����λ�ã��������value������ֵ
*/
void insert(List *list, int value,int pos);

/**
* ɾ��Ԫ��
* @ list ����
* @ value ɾ��ֵ
*/
void delet(List *list, int value);

int _tmain(int argc, _TCHAR* argv[])
{
	List *list = NULL;
	list = createLinkList(list);
	
	cout<<"�����Ŀ�����ĳ���Ϊ��"<<list->len<<endl;
	insert(list,1,0);
	insert(list,2,0);
	insert(list,3,0);
	cout<<"����Ԫ�غ�������Ϊ��"<<list->len<<endl;
	Node *p;
	for(p = list->head->next; p != NULL; p = p->next)
		cout<<p->data<<" ";
	cout<<endl;
	delet(list,2);
	cout<<"ɾ��Ԫ�غ�����ĳ���Ϊ��"<<list->len<<endl;
	for(p = list->head->next; p != NULL; p = p->next)
		cout<<p->data<<" ";
	cout<<endl;
	return 0;
}

List *createLinkList(List *list)
{
	//����һ��������
	list = new List();
	//Ϊͷ�ڵ����ռ䣬����ʼ������
	list->head = new Node();
	list->head->data = -1;
	list->head->next = NULL;
	list->len = 0;

	return list;
}

void insert(List *list, int value, int pos)
{
	if(pos > list->len)
	{//λ��Խ��
		cout<<"pos error"<<endl;
		return;
	}
	//����value��Ҫ����λ�õ�ǰ��
	Node *p = list->head;
	for(int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	Node *v = new Node();
	//��װvalueֵ��һ���ڵ㣬���Ҳ���
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