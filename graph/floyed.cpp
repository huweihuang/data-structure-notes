#include <stdio.h>
#define MAXVEX 100
#define INF 32767
void Floyed(int cost[][MAXVEX],int n)
{
	int A[MAXVEX][MAXVEX],path[MAXVEX][MAXVEX];
	int i,j,k,pre;
	for (i=0;i<n;i++)		/*置初值*/
		for (j=0;j<n;j++) 
		{	
			A[i][j]=cost[i][j];
			path[i][j]=-1;
		}
	for (k=0;k<n;k++)
	{	
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (A[i][j]>(A[i][k]+A[k][j])) 
				{	
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
	}
	printf("\n Floyed算法求解如下:\n"); 
	for (i=0;i<n;i++)		/*输出最短路径*/
		for (j=0;j<n;j++) 
			if (i!=j)
			{	
				printf("   %d->%d:",i,j);
				if (A[i][j]==INF)
				{	
					if (i!=j) 
						printf("不存在路径\n");
				}
				else 
				{	
					printf("路径长度为:%3d ",A[i][j]);
					printf("路径为%d ",i);
					pre=path[i][j];
					while (pre!=-1)
					{	
						printf("%d ",pre);
						pre=path[pre][j];
					}
					printf("%d\n",j);
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
	Floyed(cost,6);
	printf("\n");
}
