#include <stdio.h>
#include <malloc.h>
#define MaxSize 100

typedef int KeyType;		/*关键字类型*/

typedef char ElemType[10];	/*其他数据项类型*/

typedef struct 
{	
	KeyType key;   			/*关键字域*/
	ElemType data; 			/*其他数据域*/
} LineList;					/*线性表元素类型*/

void Merge(LineList R[],int low,int mid,int high) 
{
	LineList *R1;
	int i=low,j=mid+1,k=0; /*k是R1的下标,i、j分别为第1、2段的下标*/
	R1=(LineList *)malloc((high-low+1)*sizeof(LineList));  /*动态分配空间*/
	while (i<=mid && j<=high)    /*在第1段和第2段均未扫描完时循环*/
		if (R[i].key<=R[j].key)  /*将第1段中的记录放入R1中*/
		{	R1[k]=R[i];
			i++;k++; 
		}
		else                       	/*将第2段中的记录放入R1中*/
		{	R1[k]=R[j];
			j++;k++; 
		}
		while (i<=mid)           	/*将第1段余下部分复制到R1*/
		{  
			R1[k]=R[i];
			i++;k++; 
		}
		while (j<=high)           /*将第2段余下部分复制到R1*/
		{	R1[k]=R[j];
			j++;k++;  
		}
		for (k=0,i=low;i<=high;k++,i++) /*将R1复制回R中*/
			R[i]=R1[k];
} 

void MergePass(LineList R[],int length,int n)
{
	int i;
	for (i=0;i+2*length-1<n;i=i+2*length) 	/*归并length长的两相邻子表*/
		Merge(R,i,i+length-1,i+2*length-1);
	if (i+length-1<n)                	/*余下两个子表,后者长度小于length*/
		Merge(R,i,i+length-1,n-1); 	/*归并这两个子表*/
}

void MergeSort(LineList R[],int n)	/*二路归并算法*/
{
	int length;
	for (length=1;length<n;length=2*length)
		MergePass(R,length,n);
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
	MergeSort(R,n);
	printf("排序后:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
