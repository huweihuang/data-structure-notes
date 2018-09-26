#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct QNode 
{
	ElemType data;
	struct QNode *next;
} QType;				/*链队中结点的类型*/
typedef struct qptr    	
{
	QType *front,*rear;
} LinkQueue;			/*链队类型*/
void InitQueue(LinkQueue *&lq)			/*lq为引用型参数*/
{    
	lq=(LinkQueue *)malloc(sizeof(LinkQueue));
    lq->rear=lq->front=NULL;     		/*初始情况*/
}
void EnQueue(LinkQueue *&lq,ElemType x)	/*入队运算,lq为引用型参数*/
{
	QType *s;
	s=(QType *)malloc(sizeof(QType));  	/*创建新结点，插入到链队的末尾*/
	s->data=x;s->next=NULL;
	if (lq->front==NULL && lq->rear==NULL) 	/*空队*/
		lq->rear=lq->front=s;
	else 
	{
		lq->rear->next=s;
		lq->rear=s;
	}
}
int DeQueue(LinkQueue *&lq,ElemType &x) 	/*出队运算,lq和x均为引用型参数*/
{
	QType *p;
	if (lq->front==NULL && lq->rear==NULL)  /*空队*/
		return 0;
	p=lq->front;
	x=p->data;
	if (lq->rear==lq->front)  /*若原队列中只有一个结点,删除后队列变空*/
		lq->rear=lq->front=NULL;
	else
		lq->front=lq->front->next;
	free(p);
	return 1;
}
int GetHead(LinkQueue *lq,ElemType &x) 	/*取队头元素运算,x为引用型参数*/
{
	if (lq->front==NULL && lq->rear==NULL)	/*队空*/
		return 0;
	x=lq->front->data;
	return 1;
}
int QueueEmpty(LinkQueue *lq)	/*判断队空运算*/
{
	if (lq->front==NULL && lq->rear==NULL)
		return 1;
	else
		return 0;
}

void main()
{
	LinkQueue *lq;
	ElemType e;
	InitQueue(lq);
	printf("队%s\n",(QueueEmpty(lq)==1?"空":"不空"));
	printf("a进队\n");EnQueue(lq,'a');
	printf("b进队\n");EnQueue(lq,'b');
	printf("c进队\n");EnQueue(lq,'c');
	printf("d进队\n");EnQueue(lq,'d');
	printf("队%s\n",(QueueEmpty(lq)==1?"空":"不空"));
	GetHead(lq,e);
	printf("队头元素:%c\n",e);
	printf("出队次序:");
	while (!QueueEmpty(lq))
	{
		DeQueue(lq,e);
		printf("%c ",e);
	}
	printf("\n");
}