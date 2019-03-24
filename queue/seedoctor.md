# 看病排队问题

```c
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct QNode 
{
	char data[10];
	struct QNode *next;
} QType;		/*链队结点类型*/

typedef struct 
{
	QType *front,*rear;
} LinkQueue;	/*链队类型*/

void SeeDoctor()
{
	int sel,flag=1;
	LinkQueue *lq;
	QType *s;
	char name[10];
	lq=(LinkQueue *)malloc(sizeof(LinkQueue));
	lq->front=(QType *)malloc(sizeof(QType));
	lq->front->next=NULL;
	lq->rear=lq->front;
	while (flag==1) 	/*未下班时循环执行*/
	{
		printf("1:排队 2:看医生 3:查看排队 0:下班  请选择:");
		scanf("%d",&sel); 
		switch(sel) 
		{
		case 0:
			if (lq->front!=lq->rear) 	/*队不空*/
					printf("  >>请排队的患者明天就医\n");
			flag=0;
			break;
		case 1:
			printf("  >>输入患者姓名:");scanf("%s",name);
			s=(QType *)malloc(sizeof(QType));
			strcpy(s->data,name);s->next=NULL;
			lq->rear->next=s;lq->rear=s;
			break;
       	case 2:	
			if (lq->front==lq->rear)	/*队空*/
				printf("  >>没有排队的患者\n");
			else 
			{
				s=lq->front->next;
				if (lq->rear==s)
					lq->rear=lq->front;
				printf("  >>患者%s看医生\n",s->data);
				lq->front->next=s->next;
				free(s);
			}
			break;
       	case 3:
			if (lq->front==lq->rear)	/*队空*/
				printf("  >>没有排列的患者\n");
			else 
			{	
				s=lq->front->next;
				printf("  >>排队患者:");
				while (s!=NULL) 
				{  	
					printf("%s ",s->data);
					s=s->next;
				}
				printf("\n");
			}
			break;
		}
	}
}

void main()
{
	SeeDoctor();
}
```
