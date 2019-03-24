# 顺序表求解约瑟夫问题

```c
#include <stdio.h>
#define MaxSize 50

void jose(int n,int m)
{
	int mon[MaxSize];			/*存放n个猴子的编号*/
	int i,d,count;
	for (i=0;i<n;i++)			/*设置猴子的编号*/
		mon[i]=i+1;
	printf("出队前:");			/*输出出列前的编号*/
	for (i=0;i<n;i++) 
		printf("%d ",mon[i]);
	printf("\n");
	printf("出队后:");
	count=0;					/*记录退出圈外的猴子个数*/
	i=-1;						/*从0号位置的猴子开始计数*/
	while (count<n)
	{
		d=0;
		while (d<m)				/*累计m个猴子*/
		{
			i=(i+1)%n;
			if (mon[i]!=0)
				d++;
		}
		printf("%d ",mon[i]);	/*猴子出列*/
		mon[i]=0;
		count++;				/*出列数增1*/
	}
	printf("\n");
}

void main()
{
	int m,n;
	printf("输入猴子个数n,m:");
	scanf("%d%d",&n,&m);
	jose(n,m);
}
```
