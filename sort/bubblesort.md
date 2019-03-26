# 冒泡排序

## 基本思想

- 比较相邻两个元素，如果第一个比第二个大，就交换两者的顺序
- 对每一对相邻的元素做同样的操作，从最后一对到第一对，每一趟结束最小的元素会排在第一个（即冒泡）
- 从未排序的元素开始循环做以上操作，直到排序完成

## 步骤

1. 第一层循环: i=0; i<(len-1); i++
2. 第二层循环: j=len-1; j>i; j--
3. 比较相邻两个元素: list[j-1]和list[j]
4. 如果前者比后者大，就交换顺序: list[j-1], list[j] = list[j], list[j-1]

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
```

## By Golang

```go
package main

import (
	"fmt"
)

// 冒泡排序，从小到大
func bubbleSort(list []int) []int {
	for i := 0; i < len(list)-1; i++ {  
		for j := len(list) - 1; j > i; j-- {  // 从最后两个元素开始比较
			if list[j-1] > list[j] { // 相邻元素对比
				list[j-1], list[j] = list[j], list[j-1] // 如果后者比前者小，就交互位置
			}
		}
		fmt.Println("第", i+1, "趟：", list)
	}
	return list
}

func main() {
	list := []int{75, 87, 68, 92, 88, 61, 77, 96, 80, 72}
	fmt.Println("初始序列:", list)
	result := bubbleSort(list)
	fmt.Println("最终结果:", result)
}
```

## 排序过程

```bash
初始序列: [75 87 68 92 88 61 77 96 80 72]

第 1 趟： [61 75 87 68 92 88 72 77 96 80]
第 2 趟： [61 68 75 87 72 92 88 77 80 96]
第 3 趟： [61 68 72 75 87 77 92 88 80 96]
第 4 趟： [61 68 72 75 77 87 80 92 88 96]
第 5 趟： [61 68 72 75 77 80 87 88 92 96]
第 6 趟： [61 68 72 75 77 80 87 88 92 96]
第 7 趟： [61 68 72 75 77 80 87 88 92 96]
第 8 趟： [61 68 72 75 77 80 87 88 92 96]
第 9 趟： [61 68 72 75 77 80 87 88 92 96]

最终结果: [61 68 72 75 77 80 87 88 92 96]
```
