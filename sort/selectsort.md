# 选择排序

## 基本思想

- 每次从未排序的序列中选择最小的数放置在该未排序序列的第一个
- 不断循环，直到排序完成

## 步骤

- 第一层循环：i=0; i < len(list)-1; i++
- 第二层循环：j := i + 1; j < len(list); j++
- 寻找未排序序列中最小的数: if list[j] < list[minIndex] { minIndex = j }
- 将最小的数与放置到当前未排序序列的第一个: list[i], list[minIndex] = list[minIndex], list[i]

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
```

## By Golang

```go
package main

import (
	"fmt"
)

// 选择排序
func selectSort(list []int) []int {
	var minIndex int
	for i := 0; i < len(list)-1; i++ {
		minIndex = i
		for j := i + 1; j < len(list); j++ {
			if list[j] < list[minIndex] { // 寻找未排序序列中最小的数
				minIndex = j
			}
		}
		list[i], list[minIndex] = list[minIndex], list[i] // 将当前数与最小的数交换位置
		fmt.Println("第", i+1, "趟：", list)                 // 打印每趟的序列
	}
	return list
}

func main() {
	list := []int{75, 87, 68, 92, 88, 61, 77, 96, 80, 72}
	fmt.Println("初始序列:", list)
	result := selectSort(list)
	fmt.Println("最终结果:", result)
}
```

## 排序过程

```
初始序列: [75 87 68 92 88 61 77 96 80 72]

第 1 趟： [61 87 68 92 88 75 77 96 80 72]
第 2 趟： [61 68 87 92 88 75 77 96 80 72]
第 3 趟： [61 68 72 92 88 75 77 96 80 87]
第 4 趟： [61 68 72 75 88 92 77 96 80 87]
第 5 趟： [61 68 72 75 77 92 88 96 80 87]
第 6 趟： [61 68 72 75 77 80 88 96 92 87]
第 7 趟： [61 68 72 75 77 80 87 96 92 88]
第 8 趟： [61 68 72 75 77 80 87 88 92 96]
第 9 趟： [61 68 72 75 77 80 87 88 92 96]

最终结果: [61 68 72 75 77 80 87 88 92 96]
```
