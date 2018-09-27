#include <stdio.h>
#define MaxSize 100

typedef int KeyType;		/*关键字类型*/

typedef char ElemType[10];	/*其他数据项类型*/

typedef struct 
{	
	KeyType key;   			/*关键字域*/
	ElemType data; 			/*其他数据域*/
} LineList;					/*线性表元素类型*/

void BubbleSort(LineList R[],int n)
{
	int i,j,exchange;
	LineList tmp;
	for (i=0;i<n-1;i++) 
	{	exchange=0;
		for (j=n-1;j>i;j--)	/*比较,找出最小关键字的记录*/
			if (R[j].key<R[j-1].key)   	
			{	tmp=R[j];  /*R[j]与R[j-1]进行交换,将最小关键字记录前移*/
				R[j]=R[j-1];
				R[j-1]=tmp;
				exchange=1;
			}
		if (exchange==0) 	/*本趟未发生交换时结束算法*/
			return;
	}
}

void main()
{
	LineList R[MaxSize];
	KeyType a[]={75,87,68,92,88,61,77,96,80,72};
	int n=10,i;
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("排序前:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
	BubbleSort(R,n);
	printf("排序后:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
