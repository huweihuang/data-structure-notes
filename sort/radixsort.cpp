#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXE 20			/*线性表中最多元素个数*/
#define MAXR 10			/*基数的最大取值*/
#define MAXD 8			/*关键字位数的最大取值*/

typedef struct node
{	
	char data[MAXD];	/*记录的关键字定义的字符串*/
   	struct node *next;
} RecType;

void RadixSort(RecType *&p,int r,int d) 
/*p为待排序序列链表指针,r为基数,d为关键字位数*/
{
	RecType *head[MAXR],*tail[MAXR],*t;/*定义各链队的首尾指针*/
	int i,j,k;
	for (i=d-1;i>=0;i--)           		/*从低位到高位做d趟排序*/
	{	for (j=0;j<r;j++) 				/*初始化各链队首、尾指针*/
			head[j]=tail[j]=NULL;
		while (p!=NULL)          		/*对于原链表中每个结点循环*/
		{	k=p->data[i]-'0';   		/*找第k个链队*/
			if (head[k]==NULL)   		/*进行分配,即采用尾插法建立单链表*/
			{	
				head[k]=p;
				tail[k]=p;
			}
          	else
			{  	
				tail[k]->next=p;
				tail[k]=p;
			}
			p=p->next;             		/*取下一个待排序的元素*/
		}
		p=NULL;
       	for (j=0;j<r;j++)        		/*对于每一个链队循环*/
			if (head[j]!=NULL)         	/*进行收集*/
			{	if (p==NULL)
				{	p=head[j];
					t=tail[j];
				}
				else
				{	t->next=head[j];
					t=tail[j];
				}
			}
		t->next=NULL;					/*最后一个结点的next域置NULL*/
	}
}

void main()
{
	RecType *h=NULL,*p,*t;
	char *A[]={"75","87","68","92","88","61","77","96","80","72"};
	int i,n=10;
	for (i=0;i<n;i++)		/*构造不带头结点的单链表h*/
	{	
		p=(RecType *)malloc(sizeof(RecType));
		strcpy(p->data,A[i]);
		if (h==NULL)
		{	
			h=p;
			t=h;
		}
		else
		{	
			t->next=p;
			t=p;
		}
	}
	t->next=NULL;
	printf("排序前:");
	for (i=0;i<n;i++)
		printf("%3s",A[i]);
	printf("\n");
	RadixSort(h,10,2);
	printf("排序后:");
	p=h;
	while (p!=NULL)
	{	
		printf("%3s",p->data);
		p=p->next;
	}
	printf("\n");
}
