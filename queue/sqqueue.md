# 顺序队列的基本运算

## 顺序队列的定义

```c
#include <stdio.h>
#define QueueSize 100

typedef char ElemType;

typedef struct  
{	
	ElemType data[QueueSize];	/*保存队中元素*/
	int front,rear;				/*队头和队尾指针*/
} SqQueue;
```

## 初始化队列
```c
void InitQueue(SqQueue &qu)		/*qu为引用型参数*/
{
   	qu.rear=qu.front=0;           /*指针初始化*/
} 
```

## 入队运算
```c
int EnQueue(SqQueue &qu,ElemType x)	/*入队运算,qu为引用型参数*/
{
	if ((qu.rear+1)%QueueSize==qu.front)	/*队满*/
		return 0;
	qu.rear=(qu.rear+1)%QueueSize;      /*队尾指针进1*/
	qu.data[qu.rear]=x;
	return 1;
}
```

## 出队运算
```c
int DeQueue(SqQueue &qu,ElemType &x)	/*出队运算,qu和x为引用型参数*/
{
    if (qu.rear==qu.front)
		return 0;
    qu.front=(qu.front+1)%QueueSize;    /*队头指针进1*/
    x=qu.data[qu.front];
    return 1;
}
```

## 取队头元素运算
```c
int GetHead(SqQueue qu,ElemType &x)		/*取队头元素运算,x为引用型参数*/
{
	if (qu.rear==qu.front)		/*队空*/
		return 0;
	x=qu.data[(qu.front+1)%QueueSize];
	return 1;
}
```

## 判断队空运算
```c
int QueueEmpty(SqQueue qu)		/*判断队空运算*/
{
	if (qu.rear==qu.front)		/*队空*/
		return 1;
	else
		return 0;
}
```

## main
```c
void main()
{
	SqQueue qu;
	ElemType e;
	InitQueue(qu);
	printf("队%s\n",(QueueEmpty(qu)==1?"空":"不空"));
	printf("a进队\n");EnQueue(qu,'a');
	printf("b进队\n");EnQueue(qu,'b');
	printf("c进队\n");EnQueue(qu,'c');
	printf("d进队\n");EnQueue(qu,'d');
	printf("队%s\n",(QueueEmpty(qu)==1?"空":"不空"));
	GetHead(qu,e);
	printf("队头元素:%c\n",e);
	printf("出队次序:");
	while (!QueueEmpty(qu))
	{
		DeQueue(qu,e);
		printf("%c ",e);
	}
	printf("\n");
}
```

# By Golang

```go
// Package queue creates a ItemQueue data structure for the Item type
package queue

import (
	"sync"
)

// Item the type of the queue
type Item interface{}

// ItemQueue the queue of Items
type ItemQueue struct {
	items []Item
	lock  sync.RWMutex
}

// New creates a new ItemQueue
func (s *ItemQueue) New() *ItemQueue {
	s.lock.Lock()
	s.items = []Item{}
	s.lock.Unlock()
	return s
}

// Enqueue adds an Item to the end of the queue
func (s *ItemQueue) Enqueue(t Item) {
	s.lock.Lock()
	s.items = append(s.items, t)
	s.lock.Unlock()
}

// Dequeue removes an Item from the start of the queue
func (s *ItemQueue) Dequeue() *Item {
	s.lock.Lock()
	item := s.items[0]
	s.items = s.items[1:len(s.items)]
	s.lock.Unlock()
	return &item
}

// Front returns the item next in the queue, without removing it
func (s *ItemQueue) Front() *Item {
	s.lock.RLock()
	item := s.items[0]
	s.lock.RUnlock()
	return &item
}

// IsEmpty returns true if the queue is empty
func (s *ItemQueue) IsEmpty() bool {
	s.lock.RLock()
	defer s.lock.RUnlock()
	return len(s.items) == 0
}

// Size returns the number of Items in the queue
func (s *ItemQueue) Size() int {
	s.lock.RLock()
	defer s.lock.RUnlock()
	return len(s.items)
}
```
