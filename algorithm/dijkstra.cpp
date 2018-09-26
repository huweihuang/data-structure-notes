#include <stdio.h>
#define MAXVEX 100
#define INF 32767
void Dijkstra(int cost[][MAXVEX],int n,int v)
{
	int dist[MAXVEX],path[MAXVEX];
	int s[MAXVEX];
	int mindis,i,j,u,pre;
	for (i=0;i<n;i++) 
	{	
		dist[i]=cost[v][i];   		/*距离初始化*/
		s[i]=0;                		/*s[]置空*/
		if (cost[v][i]<INF)			/*路径初始化*/
			path[i]=v;
		else
		    path[i]=-1;
	}
	s[v]=1;path[v]=0;        		/*源点编号v放入s中*/
	for (i=0;i<n;i++)     			/*循环直到所有顶点的最短路径都求出*/
	{	
		mindis=INF;
		u=-1;
		for (j=0;j<n;j++)     		/*选取不在s中且具有最小距离的顶点u*/
			if (s[j]==0 && dist[j]<mindis) 
			{ 	
				u=j;
				mindis=dist[j];	
			}
		if (u!=-1)						/*找到最小距离的顶点u*/
		{	s[u]=1; 					/*顶点u加入s中*/
			for (j=0;j<n;j++)      		/*修改不在s中的顶点的距离*/
				if (s[j]==0) 
					if (cost[u][j]<INF && dist[u]+cost[u][j]<dist[j]) 
					{	
						dist[j]=dist[u]+cost[u][j];
						path[j]=u;
					} 
		}
	}
	printf("\n Dijkstra算法求解如下:\n"); 
	for (i=0;i<n;i++)				/*输出最短路径长度,路径逆序输出*/
	{
		if (i!=v)
		{	
			printf("  %d->%d:",v,i);
			if (s[i]==1)  
			{	
				printf("路径长度为%2d ",dist[i]);
				pre=i;
				printf("路径逆序为");
				while (pre!=v)		/*一直求解到初始顶点*/
				{	
					printf("%d,",pre);
					pre=path[pre];
				}
				printf("%d\n",pre);
			}
			else
				printf("不存在路径\n");
		}
	}
}
void main()
{
	int cost[6][MAXVEX]={		/*图6.9的代价矩阵*/
		{0,50,10,INF,INF,INF},
		{INF,0,15,50,10,INF},
		{20,INF,0,15,INF,INF},
		{INF,20,INF,0,35,INF},
		{INF,INF,INF,30,0,INF},
		{INF,INF,INF,3,INF,0}};
	Dijkstra(cost,6,1);
	printf("\n");
}
