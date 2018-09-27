#include <stdio.h>
#define MaxSize 100

typedef int KeyType;		/*关键字类型*/

typedef char ElemType[10];	/*其他数据项类型*/

typedef struct 
{	
	KeyType key;   			/*关键字域*/
	ElemType data; 			/*其他数据域*/
} LineList;					/*线性表元素类型*/

void ShellSort(LineList R[],int n)
{
	int i,j,gap;
	LineList tmp;
	gap=n/2;					/*增量置初值*/
	while (gap>0)
	{	
		for (i=gap;i<n;i++)  	/*对所有相隔gap位置的所有元素组进行排序*/
		{
			tmp=R[i];
			j=i-gap;
			while (j>=0 && tmp.key<R[j].key)/*对相隔gap位置的元素组进行排序*/
			{
				R[j+gap]=R[j];
				j=j-gap;					/*移到本组中的前一个元素*/
			}
			R[j+gap]=tmp;
			j=j-gap;
		}
		gap=gap/2;	/*减小增量*/
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
	ShellSort(R,n);
	printf("排序后:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
