# 图的基本概念

## 图的定义

图是一种非线性结构，其中的元素是多对多的关系。

图是由非空的顶点的集合和描述顶点关系即边的集合组成。

## 图的特征

## 图的基本术语

- 有向图：边是有方向的图
- 无向图：边是无方向的图

## 图的存储结构

### 图的连接矩阵

```c
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
```

### 图的连接表

```c
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
```

## 图的遍历

### 广度优先搜索

### 深度优先搜索

