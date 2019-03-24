# 两个多项式相加运算

```c
#include <stdio.h>
#include <malloc.h>

typedef struct node
{  	float coef;    		/*序数*/
   	int expn;      		/*指数*/
   	struct node *next;	/*指向下一个结点的指针*/
} PolyNode;

void InitList(PolyNode *&L)		/*初始化多项式单链表*/
{
    L=(PolyNode *)malloc(sizeof(PolyNode));	/*建立头结点*/
    L->next=NULL;
}

int GetLength(PolyNode *L)		/*求多项式单链表的长度*/
{
    int i=0;
    PolyNode *p=L->next;
    while (p!=NULL)		/*扫描单链表L,用i累计数据结点个数*/
	{
        i++;p=p->next;
    }
    return i;
}

PolyNode *GetElem(PolyNode *L,int i)	/*返回多项式单链表中第i个结点的指针*/
{
    int j=1;
    PolyNode *p=L->next;
    if (i<1 || i>GetLength(L)) 
       	return NULL;
    while (j<i)				/*沿next域找第i个结点*/
	{
       	p=p->next;j++;
    }
    return p;
}

PolyNode *Locate(PolyNode *L,float c,int e)	/*在多项式单链表中按值查找*/
{
    PolyNode *p=L->next;
    while (p!=NULL && (p->coef!=c ||p->expn!=e))
        	p=p->next;
    return p;
}

int InsElem(PolyNode *&L,float c,int e,int i)  /*在多项式单链表中插入一个结点*/
{
    int j=1;
    PolyNode *p=L,*s;
    s=(PolyNode *)malloc(sizeof(PolyNode));
    s->coef=c;s->expn=e;s->next=NULL;
    if (i<1 || i>GetLength(L)+1) 
        return 0;
    while (j<i)		/*查找第i-1个结点*p*/
	{
		p=p->next;j++;
    }
    s->next=p->next;
    p->next=s;
    return 1;
}

int DelElem(PolyNode *L,int i)		/*在多项式单链表中删除一个结点*/
{
    int j=1;
    PolyNode *p=L,*q;
	if (i<1 || i>GetLength(L)) 
		return 0;
    while (j<i)		/*在单链表中查找第i-1个结点*p*/
	{
		p=p->next;j++;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}

void DispList(PolyNode *L)		/*输出多项式单链表的元素值*/
{
	PolyNode *p=L->next;
    while (p!=NULL)
	{
        printf("(%g,%d) ",p->coef,p->expn);
        p=p->next;
    }
    printf("\n");
}
void CreaPolyList(PolyNode *&L,float C[],int E[],int n)
{
    int i;
    InitList(L);
    for (i=0;i<n;i++)
        InsElem(L,C[i],E[i],i+1);
}

void SortPloy(PolyNode *&L)	/*对L的多项式单链表按expn域递增排序*/
{
	PolyNode *p=L->next,*q,*pre;
	L->next=NULL;
	while (p!=NULL) 
	{
		if (L->next==NULL)     				/*处理第1个结点*/
		{
			L->next=p;p=p->next;
			L->next->next=NULL;
       	}
		else      							/*处理其余结点*/
		{
			pre=L;q=pre->next;
			while (q!=NULL && p->expn>q->expn) 	/*找q->expn刚大于或等于p->expn的结点*q的前驱结点*pre*/
			{
				pre=q;q=q->next;
			}
			q=p->next;              		/*在*pre结点之后插入*p*/
			p->next=pre->next;
			pre->next=p;
			p=q;
		}	
	}
}

PolyNode *AddPoly(PolyNode *pa,PolyNode *pb)
{
	PolyNode *pc,*p1=pa->next,*p2=pb->next,*p,*tc,*s;
	pc=(PolyNode *)malloc(sizeof(PolyNode));	/*新建头结点*/
	pc->next=NULL;					/*pc为新建单链表的头结点*/
	tc=pc;							/*tc始终指向新建单链表的最后结点*/
	while (p1!=NULL && p2!=NULL) 
	{
		if (p1->expn<p2->expn)		/*将*p1结点复制到*s并链到pc尾*/
		{
			s=(PolyNode *)malloc(sizeof(PolyNode));
			s->coef=p1->coef;s->expn=p1->expn;s->next=NULL;
			tc->next=s;tc=s;
			p1=p1->next;
		}
		else if (p1->expn>p2->expn)	/*将*p2结点复制到*s并链到pc尾*/
		{
			s=(PolyNode *)malloc(sizeof(PolyNode));
			s->coef=p2->coef;s->expn=p2->expn;s->next=NULL;
			tc->next=s;tc=s;
			p2=p2->next;
		}
		else   /*p1->expn=p2->expn的情况*/
		{
			if (p1->coef+p2->coef!=0) /*序数相加不为0时新建结点*s并链到pc尾*/
			{
				s=(PolyNode *)malloc(sizeof(PolyNode));
				s->coef=p1->coef+p2->coef;s->expn=p1->expn;
				s->next=NULL;
				tc->next=s;tc=s;
			}
			p1=p1->next;p2=p2->next;
		}
	}
	if (p1!=NULL) p=p1;  /*将尚未扫描完的余下结点复制并链接到pc单链表之后*/
	else p=p2;
	while (p!=NULL) 
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));
		s->coef=p->coef;s->expn=p->expn;s->next=NULL;
		tc->next=s;tc=s;
		p=p->next;
	}
	tc->next=NULL;		/*新建单链表最后结点的next域置空*/
	return pc;
}

void main()
{
	PolyNode *L1,*L2,*L3;
	float C1[]={3,7,5,9},C2[]={-9,8,22};
	int E1[]={1,0,17,8},E2[]={8,1,7};
	InitList(L1);
	InitList(L2);
	InitList(L3);
	CreaPolyList(L1,C1,E1,4);
	CreaPolyList(L2,C2,E2,3);
	printf("两多项式相加运算\n");
	printf("     原多项式A:");DispList(L1);
	printf("     原多项式B:");DispList(L2);
	SortPloy(L1);
	SortPloy(L2);
	printf("排序后的多项式A:");DispList(L1);
	printf("排序后的多项式B:");DispList(L2);
	L3=AddPoly(L1,L2);
	printf("多项式相加结果:");DispList(L3);
}
```
