# 有向图连接链表

## By C++

```c
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
```

## By Golang

```go
// Package graph creates a ItemGraph data structure for the Item type
package graph

import (
	"fmt"
	"sync"
)

// Item the type of the binary search tree
type Item interface{}

// Node a single node that composes the tree
type Node struct {
	value Item
}

func (n *Node) String() string {
	return fmt.Sprintf("%v", n.value)
}

// ItemGraph the Items graph
type ItemGraph struct {
	nodes []*Node
	edges map[Node][]*Node
	lock  sync.RWMutex
}

// AddNode adds a node to the graph
func (g *ItemGraph) AddNode(n *Node) {
	g.lock.Lock()
	g.nodes = append(g.nodes, n)
	g.lock.Unlock()
}

// AddEdge adds an edge to the graph
func (g *ItemGraph) AddEdge(n1, n2 *Node) {
	g.lock.Lock()
	if g.edges == nil {
		g.edges = make(map[Node][]*Node)
	}
	g.edges[*n1] = append(g.edges[*n1], n2)
	g.edges[*n2] = append(g.edges[*n2], n1)
	g.lock.Unlock()
}

// AddEdge adds an edge to the graph
func (g *ItemGraph) String() {
	g.lock.RLock()
	s := ""
	for i := 0; i < len(g.nodes); i++ {
		s += g.nodes[i].String() + " -> "
		near := g.edges[*g.nodes[i]]
		for j := 0; j < len(near); j++ {
			s += near[j].String() + " "
		}
		s += "\n"
	}
	fmt.Println(s)
	g.lock.RUnlock()
}

// Traverse implements the BFS traversing algorithm
func (g *ItemGraph) Traverse(f func(*Node)) {
	g.lock.RLock()
	q := NodeQueue{}
	q.New()
	n := g.nodes[0]
	q.Enqueue(*n)
	visited := make(map[*Node]bool)
	for {
		if q.IsEmpty() {
			break
		}
		node := q.Dequeue()
		visited[node] = true
		near := g.edges[*node]

		for i := 0; i < len(near); i++ {
			j := near[i]
			if !visited[j] {
				q.Enqueue(*j)
				visited[j] = true
			}
		}
		if f != nil {
			f(node)
		}
	}
	g.lock.RUnlock()
}
```
