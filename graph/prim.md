# 普里姆算法

```c
#include <stdio.h>
#define MAXVEX 100
#define INF 32767       /*INF表示∞*/

void Prim(int cost[][MAXVEX],int n,int v)
/*输出最小生成树的每条边*/
{
	int lowcost[MAXVEX],min;
	int closest[MAXVEX],i,j,k;
	for (i=0;i<n;i++)          	/*给lowcost[]和closest[]置初值*/
	{	
		lowcost[i]=cost[v][i];
	    	closest[i]=v;
	}
	for (i=1;i<n;i++)          	/*找出n-1个顶点*/
	{   
		min=INF;
		for (j=0;j<n;j++)       /*在(V-U)中找出离U最近的顶点k*/
			if (lowcost[j]!=0 && lowcost[j]<min) 
			{	
				min=lowcost[j];
				k=j;  
			}
		printf("  边(%d,%d)权为:%d\n",closest[k],k,min);
		lowcost[k]=0;         	/*标记k已经加入U*/
		for (j=0;j<n;j++)   	/*修改数组lowcost和closest*/
			if (cost[k][j]!=0 && cost[k][j]<lowcost[j]) 
			{	
				lowcost[j]=cost[k][j];
				closest[j]=k; 
			}
	}
}

void main()
{
	int n=7;
	int cost[7][MAXVEX]={
		{0,50,60,INF,INF,INF,INF},
		{50,0,INF,65,40,INF,INF},
		{60,INF,0,52,INF,INF,45},
		{INF,65,52,0,50,30,42},
		{INF,40,INF,50,0,70,INF},
		{INF,INF,INF,30,70,0,INF},
		{INF,INF,45,42,INF,INF,0}};
	printf("最小生成树:\n");Prim(cost,n,0);
}
```
