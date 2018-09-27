#include <stdio.h>
#define QueueSize 100

typedef char ElemType;

typedef struct  
{	
	ElemType data[QueueSize];	/*保存队中元素*/
	int front,rear;				/*队头和队尾指针*/
} SqQueue;

void InitQueue(SqQueue &qu)		/*qu为引用型参数*/
{
   	qu.rear=qu.front=0;           /*指针初始化*/
} 

int EnQueue(SqQueue &qu,ElemType x)	/*入队运算,qu为引用型参数*/
{
	if ((qu.rear+1)%QueueSize==qu.front)	/*队满*/
		return 0;
	qu.rear=(qu.rear+1)%QueueSize;      /*队尾指针进1*/
	qu.data[qu.rear]=x;
	return 1;
}

int DeQueue(SqQueue &qu,ElemType &x)	/*出队运算,qu和x为引用型参数*/
{
    if (qu.rear==qu.front)
		return 0;
    qu.front=(qu.front+1)%QueueSize;    /*队头指针进1*/
    x=qu.data[qu.front];
    return 1;
}

int GetHead(SqQueue qu,ElemType &x)		/*取队头元素运算,x为引用型参数*/
{
	if (qu.rear==qu.front)		/*队空*/
		return 0;
	x=qu.data[(qu.front+1)%QueueSize];
	return 1;
}

int QueueEmpty(SqQueue qu)		/*判断队空运算*/
{
	if (qu.rear==qu.front)		/*队空*/
		return 1;
	else
		return 0;
}

void main()
{
	SqQueue qu;
	ElemType e;
	InitQueue(qu);
	printf("队%s\n",(QueueEmpty(qu)==1?"空":"不空"));
	printf("a进队\n");EnQueue(qu,'a');
	printf("b进队\n");EnQueue(qu,'b');
	printf("c进队\n");EnQueue(qu,'c');
	printf("d进队\n");EnQueue(qu,'d');
	printf("队%s\n",(QueueEmpty(qu)==1?"空":"不空"));
	GetHead(qu,e);
	printf("队头元素:%c\n",e);
	printf("出队次序:");
	while (!QueueEmpty(qu))
	{
		DeQueue(qu,e);
		printf("%c ",e);
	}
	printf("\n");
}
