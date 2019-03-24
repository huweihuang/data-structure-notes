# 顺序表的基本运算

## 线性表的定义
```c
#include <stdio.h>
#define MAXSIZE 100 /*顺序表的容量*/

typedef char ElemType;

typedef struct
{
	ElemType data[MAXSIZE]; /*存放顺序表的元素*/
	int length;				/*顺序表的实际长度*/
} SqList;
```

## 初始化线性表
```c
void InitList(SqList &sq) /*初始化线性表*/
{
	sq.length = 0;
}
```

## 求线性表长度
```c
int GetLength(SqList sq) /*求线性表长度*/
{
	return sq.length;
}
```

## 求线性表中第i个元素
```c
int GetElem(SqList sq, int i, ElemType &e) /*求线性表中第i个元素*/
{
	if (i < 1 || i > sq.length) /*无效的i值*/
		return 0;
	else
	{
		e = sq.data[i - 1];
		return 1;
	}
}
```

## 按值查找
```c
int Locate(SqList sq, ElemType x) /*按值查找*/
{
	int i = 0;
	while (sq.data[i] != x) /*查找值为x的第1个结点*/
		i++;
	if (i > sq.length)
		return (0); /*未找到*/
	else
		return (i + 1);
}
```

## 插入元素

```c
int InsElem(SqList &sq, ElemType x, int i) /*插入元素*/
{
	int j;
	if (i < 1 || i > sq.length + 1) /*无效的参数i*/
		return 0;
	for (j = sq.length; j > i; j--) /*将位置为i的结点及之后的结点后移*/
		sq.data[j] = sq.data[j - 1];
	sq.data[i - 1] = x; /*在位置i处放入x*/
	sq.length++;		/*线性表长度增1*/
	return 1;
}
```

## 删除元素
```c
int DelElem(SqList &sq, int i) /*删除元素*/
{
	int j;
	if (i < 1 || i > sq.length) /*无效的参数i*/
		return 0;
	for (j = i; j < sq.length; j++) /*将位置为i的结点之后的结点前移*/
		sq.data[j - 1] = sq.data[j];
	sq.length--; /*线性表长度减1*/
	return 1;
}
```

## 输出线性表
```c
void DispList(SqList sq) /*输出线性表*/
{
	int i;
	for (i = 1; i <= sq.length; i++)
		printf("%c ", sq.data[i - 1]);
	printf("\n");
}
```

## main
```c
void main()
{
	int i;
	ElemType e;
	SqList sq;
	InitList(sq);		 /*初始化顺序表sq*/
	InsElem(sq, 'a', 1); /*插入元素*/
	InsElem(sq, 'c', 2);
	InsElem(sq, 'a', 3);
	InsElem(sq, 'e', 4);
	InsElem(sq, 'd', 5);
	InsElem(sq, 'b', 6);
	printf("线性表:");
	DispList(sq);
	printf("长度:%d\n", GetLength(sq));
	i = 3;
	GetElem(sq, i, e);
	printf("第%d个元素:%c\n", i, e);
	e = 'a';
	printf("元素%c是第%d个元素\n", e, Locate(sq, e));
	i = 4;
	printf("删除第%d个元素\n", i);
	DelElem(sq, i);
	printf("线性表:");
	DispList(sq);
}
```
