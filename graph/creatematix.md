# 有向图连接矩阵

```c
#include <stdio.h>
#define MAXVEX  100

typedef char VertexType[3];		/*定义VertexType为char数组类型*/

typedef struct vertex
{	
	int adjvex;     			/*顶点编号*/
	VertexType data; 			/*顶点的信息*/
} VType;						/*顶点类型*/

typedef struct graph
{
	int n,e;					/*n为实际顶点数,e为实际边数*/
	VType vexs[MAXVEX];			/*顶点集合*/
	int edges[MAXVEX][MAXVEX];	/*边的集合*/
} AdjMatix;						/*图的邻接矩阵类型*/

int CreateMatix(AdjMatix &g)
{
	int i,j,k,b,t;
	int w;
	printf("顶点数(n)和边数(e):");
	scanf("%d%d",&g.n,&g.e);
	for (i=0;i<g.n;i++)
	{	
		printf("   序号为%d的顶点信息:",i);
		scanf("%s",g.vexs[i].data);
		g.vexs[i].adjvex=i;		/*顶点编号为i*/
	}
    for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=0;
	for (k=0;k<g.e;k++)
	{
		printf("   序号为%d的边=>",k);
		printf("  起点号 终点号 权值:");
		scanf("%d%d%d",&b,&t,&w);
		if (b<g.n && t<g.n && w>0)
			g.edges[b][t]=w;
		else
		{
			printf("输入错误!\n");
			return(0);		
		}
	}
	return(1);
}

void DispMatix(AdjMatix g)
{
	int i,j;
	printf("\n图的邻接矩阵:\n");
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}

void main()
{
	AdjMatix g;
	CreateMatix(g);
	DispMatix(g);
}
```
