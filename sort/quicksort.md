# 快速排序

## 基本思想

- 分治：在未排序序列中选择一个基准数（一般为第一个），将小于基准数的放在其左边，大于基准数的放在其右边，即分成两个区间
- 递归：将上述两个区间，每个区间内执行上述操作，以此类推，直到排序完成

## 步骤

- 选择一个基准数，一般为第一个: pivot := list[left] 
- 将小于基准数的放在其左边
- 将大于基准数的放在其右边
- 对每个分区执行递归操作：quickSort(list, left, i-1)；quickSort(list, i+1, right)

## By C++

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
```

## By Golang

```go
package main

import (
	"fmt"
)

func quickSort(list []int, left, right int) []int {
	if left < right {
		i, j := left, right
		pivot := list[left] // 以左边第一个数作为基准数，将第一个数暂存在pivot变量中

		// 分治
		for i < j {
			// 从右向左找出第一个小于基准数的，将list[j]赋值给list[i] 
			for j > i && list[j] > pivot {
				j--
			}
			list[i] = list[j]

			// 从左向右找出第一个大于基准数的，将list[i]赋值给list[j] 
			for i < j && list[i] < pivot {
				i++
			}
			list[j] = list[i]
		}
		list[i] = pivot
		fmt.Println(list) // 打印该趟的序列

		// 递归
		quickSort(list, left, i-1)
		quickSort(list, i+1, right)
	}
	return list
}

func main() {
	list := []int{75, 87, 68, 92, 88, 61, 77, 96, 80, 72}
	fmt.Println("初始序列:", list)
	result := quickSort(list, 0, len(list)-1)
	fmt.Println("最终结果:", result)
}
```

## 排序过程

```bash
初始序列: [75 87 68 92 88 61 77 96 80 72]

第 1 趟：[72 61 68 75 88 92 77 96 80 87]
第 2 趟：[68 61 72 75 88 92 77 96 80 87]
第 3 趟：[61 68 72 75 88 92 77 96 80 87]
第 4 趟：[61 68 72 75 87 80 77 88 96 92]
第 5 趟：[61 68 72 75 77 80 87 88 96 92]
第 6 趟：[61 68 72 75 77 80 87 88 96 92]
第 7 趟：[61 68 72 75 77 80 87 88 92 96]

最终结果: [61 68 72 75 77 80 87 88 92 96]
```
