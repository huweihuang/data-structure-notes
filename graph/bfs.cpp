#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAXVEX 100

typedef char VertexType[3];		/*定义VertexType为char数组类型*/
typedef struct vertex
{	
	int adjvex;     				/*顶点编号*/
	VertexType data; 			/*顶点的信息*/
} VType;						/*顶点类型*/
typedef struct graph
{	
	int n,e;					/*n为实际顶点数,e为实际边数*/
	VType vexs[MAXVEX];			/*顶点集合*/
	int edges[MAXVEX][MAXVEX];	/*边的集合*/
} AdjMatix;						/*图的邻接矩阵类型*/

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
void MatToList(AdjMatix g,AdjList *&G)  /*例6.3算法:将邻接矩阵g转换成邻接表G*/
{
	int i,j;
	ArcNode *p;
	G=(AdjList *)malloc(sizeof(AdjList));
	for (i=0;i<g.n;i++)					/*给邻接表中所有头结点的指针域置初值*/
	{	
		G->adjlist[i].firstarc=NULL;
		strcpy(G->adjlist[i].data,g.vexs[i].data);
	}
	for (i=0;i<g.n;i++)					/*检查邻接矩阵中每个元素*/
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0)		/*邻接矩阵的当前元素不为0*/
			{
				p=(ArcNode *)malloc(sizeof(ArcNode));/*创建一个结点*p*/
				p->value=g.edges[i][j];p->adjvex=j;
				p->next=G->adjlist[i].firstarc;		  /*将*p链到链表后*/
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}
void BFS(AdjList *G,int vi)		/*对邻接表g从顶点vi开始进行广宽优先遍历*/
{
	int i,v,visited[MAXVEX];
	int Qu[MAXVEX],front=0,rear=0;		/*循环队列*/
	ArcNode *p;
	for (i=0;i<G->n;i++)				/*给visited数组置初值0*/
		visited[i]=0;
	printf("%d ",vi);					/*访问初始顶点*/
	visited[vi]=1;						/*置已访问标识*/
	rear=(rear=1)%MAXVEX;				/*循环移动队尾指针*/
	Qu[rear]=vi;						/*初始顶点进队*/
	while (front!=rear)					/*队列不为空时循环*/
	{	
		front=(front+1) % MAXVEX;
		v=Qu[front];					/*顶点v出队*/
		p=G->adjlist[v].firstarc;		/*找v的第一个邻接点*/
		while (p!=NULL)					/*找v的所有邻接点*/
		{	
			if (visited[p->adjvex]==0)	/*未访问过则访问之*/
			{
				visited[p->adjvex]=1;	/*置已访问标识*/
				printf("%d ",p->adjvex);/*访问该点并使之入队列*/
				rear=(rear+1) % MAXVEX;	/*循环移动队尾指针*/
				Qu[rear]=p->adjvex;		/*顶点p->adjvex进队*/
			}
			p=p->next;					/*找v的下一个邻接点*/
		}
	}
}
void main()
{
	int i,j;
	AdjMatix g;
	AdjList *G;
	int a[5][5]={{0,1,0,1,0},{1,0,1,0,0},{0,1,0,1,1},{1,0,1,0,1},{0,0,1,1,0}};
	char *vname[MAXVEX]={"a","b","c","d","e"};
	g.n=5;g.e=12;	/*建立图6.1(a)的无向图,每1条无向边算为2条有向边*/
	for (i=0;i<g.n;i++)
		strcpy(g.vexs[i].data,vname[i]);
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=a[i][j];
	MatToList(g,G);		/*生成邻接表*/
	DispAdjList(G);		/*输出邻接表*/
	printf("从顶点0的广度优先遍历序列:\n");
	printf("\t");BFS(G,0);printf("\n");
}

