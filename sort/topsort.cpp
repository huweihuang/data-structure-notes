#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXVEX 100

typedef char VertexType[3];		/*定义VertexType为char数组类型*/

typedef struct vertex
{
	int adjvex;
	VertexType data;
} VType;

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
	int count;             		/*存放顶点入度,新增用于拓扑排序*/
	ArcNode *firstarc; 			/*指向第一条边结点*/
} VHeadNode;					/*单链表的头结点类型*/

typedef struct 
{
	int n,e;					/*n为实际顶点数,e为实际边数*/
	VHeadNode adjlist[MAXVEX];	/*单链表头结点数组*/
} AdjList; 						/*图的邻接表类型*/

void DispAdjList(AdjList *G)	/*显示邻接表(含顶点入度)*/
{
	int i;
	ArcNode *p;
	printf("图的邻接表表示如下:\n");
	for (i=0;i<G->n;i++)
	{	
		printf("  [%d,%3s:]=>",i,G->adjlist[i].data,G->adjlist[i].count);
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

void TopSort(AdjList *G)
{
	int i,j;
	int St[MAXV],top=-1;  			/*栈St的指针为top*/
	ArcNode *p;
	for (i=0;i<n;i++)
		if (adj[i].count==0)   		/*入度为0的顶点入栈*/
		{
			top++; 
			St[top]=i;  
		}
		while (top>-1)             	/*栈不为空时循环*/
		{
			i=St[top];top--;  		/*出栈*/
			printf("%d ",i);      	/*输出顶点*/
			p=adj[i].firstarc;     	/*找第一个相邻顶点*/
			while (p!=NULL) 
			{
				j=p->adjvex;
				adj[j].count--; 
				if (adj[j].count==0)/*入度为0的相邻顶点入栈*/
				{
					top++;
					St[top]=j;
				}
				p=p->nextarc;        /*找下一个相邻顶点*/
			}
		}
}

void main()
{
	int i,j;
	AdjMatix g;
	AdjList *G;
	int a[6][6]={{0,1,0,10},{1,0,1,0,0},{0,1,0,1,1},{1,0,1,0,1},{0,0,1,1,0}};
	char *vname[MAXVEX]={"a","b","c","d","e"};
	g.n=5;g.e=12;	/*建立图6.1(a)的无向图,每1条无向边算为2条有向边*/
	for (i=0;i<g.n;i++)
		strcpy(g.vexs[i].data,vname[i]);
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=a[i][j];
	MatToList(g,G);		/*生成邻接表*/
	DispAdjList(G);		/*输出邻接表*/
	for (i=0;i<g.n;i++)	visited[i]=0; /*顶点标识置初值*/
	printf("从顶点0的深度优先遍历序列:\n");
	printf("  递归算法:");DFS(G,0);printf("\n");
	for (i=0;i<g.n;i++)	visited[i]=0; /*顶点标识置初值*/
	printf("  非递归算法:");DFS1(G,0);printf("\n");
}

