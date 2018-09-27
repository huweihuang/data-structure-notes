#include <stdio.h>
#define MaxSize 100

typedef int KeyType;		/*关键字类型*/

typedef char ElemType[10];	/*其他数据项类型*/

typedef struct 
{	
	KeyType key;   			/*关键字域*/
	ElemType data; 			/*其他数据域*/
} LineList;					/*线性表元素类型*/

void InsertSort(LineList R[],int n)
{
	int i,j;
	LineList tmp;
	for (i=1;i<n;i++)
	{	
		tmp=R[i];
		j=i-1;
		while (j>=0 && tmp.key<R[j].key)/*元素后移,以便腾出一个位置插入tmp*/
		{	
			R[j+1]=R[j];
			j--;
		}
		R[j+1]=tmp;		/*在j+1位置处插入tmp*/
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
	InsertSort(R,n);
	printf("排序后:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
