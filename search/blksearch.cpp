#include <stdio.h>
#define MaxSize 100
#define MaxBlk 20
typedef int KeyType;
typedef char ElemType[10];
typedef struct
{	
	KeyType key;   	/*存放关键字,KeyType为关键字类型*/
    ElemType data;	/*其他数据, ElemType为其他数据的类型*/
} LineList;
typedef struct
{	
	KeyType key;
	int low,high;
} IDXType;			/*索引表的类型*/
int BlkSearch(LineList R[],IDXType idx[],int m,KeyType k)
{
	int low=0,high=m-1,mid,i,j,find=0;
	while (low<=high && !find)    /*二分查找索引表*/
	{
		mid=(low+high)/2;
		if (k<idx[mid].key) 
			high=mid-1;
		else if (k>idx[mid].key) 
			low=mid+1;
		else 
		{
			high=mid-1;
			find=1;
		}
	}
	if (low<m)     				/*k小于索引表内最大值*/
	{
		i=idx[low].low;			/*在索引表中定块起始地址*/
		j=idx[low].high;		/*在索引表中定块终止地址*/
   	}
	while (i<j && R[i].key!=k) /*在指定的块内采用顺序方法进行查找*/
		i++;
     if (i>=j)
		 return(-1);
    else
		return(i);
}

void main()
{
	KeyType a[]={9,22,12,14,35,42,44,38,48,60,58,47,78,80,77,82},k=48;
	LineList R[MaxSize];
	IDXType I[MaxBlk];
	int n=16,m=4,i;
	for (i=0;i<n;i++)
		R[i].key=a[i];
	I[0].key=22;I[0].low=0;I[0].high=3;
	I[1].key=44;I[1].low=4;I[1].high=7;
	I[2].key=60;I[2].low=8;I[2].high=11;
	I[3].key=82;I[3].low=12;I[3].high=15;
	i=BlkSearch(R,I,m,k);
	if (i>=0)
		printf("R[%d].key=%d\n",i,k);
	else
		printf("%d不在a中\n",k);
}

