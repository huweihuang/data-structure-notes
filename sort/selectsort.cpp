#include <stdio.h>
#define MaxSize 100

typedef int KeyType;		/*关键字类型*/

typedef char ElemType[10];	/*其他数据项类型*/

typedef struct 
{	
	KeyType key;   			/*关键字域*/
	ElemType data; 			/*其他数据域*/
} LineList;					/*线性表元素类型*/

void SelectSort(LineList R[],int n)
{
	int i,j,k;
	LineList tmp;
	for (i=0;i<n-1;i++)
	{	
		k=i;
		for (j=i+1;j<n;j++)
			if (R[j].key<R[k].key) 
				k=j;		/*用k指出每趟在无序区段的最小元素*/
		tmp=R[i];			/*将R[k]与R[i]交换*/
		R[i]=R[k];
		R[k]=tmp;
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
	SelectSort(R,n);
	printf("排序后:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
