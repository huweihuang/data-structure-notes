# 单链表的基本运算

## 单链表的定义

```c
#include <stdio.h>
#include <malloc.h>

typedef char ElemType;

typedef struct node 
{ 	
	ElemType data;		/*数据域*/
	struct node *next; 	/*指针域*/
} SLink;
```

## 初始化单链表
```c
void InitList(SLink *&L) 	/*L作为引用型参数*/
{
    L=(SLink *)malloc(sizeof(SLink));  /*创建头结点*L*/
    L->next=NULL;
}
```

## 求线性表的长度
```c
int GetLength(SLink *L)	/*求线性表的长度*/
{
    int i=0;
    SLink *p=L->next;
    while (p!=NULL) 
	{
		i++;
		p=p->next;
    }
    return i;
}
```

## 求线性表中第i个元素
```c
int GetElem(SLink *L,int i,ElemType &e)	/*求线性表中第i个元素*/
{
    int j=1;
    SLink *p=L->next;  
    if (i<1 || i>GetLength(L)) 
        return(0);    			/*i参数不正确,返回0*/
	while (j<i)      			/*从第1个结点开始找,查找第i个结点*/
    { 
		p=p->next;j++;
    }
	e=p->data;
    return(1);          		/*返回1*/
}
```

## 按值查找

```c
int Locate(SLink *L,ElemType x)	/*按值查找*/
{
	int i=1;
	SLink *p=L->next;
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
```

## 插入结点
```c
int InsElem(SLink *L,ElemType x,int i)	/*插入结点*/
{
    int j=1;
    SLink *p=L,*s;
    s=(SLink *)malloc(sizeof(SLink));	/*创建data域为x的结点*/
    s->data=x;s->next=NULL;
    if (i<1 || i>GetLength(L)+1) 
	return 0;    		/*i参数不正确,插入失败,返回0*/
	while (j<i)  		/*从头结点开始找,查找第i-1个结点,由p指向它*/
	{  
		p=p->next;j++;
    }
    s->next=p->next; 	/*将*s的next域指向*p的下一个结点(即第i个结点)*/
	p->next=s;        	/*将*p的next域指向*s,这样*s变成第i个结点*/
	return 1;           /*插入运算成功,返回1*/
}
```

## 删除结点
```c
int DelElem(SLink *L,int i)	/*删除结点*/
{
    int j=1;
    SLink *p=L,*q;
    if (i<1 || i>GetLength(L)) 
    	return 0;   	/*i参数不正确,插入失败,返回0*/
    while (j<i)    		/*从头结点开始,查找第i-1个结点,由p指向它*/
	{
		p=p->next;j++;
    }
    q=p->next;      	/*由q指向第i个结点*/
	p->next=q->next;	/*将*p的next指向*q之后结点,即从链表中删除第i个结点*/
    free(q);        		/*释放第i个结点占用的空间*/
    return 1;        	/*删除运算成功,返回1*/
}
```

## 输出单链表
```c
void DispList(SLink *L)	/*输出单链表*/
{
    SLink *p=L->next;
    while (p!=NULL) 
	{
		printf("%c ",p->data);
		p=p->next;
    }
    printf("\n");
}
```

## main
```c
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
