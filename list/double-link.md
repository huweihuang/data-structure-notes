# 双链表的基本运算

```c
#include <stdio.h>
#include <malloc.h>

typedef char ElemType;

typedef struct node
{	
	ElemType data;				/*数据域*/
	struct node *prior,*next;  /*分别指向前驱结点和后继结点的指针*/
} DLink;

void InitList(DLink *&L)
{
    L=(DLink *)malloc(sizeof(DLink));  /*创建头结点*L*/
    L->prior=L->next=NULL;
}

int GetLength(DLink *L)	/*求表长运算*/
{
    int i=0;
    DLink *p=L->next;
    while (p!=NULL) 
	{
		i++;p=p->next;
    }
    return i;
}

int GetElem(DLink *L,int i,ElemType &e)	/*求线性表中第i个元素*/
{
    int j=1;
    DLink *p=L->next;  
    if (i<1 || i>GetLength(L)) 
        return(0);    			/*i参数不正确,返回0*/
	while (j<i)      			/*从第1个结点开始,查找第i个结点*/
    { 
		p=p->next;j++;
    }
	e=p->data;
    return(1);          		/*返回1*/
}

int Locate(DLink *L,ElemType x)	/*按值查找*/
{
	int i=1;
	DLink *p=L->next;
	while (p!=NULL && p->data!=x)  	/*从第1个结点开始查找data域为x的结点*/
	{
		p=p->next;
		i++;
	}
	if (p==NULL)
		return(0);
	else
		return(i);
}

int InsElem(DLink *L,ElemType x,int i)	/*插入运算*/
{
    int j=1;
    DLink *p=L,*s;
    s=(DLink *)malloc(sizeof(DLink));  	/*创建data域为x的结点*/
    s->data=x;s->prior=s->next=NULL;
    if (i<1 || i>GetLength(L)+1)		/*i参数不正确,插入失败,返回0*/
        return 0;
    while (j<i)          	/*找到第i-1个结点,由p指向它*/
	{
    		p=p->next;j++;
    }
    s->next=p->next;   		/**s的next域指向*p的下一个结点*/
    s->prior=p;         	/**s的prior域指向*p*/
    if (p->next!=NULL)  	/*若*p不是最后结点,则将*p之后结点的prior域指向*s*/
        s->next->prior=s;
     p->next=s;          	/**p的next域指向*s*/
    return 1;             	/*插入运算成功,返回1*/
}

int DelElem(DLink *L,int i)	/*删除运算*/
{
    int j=1;
    DLink *p=L,*q;
	if (i<1 || i>GetLength(L))	/*i参数不正确,删除失败,返回0*/
		return 0;
    while (j<i)        		/*找到第i-1个结点,由p指向它*/
	{
       	p=p->next;j++;
    }
    q=p->next;         		/*q指向*p的下一个结点,即要删除的结点*/
    p->next=q->next;
    if (q->next!=NULL)		/*若*q不是最后结点,则将*q之后结点的prior域指向*p*/
        q->next->prior=p;
    free(q);            		/*释放第i个结点占用的空间*/
    return 1;           		/*删除运算成功,返回1*/
}

void DispList(DLink *L)	/*输出线性表*/
{
    DLink *p=L->next;
    while (p!=NULL) 
	{
        printf("%c ",p->data);p=p->next;
    }
    printf("\n");
}

void main()
{
	int i;
	ElemType e;
	DLink *L;
	InitList(L);		/*初始化双链表L*/
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
