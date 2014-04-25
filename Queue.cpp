// Queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*ѭ������*/
#include <iostream>

using namespace std;

/*���нṹ*/
typedef struct Queue
{
	int *data;//���л���ַ
	int head;//����ͷ���ڵ�����
	int tail;//����β���ڵ�����
	int len;//����Ķӿռ�
}Queue;

/**
* ��������
* @ n ���е���󳤶�
* @ return �����õĿն���
*/
Queue* createQueue(int n);

/**
* ���
* @ queue ����
* @ value ��ӵ�ֵ
*/
void enQueue(Queue *queue, int value);

/**
* ����
* @ queue ����
*/
void deQueue(Queue *queue);

/**
* �ö���Ԫ��
* @ queue ����
* @ return ��ͷԪ��
*/
int getHead(Queue *queue);

/**
* �ж϶���
* @ queue ����
* @ return �������������棬���򣬷��ؼ�
*/
bool isFull(Queue *queue);

/**
* �ж϶ӿ�
* @ queue ����
* @ return ���ӿգ������棬���򣬷��ؼ�
*/
bool isEmpty(Queue *queue);

int _tmain(int argc, _TCHAR* argv[])
{
	Queue *queue;
	int n;
	//������пռ�
	cin>>n;
	queue = createQueue(n);

	//���3��Ԫ��
	enQueue(queue,1);
	enQueue(queue,2);
	enQueue(queue,3);
	cout<<getHead(queue)<<endl;

	deQueue(queue);
	cout<<getHead(queue)<<endl;
	return 0;
}

Queue* createQueue(int n)
{
	Queue *queue = new Queue();
	queue->data = new int[n];
	queue->head = 0;
	queue->tail = 0;
	queue->len = n;

	return queue;
}

void enQueue(Queue *queue, int value)
{
	if(!isFull(queue))
	{
		queue->data[queue->tail] = value;
		queue->tail = (queue->tail + 1) % queue->len;
	}
	else
		cout<<"queue is full"<<endl;
}

void deQueue(Queue *queue)
{
	if(!isEmpty(queue))
	{
		queue->head = (queue->head + 1) % queue->len;
	}
	else
		cout<<"queue is empty"<<endl;
}

int getHead(Queue *queue)
{
	if(!isEmpty(queue))
		return queue->data[queue->head];
	else
		return -1;
}

bool isFull(Queue *queue)
{
	if(queue->head == (queue->tail + 1) % queue->len)
		return true;
	return false;
}

bool isEmpty(Queue *queue)
{
	if(queue->head == queue->tail)
		return true;
	return false;
}

