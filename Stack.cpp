// Stack.cpp : �������̨Ӧ�ó������ڵ㡣
//
//˳��ջ��ʵ��

#include <iostream>

using namespace std;

/*ջ�ṹ*/
typedef struct Stack
{
	int *base;//����ַ
	int top;//ջ������
	int len;//ջ�ռ�ĳ���
}Stack;

/**
* ������ջ
* @ n Ϊջ����Ŀռ�
* @ return �����õĿ�ջ
*/
Stack* createStack(int n);

/**
* ��ջ
* @ stack ջָ��
* @ value ��ջ��ֵ
*/
void push(Stack *stack, int value);

/**
* ��ջ
* @ stack ջָ��
*/
void pop(Stack *stack);

/**
* �ж�ջ��
* @ stack ջָ��
* @ return ���������棬���򣬷��ؼ�
*/
bool isFull(Stack *stack);

/**
* �ж�ջ��
* @ stack ջָ��
* @ return ���շ����棬���򣬷��ؼ�
*/
bool isEmpty(Stack *stack);

/**
* �õ�ջ��Ԫ��
* @ stack ջָ��
* @ return ջ��Ԫ��
*/
int getTop(Stack *stack);

int _tmain(int argc, _TCHAR* argv[])
{
	Stack *stack;
	int n;
	//����ջ�ռ�Ĵ�С
	cin>>n;
	stack = createStack(n);

	//��ջ3��Ԫ��
	push(stack,1);
	push(stack,2);
	push(stack,3);
	cout<<stack->top<<endl;

	//��ջ1��Ԫ��
	pop(stack);
	cout<<stack->top<<endl;

	//��ջ��Ԫ��
	int a = getTop(stack);
	cout<<a<<endl;
	return 0;
}

Stack* createStack(int n)
{
	Stack *stack;
	stack = new Stack();
	stack->base = new int[n];//����ջ�ռ�
	stack->top = 0;//ջ��ָ��
	stack->len = n;//ջ�ռ�ĳ���
	return stack;
}

void push(Stack *stack, int value)
{
	if(!isFull(stack))
		stack->base[stack->top++] = value;
}

void pop(Stack *stack)
{
	if(!isEmpty(stack))
		stack->top --;
}

int getTop(Stack *stack)
{
	if(!isEmpty(stack))
		return stack->base[stack->top - 1];
	return -1;
}

bool isFull(Stack *stack)
{
	if(stack->top >= stack->len)
		return true;
	return false;
}

bool isEmpty(Stack *stack)
{
	if(stack->top == 0)
		return true;
	return false;
}