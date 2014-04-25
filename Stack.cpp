// Stack.cpp : 定义控制台应用程序的入口点。
//
//顺序栈的实现

#include <iostream>

using namespace std;

/*栈结构*/
typedef struct Stack
{
	int *base;//基地址
	int top;//栈顶索引
	int len;//栈空间的长度
}Stack;

/**
* 创建空栈
* @ n 为栈分配的空间
* @ return 创建好的空栈
*/
Stack* createStack(int n);

/**
* 入栈
* @ stack 栈指针
* @ value 入栈的值
*/
void push(Stack *stack, int value);

/**
* 出栈
* @ stack 栈指针
*/
void pop(Stack *stack);

/**
* 判断栈满
* @ stack 栈指针
* @ return 若满返回真，否则，返回假
*/
bool isFull(Stack *stack);

/**
* 判断栈空
* @ stack 栈指针
* @ return 若空返回真，否则，返回假
*/
bool isEmpty(Stack *stack);

/**
* 得到栈顶元素
* @ stack 栈指针
* @ return 栈顶元素
*/
int getTop(Stack *stack);

int _tmain(int argc, _TCHAR* argv[])
{
	Stack *stack;
	int n;
	//输入栈空间的大小
	cin>>n;
	stack = createStack(n);

	//入栈3个元素
	push(stack,1);
	push(stack,2);
	push(stack,3);
	cout<<stack->top<<endl;

	//出栈1个元素
	pop(stack);
	cout<<stack->top<<endl;

	//得栈顶元素
	int a = getTop(stack);
	cout<<a<<endl;
	return 0;
}

Stack* createStack(int n)
{
	Stack *stack;
	stack = new Stack();
	stack->base = new int[n];//分配栈空间
	stack->top = 0;//栈顶指针
	stack->len = n;//栈空间的长度
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