// Queue.cpp : 定义控制台应用程序的入口点。
//

/*循环队列*/
#include <iostream>

using namespace std;

/*队列结构*/
typedef struct Queue
{
	int *data;//队列基地址
	int head;//队列头所在的索引
	int tail;//队列尾所在的索引
	int len;//分配的队空间
}Queue;

/**
* 创建队列
* @ n 队列的最大长度
* @ return 创建好的空队列
*/
Queue* createQueue(int n);

/**
* 入队
* @ queue 队列
* @ value 入队的值
*/
void enQueue(Queue *queue, int value);

/**
* 出队
* @ queue 队列
*/
void deQueue(Queue *queue);

/**
* 得队首元素
* @ queue 队列
* @ return 对头元素
*/
int getHead(Queue *queue);

/**
* 判断队满
* @ queue 队列
* @ return 若队满，返回真，否则，返回假
*/
bool isFull(Queue *queue);

/**
* 判断队空
* @ queue 队列
* @ return 若队空，返回真，否则，返回假
*/
bool isEmpty(Queue *queue);

int _tmain(int argc, _TCHAR* argv[])
{
	Queue *queue;
	int n;
	//输入队列空间
	cin>>n;
	queue = createQueue(n);

	//入队3个元素
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

