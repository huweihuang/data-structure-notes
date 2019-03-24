# 顺序栈的基本运算

```c
#include <stdio.h>

typedef char ElemType;

#define StackSize 100		/*顺序栈的初始分配空间*/

typedef struct 
{	
	ElemType data[StackSize];	/*保存栈中元素*/
	int top;					/*栈指针*/
} SqStack;

void InitStack(SqStack &st)		/*st为引用型参数*/
{
	st.top=-1;
}

int Push(SqStack &st,ElemType x)	/*进栈运算,st为引用型参数*/
{
	if (st.top==StackSize-1)	/*栈满*/
		return 0;
	else						/*栈不满*/
	{
		st.top++;
		st.data[st.top]=x;
		return 1;    	
	}
}

int Pop(SqStack &st,ElemType &x)		/*出栈运算,st和x为引用型参数*/
{
	if (st.top==-1)		/*栈空*/
		return 0;
	else				/*栈不空*/
	{
		x=st.data[st.top];
		st.top--;
		return 1;
	}
}

int GetTop(SqStack st,ElemType &x)	/*取栈顶元素,x为引用型参数*/
{
	if (st.top==-1)		/*栈空*/
		return 0;
	else 
	{
		x=st.data[st.top];
		return 1;
	}
}

int StackEmpty(SqStack st)	/*判断栈空运算*/
{
	if (st.top==-1)	/*栈空*/
		return 1;
	else			/*栈不空*/
		return 0;
}

void main()
{
	SqStack st;
	ElemType e;
	InitStack(st);
	printf("栈%s\n",(StackEmpty(st)==1?"空":"不空"));
	printf("a进栈\n");Push(st,'a');
	printf("b进栈\n");Push(st,'b');
	printf("c进栈\n");Push(st,'c');
	printf("d进栈\n");Push(st,'d');
	printf("栈%s\n",(StackEmpty(st)==1?"空":"不空"));
	GetTop(st,e);
	printf("栈顶元素:%c\n",e);
	printf("出栈次序:");
	while (!StackEmpty(st))
	{
		Pop(st,e);
		printf("%c ",e);
	}
	printf("\n");
}
```
