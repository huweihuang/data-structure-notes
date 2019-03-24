# 栈的基本概念

## 栈的定义

栈是一种特殊的线性表，插入和删除操作在表的某一端进行，允许插入和删除操作的一端称为`栈顶`，另一端称为`栈底`。

可以把栈看作一个竖直的桶，每次只能放入一个元素，先放入的元素在下，后放入的元素在上，后放入的元素先出。

## 栈的特征

 - 后进先出（LIFO）

## 栈的基本运算

- 初始化栈
- 进栈
- 出栈，即返回栈顶元素，并删除当前的栈顶元素
- 取栈顶元素
- 判断栈空


## 栈的存储结构

栈的结构定义主要包含以下属性

- data: 一维数组，用于保存栈中的元素
  
  - StackSize：栈的大小，即数组的大小
  
  - ElemType：元素的类型

- top: 栈顶的指针


### 顺序存储结构

```c
typedef char ElemType;

#define StackSize 100		/*顺序栈的初始分配空间*/

typedef struct 
{	
	ElemType data[StackSize];	/*保存栈中元素*/
	int top;					/*栈指针*/
} SqStack;
```

### 链式存储结构

```c
typedef char ElemType;

typedef struct lsnode 
{	
	ElemType data;			/*存储结点数据*/
	struct lsnode *next;	/*指针域*/
} LinkStack;
```
