# 线性表的基本概念

## 线性表的定义

线性表是由n（n>=0）个节点组成的有限序列，通常表示成（a1,a2,...,an），满足以下特征。

## 线性表的特征

- 线性表中每个节点至多只有一个前驱节点且至多只有一个后继结点
- 起始节点没有前驱节点
- 终结节点没有后继节点

## 线性表的基本运算

- 初始化线性表
- 求线性表的长度
- 求线性表的第i个元素
- 按值查找元素，返回元素序号
- 插入元素
- 删除元素
- 输出列表

## 线性表的存储结构

### 顺序存储结构

```c
#define MAXSIZE 100 /*顺序表的容量*/

typedef char ElemType;

typedef struct
{
	ElemType data[MAXSIZE]; /*存放顺序表的元素*/
	int length;				/*顺序表的实际长度*/
} SqList;
```

### 链式存储结构

#### 单链表

```c
typedef char ElemType;

typedef struct node 
{ 	
	ElemType data;		/*数据域*/
	struct node *next; 	/*指针域*/
} SLink;
```

#### 双链表
  
```c
typedef char ElemType;

typedef struct node
{	
	ElemType data;				/*数据域*/
	struct node *prior,*next;  /*分别指向前驱结点和后继结点的指针*/
} DLink;
```
