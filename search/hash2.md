# 哈希查找

```c
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100		/*哈希表最大长度*/

typedef int KeyType;

typedef struct node
{
	KeyType key;	/*关键字值*/
	int si;			/*探查次数*/	
	struct node *next;
} Node;		/*数据结点类型*/

typedef struct
{
	Node *link;
} HNode;	/*头结点类型*/

void CreateHT(HNode *ht[],KeyType a[],int n,int p)	/*构造哈希表*/
{
	int i,d,cnt;
	Node *s,*q;
	for (i=0;i<p;i++)	/*所有头结点的link域置空*/
	{
		ht[i]=(HNode *)malloc(sizeof(HNode));
		ht[i]->link=NULL;
	}
	for (i=0;i<n;i++)
	{
		cnt=1;
		s=(Node *)malloc(sizeof(Node));	/*构造一个数据结点*/
		s->key=a[i];s->next=NULL;
		d=a[i]%p;						/*求其哈希地址*/
		if (ht[d]->link==NULL)			
		{
			ht[d]->link=s;
			s->si=cnt;
		}
		else
		{
			q=ht[d]->link;
			while (q->next!=NULL)
			{
				q=q->next;cnt++;
			}
			cnt++;
			s->si=cnt;q->next=s;
		}
	}
}

void DispHT(HNode *ht[],int n,int p)	/*输出哈希表*/
{
	int i,sum=0;
	Node *q;
	printf("哈希表:\n");
	for (i=0;i<p;i++)
	{
		q=ht[i]->link;
		printf("%d:link->",i);
		while (q!=NULL)
		{
			sum+=q->si;
			printf("[%d,%d]->",q->key,q->si);
			q=q->next;
		}
		printf("∧\n");
	}
	printf("\n平均查找长度:ASL=%g\n",1.0*sum/n);
}

void main()
{
	HNode *ht[MaxSize];
	KeyType a[]={87,25,310,8,27,132,68,95,187,123,70,63,47};
	int n=13,p=13;
	CreateHT(ht,a,n,p);
	DispHT(ht,n,p);
}
```
