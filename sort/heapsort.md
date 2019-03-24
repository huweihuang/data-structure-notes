# 堆排序

```c
#include <stdio.h>
#define MaxSize 100

typedef int KeyType;		/*关键字类型*/

typedef char ElemType[10];	/*其他数据项类型*/

typedef struct 
{	
	KeyType key;   			/*关键字域*/
	ElemType data; 			/*其他数据域*/
} LineList;					/*线性表元素类型*/

void Sift(LineList R[],int low,int high)
{
	int i=low,j=2*i;     		/*R[j]是R[i]的左孩子*/
	LineList tmp=R[i];
	while (j<=high) 
	{	if (j<high && R[j].key<R[j+1].key) 	/*若右孩子较大,把j指向右孩子*/
			j++;    				/*j变为2i+1,指向右孩子结点*/
		if (tmp.key<R[j].key) 
		{	R[i]=R[j];           /*将R[j]调整到双亲结点位置上*/
			i=j;                  /*修改i和j值,以便继续向下筛选*/
			j=2*i;
		}
		else break;              /*筛选结束*/
	}
	R[i]=tmp;                     /*被筛选结点的值放入最终位置*/
}

void HeapSort(LineList R[],int n)
{
	int i;
	LineList tmp;
	for (i=n/2;i>=1;i--)  	/*循环建立初始堆*/
		Sift(R,i,n); 
	for (i=n;i>=2;i--)   	/*进行n-1次循环,完成堆排序*/
	{  	tmp=R[1];        	/*将第一个元素同当前区间内R[1]对换*/
		R[1]=R[i];
		R[i]=tmp;
		Sift(R,1,i-1);     	/*筛选R[1]结点,得到i-1个结点的堆*/
	}
}

void main()
{
	LineList R[MaxSize];
	KeyType a[]={0,75,87,68,92,88,61,77,96,80,72};	/*有效数据从a[1]开始*/
	int n=10,i;
	for (i=0;i<=n;i++)
		R[i].key=a[i];
	printf("排序前:");
	for (i=1;i<=n;i++)
		printf("%3d",R[i].key);
	printf("\n");
	HeapSort(R,n);
	printf("排序后:");
	for (i=1;i<=n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
```
