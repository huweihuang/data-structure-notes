#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType[10];
typedef struct
{	
	KeyType key;   	/*存放关键字,KeyType为关键字类型*/
    ElemType data;	/*其他数据, ElemType为其他数据的类型*/
} LineList;
int BinSearch(LineList R[],int n,KeyType k)
{
	int i,low=0,high=n-1,mid;
	int find=0;				/*find=0表示未找到;find=1表示已找到*/
   	while (low<=high && !find)
     {	mid=(low+high)/2;   /*整除取中间值*/
		if (k<R[mid].key) 
			high=mid-1;
		else if (k>R[mid].key) 
			low=mid+1;
   		else 
		{	i=mid;
			find=1;
		}
}
     if (find==0) 
		return(-1);
else
		return(i);
}
void main()
{
	KeyType a[]={2,4,7,9,10,14,18,26,32,40},k=7;
	LineList R[MaxSize];
	int n=10,i;
	for (i=0;i<n;i++)
		R[i].key=a[i];
	i=BinSearch(R,n,k);
	if (i>=0)
		printf("R[%d].key=%d\n",i,k);
	else
		printf("%d不在a中\n",k);
}

