# 队列的基本概念

## 队列的定义

队列也是一种特殊的线性表，插入操作在一端进行，称为队头，删除操作在另一端进行，称为队尾。

队列就跟生活中的排队类似，不允许插队，先排的人可以先得到服务。

## 队列的特征

- 先进先出（FIFO）

## 队列的基本运算

- 初始化队列
- 入队
- 出队
- 取队头的元素
- 判断队列是否为空

## 队列的存储结构

### 顺序存储结构

```c
#define QueueSize 100

typedef char ElemType;

typedef struct  
{	
	ElemType data[QueueSize];	/*保存队中元素*/
	int front,rear;				/*队头和队尾指针*/
} SqQueue;
```

### 链式存储结构

```c
typedef char ElemType;

typedef struct QNode 
{
	ElemType data;
	struct QNode *next;
} QType;				/*链队中结点的类型*/

typedef struct qptr    	
{
	QType *front,*rear;
} LinkQueue;			/*链队类型*/
```
