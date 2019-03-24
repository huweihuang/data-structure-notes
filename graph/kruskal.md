# 克鲁斯卡尔算法

```c
#include <stdio.h>
#define MAXVEX 100

typedef struct 
{	
	int u;     /*边的起始顶点*/
	int v;     /*边的终止顶点*/
	int w;     /*边的权值*/
} Edge;

void Kruskal(Edge E[],int n,int e)
{
	int i,j,m1,m2,sn1,sn2,k;
	int vset[MAXVEX];
	for (i=0;i<n;i++) vset[i]=i;	/*初始化辅助数组*/
	k=1;                 			/*k表示构造最小生成树的第几条边,初值为1*/
	j=0;                 			/*E中边的下标,初值为0*/
	while (k<n)       				/*生成的边数小于n时循环*/
	{
		m1=E[j].u;m2=E[j].v;        /*取一条边的头尾顶点*/
		sn1=vset[m1];sn2=vset[m2]; 	/*分别得到两个顶点所属的集合编号*/
		if (sn1!=sn2)     	  		/*两顶点属不同的集合,该边是最小生成树的边*/
		{
			printf("  边(%d,%d)权为:%d\n",m1,m2,E[j].w);
			k++;                    /*生成边数增1*/
			for (i=0;i<n;i++)      	/*两个集合统一编号*/
				if (vset[i]==sn2)  	/*集合编号为sn2的改为sn1*/
				    vset[i]=sn1;
		}
		j++;   						/*扫描下一条边*/
	}
}

void main()
{
	int n=7,e=10;
	Edge E[]={
		{3,5,30},{1,4,40},{3,6,42},
		{2,6,45},{0,1,50},{3,4,50},
		{2,3,52},{0,2,60},{1,3,65},
		{4,5,70}};
	printf("最小生成树:\n");Kruskal(E,n,e);
}
```
