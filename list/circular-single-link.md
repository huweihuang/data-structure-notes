# 循环单链表的基本运算

```c
#include <stdio.h>
#include <malloc.h>

typedef char ElemType;

typedef struct node 
{ 	
	ElemType data;			/*数据域*/
	struct node *next; 		/*指针域*/
} SLink;

void InitList(SLink *&L)   	/*初始化线性表,L为引用型参数*/
{
    L=(SLink *)malloc(sizeof(SLink));
    L->next=L;
}

int GetLength(SLink *L)	/*求线性表的长度*/
{
    int i=0;
    SLink *p=L->next;
    while (p!=L) 
	{
		i++;p=p->next;
    }
    return i;
}

int GetElem(SLink *L,int i,ElemType &e)	/*求线性表中第i个元素*/
{
    int j=1;
    SLink *p=L->next;  
    if (i<1 || i>GetLength(L)) 
        return(0);    		/*i参数不正确,返回0*/
	while (j<i)      		/*从第1个结点开始,查找第i个结点*/
    { 	
		p=p->next;
		j++;
    }
	e=p->data;
    return(1);          	/*返回1*/
}

int Locate(SLink *L,ElemType x)	/*按值查找*/
{
	int i=1;
	SLink *p=L->next;
	while (p!=L && p->data!=x)  	/*从第1个结点开始查找data域为x的结点*/
	{	p=p->next;
		i++;
	}
	if (p==L)
		return(0);
	else
		return(i);
}

int InsElem(SLink *L,ElemType x,int i)	/*插入结点*/
{
    int j=1;
    SLink *p=L,*s;
    s=(SLink *)malloc(sizeof(SLink));
    s->data=x;s->next=NULL;
    if (i<1 || i>GetLength(L)+1) 
        return 0;
    while (j<i) 
	{
        p=p->next;j++;
    }
    s->next=p->next;
    p->next=s;
    return 1;
}

int DelElem(SLink *L,int i)	/*删除结点*/
{
    int j=1;
    SLink *p=L,*q;
    if (i<1 || i>GetLength(L)) 
        return 0;
    while (j<i) 
	{
        p=p->next;j++;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}

void DispList(SLink *L)	/*输出线性表*/
{
    SLink *p=L->next;
    while (p!=L) 
	{
        printf("%c ",p->data);p=p->next;
    }
    printf("\n");
}

void main()
{
	int i;
	ElemType e;
	SLink *L;
	InitList(L);		/*初始化单链表L*/
	InsElem(L,'a',1);	/*插入元素*/
	InsElem(L,'c',2);
	InsElem(L,'a',3);
	InsElem(L,'e',4);
	InsElem(L,'d',5);
	InsElem(L,'b',6);
	printf("线性表:");DispList(L);
	printf("长度:%d\n",GetLength(L));
	i=3;GetElem(L,i,e);
	printf("第%d个元素:%c\n",i,e);
	e='a';
	printf("元素%c是第%d个元素\n",e,Locate(L,e));
	i=4;printf("删除第%d个元素\n",i);
	DelElem(L,i);
	printf("线性表:");DispList(L);
}
```
