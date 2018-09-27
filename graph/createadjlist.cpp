#include <stdio.h>
#include <malloc.h>
#define MAXVEX 100

typedef char VertexType[3];

typedef struct edgenode
{	
	int adjvex;      			/*邻接点序号*/
	int value;  				/*边的权值*/
	struct edgenode *next;		/*下一条边的顶点*/
} ArcNode;						/*每个顶点建立的单链表中结点的类型*/

typedef struct vexnode
{
	VertexType data;       		/*结点信息*/
	ArcNode *firstarc; 			/*指向第一条边结点*/
} VHeadNode;					/*单链表的头结点类型*/

typedef struct 
{
	int n,e;					/*n为实际顶点数,e为实际边数*/
	VHeadNode adjlist[MAXVEX];	/*单链表头结点数组*/
} AdjList; 						/*图的邻接表类型*/

int CreateAdjList(AdjList *&G)	/*建立有向图的邻接表*/
{
	int i,b,t,w;
	ArcNode *p;
	G=(AdjList *)malloc(sizeof(AdjList));
	printf("顶点数(n),边数(e):");
	scanf("%d%d",&G->n,&G->e);
	for (i=0;i<G->n;i++)
	{	
		printf("   序号为%d的顶点信息:", i);
		scanf("%s",G->adjlist[i].data);
		G->adjlist[i].firstarc=NULL;
	}
	for (i=0;i<G->e;i++)
	{
		printf("   序号为边=>",i);
		printf(" 起点号 终点号 权值:");
		scanf("%d%d%d",&b,&t,&w);
		if (b<G->n && t<G->n && w>0)
		{
			p=(ArcNode *)malloc(sizeof(ArcNode));	/*建立*p结点*/
			p->value=w;p->adjvex=t;
			p->next=G->adjlist[b].firstarc;	 /**p插入到adjlist[b]的单链表之首*/
			G->adjlist[b].firstarc=p;
		}
		else
		{
			printf("输入错误!\n");
			return(0);		
		}
	}
	return(1);
}

void DispAdjList(AdjList *G)
{
	int i;
	ArcNode *p;
	printf("图的邻接表表示如下:\n");
	for (i=0;i<G->n;i++)
	{	
		printf("  [%d,%3s]=>",i,G->adjlist[i].data);
		p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	
			printf("(%d,%d)->",p->adjvex,p->value);
			p=p->next;
		}
		printf("∧\n");
	}
}

void main()
{
	AdjList *G;
	CreateAdjList(G);
	DispAdjList(G);
}
