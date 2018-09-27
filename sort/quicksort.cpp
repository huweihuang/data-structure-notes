#include <stdio.h>
#define MaxSize 100

typedef int KeyType;		/*关键字类型*/

typedef char ElemType[10];	/*其他数据项类型*/

typedef struct 
{	
	KeyType key;   			/*关键字域*/
	ElemType data; 			/*其他数据域*/
} LineList;					/*线性表元素类型*/

void QuickSort(LineList R[],int s,int t) /*对R[s]至R[t]的元素进行快速排序*/
{
	int i=s,j=t;
	LineList tmp;
	if (s<t) 				/*区间内至少存在一个元素的情况*/
	{	tmp=R[s];     		/*用区间的第1个记录作为基准*/
		while (i!=j)  		/*从区间两端交替向中间扫描,直至i=j为止*/
		{	while (j>i && R[j].key>tmp.key) 
				j--;  		/*从右向左扫描,找第1个关键字小于tmp.key的R[j]*/ 
			R[i]=R[j];		/*找到这样的R[j],则R[i]和R[j]交换*/
			while (i<j && R[i].key<tmp.key) 
				i++;		/*从左向右扫描,找第1个关键字大于tmp.key的R[i]*/
			R[j]=R[i];		/*找到这样的R[i],则R[i]和R[j]交换*/
		}
		R[i]=tmp;
		QuickSort(R,s,i-1);	/*对左区间递归排序*/
		QuickSort(R,i+1,t);	/*对右区间递归排序*/
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
	QuickSort(R,0,n-1);
	printf("排序后:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
