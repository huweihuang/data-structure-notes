# 二叉树的基本运算

## By C++

```c
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
#define MaxWidth 40

typedef char ElemType;

typedef struct tnode
{
	ElemType data;
	struct tnode *lchild,*rchild;
} BTNode;

void CreateBTree(BTNode * &bt,char *str)	/*由str创建二叉链bt*/
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	bt=NULL;			/*建立的二叉树初始时为空*/
	ch=str[j];
	while (ch!='\0')  	/*str未扫描完时循环*/
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;	/*为左孩子结点*/
		case ')':top--;break;
		case ',':k=2; break;                    /*为孩子结点右结点*/
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (bt==NULL)                   /**p为二叉树的根结点*/
					bt=p;
				else  							/*已建立二叉树根结点*/
				{	switch(k) 
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}

int BTHeight(BTNode *bt)	/*求二叉树高度*/
{
   	int lchilddep,rchilddep;
   	if (bt==NULL) return(0); 			/*空树的高度为0*/
   	else  
	{	lchilddep=BTHeight(bt->lchild);	/*求左子树的高度为lchilddep*/
	  	rchilddep=BTHeight(bt->rchild);	/*求右子树的高度为rchilddep*/
		return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
   	}
}

int NodeCount(BTNode *bt)	/*求二叉树bt的结点个数*/
{
	int num1,num2;
    	if (bt==NULL)	/*空树结点个数为0*/ 
			return 0;
    	else
    	{	num1=NodeCount(bt->lchild);	/*求出左子树的结点数*/
        	num2=NodeCount(bt->rchild);	/*求出右子树的结点数*/
        	return (num1+num2+1);
	}
}

int LeafCount(BTNode *bt)	/*求二叉树bt的叶子结点个数*/
{
	int num1,num2;
    	if (bt==NULL)	/*空树叶子结点个数为0*/ 
			return 0;
    	else if (bt->lchild==NULL && bt->rchild==NULL) 
			return 1;	/*若为叶子结点返回1*/ 
    	else
    	{	num1=LeafCount(bt->lchild);	/*求出左子树的叶子结点数*/
        	num2=LeafCount(bt->rchild);	/*求出右子树的叶子结点数*/
        	return (num1+num2);
	}
}

void DispBTree(BTNode *bt)	/*以括号表示法输出二叉树*/
{
	if (bt!=NULL)
	{	
		printf("%c",bt->data);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	
			printf("(");
			DispBTree(bt->lchild);		/*递归处理左子树*/
			if (bt->rchild!=NULL) 
				printf(",");
			DispBTree(bt->rchild);		/*递归处理右子树*/
			printf(")");
		}
	}
}

void DispBTree1(BTNode *bt)  /*以凹入表示法输出一棵二叉树*/
{
	BTNode *St[MaxSize],*p;
	int Level[MaxSize][2],top=-1,n,i,width=4;
	char type;		/*取值L表示为左结点,R表示为右结点,B表示为根结点*/
	if (bt!=NULL)
	{	
		top++;
		St[top]=bt;						/*根结点入栈*/
		Level[top][0]=width;
		Level[top][1]=2;				/*2表示是根*/
		while (top>-1)
		{	
			p=St[top];					/*退栈并凹入显示该结点值*/
			n=Level[top][0];
			switch(Level[top][1])
			{
			case 0:type='L';break;		/*左结点之后输出(L)*/
			case 1:type='R';break;		/*右结点之后输出(R)*/
			case 2:type='B';break;		/*根结点之后前输出(B)*/
			}
			for (i=1;i<=n;i++)			/*其中n为显示场宽,字符以右对齐显示*/
				printf(" ");
			printf("%c(%c)",p->data,type);
			for (i=n+1;i<=MaxWidth;i+=2)
				printf("━");
			printf("\n");
			top--;
			if (p->rchild!=NULL)
			{							/*将右子树根结点入栈*/
				top++;
				St[top]=p->rchild;
				Level[top][0]=n+width;	/*场宽增width,即缩width格后再输出*/
				Level[top][1]=1;		/*1表示是右子树*/
			}
			if (p->lchild!=NULL)
			{							/*将左子树根结点入栈*/
				top++;
				St[top]=p->lchild;
				Level[top][0]=n+width;  /*显示场宽增width*/
				Level[top][1]=0;        /*0表示是左子树*/
			}
		}
	}
}

void main()
{
	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");	/*构造图5.10(a)所示的二叉树*/
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("bt的高度:%d\n",BTHeight(bt));
	printf("bt的结点数:%d\n",NodeCount(bt));
	printf("bt的叶子结点数:%d\n",LeafCount(bt));
	printf("bt凹入表示:\n");DispBTree1(bt);printf("\n");
}
```

## By Golang

```go
// Package binarysearchtree creates a ItemBinarySearchTree data structure for the Item type
package binarysearchtree

import (
	"fmt"
	"sync"
)

// Item the type of the binary search tree
type Item interface{}

// Node a single node that composes the tree
type Node struct {
	key   int
	value Item
	left  *Node //left
	right *Node //right
}

// ItemBinarySearchTree the binary search tree of Items
type ItemBinarySearchTree struct {
	root *Node
	lock sync.RWMutex
}

// Insert inserts the Item t in the tree
func (bst *ItemBinarySearchTree) Insert(key int, value Item) {
	bst.lock.Lock()
	defer bst.lock.Unlock()
	n := &Node{key, value, nil, nil}
	if bst.root == nil {
		bst.root = n
	} else {
		insertNode(bst.root, n)
	}
}

// internal function to find the correct place for a node in a tree
func insertNode(node, newNode *Node) {
	if newNode.key < node.key {
		if node.left == nil {
			node.left = newNode
		} else {
			insertNode(node.left, newNode)
		}
	} else {
		if node.right == nil {
			node.right = newNode
		} else {
			insertNode(node.right, newNode)
		}
	}
}

// InOrderTraverse visits all nodes with in-order traversing
func (bst *ItemBinarySearchTree) InOrderTraverse(f func(Item)) {
	bst.lock.RLock()
	defer bst.lock.RUnlock()
	inOrderTraverse(bst.root, f)
}

// internal recursive function to traverse in order
func inOrderTraverse(n *Node, f func(Item)) {
	if n != nil {
		inOrderTraverse(n.left, f)
		f(n.value)
		inOrderTraverse(n.right, f)
	}
}

// PreOrderTraverse visits all nodes with pre-order traversing
func (bst *ItemBinarySearchTree) PreOrderTraverse(f func(Item)) {
	bst.lock.Lock()
	defer bst.lock.Unlock()
	preOrderTraverse(bst.root, f)
}

// internal recursive function to traverse pre order
func preOrderTraverse(n *Node, f func(Item)) {
	if n != nil {
		f(n.value)
		preOrderTraverse(n.left, f)
		preOrderTraverse(n.right, f)
	}
}

// PostOrderTraverse visits all nodes with post-order traversing
func (bst *ItemBinarySearchTree) PostOrderTraverse(f func(Item)) {
	bst.lock.Lock()
	defer bst.lock.Unlock()
	postOrderTraverse(bst.root, f)
}

// internal recursive function to traverse post order
func postOrderTraverse(n *Node, f func(Item)) {
	if n != nil {
		postOrderTraverse(n.left, f)
		postOrderTraverse(n.right, f)
		f(n.value)
	}
}

// Min returns the Item with min value stored in the tree
func (bst *ItemBinarySearchTree) Min() *Item {
	bst.lock.RLock()
	defer bst.lock.RUnlock()
	n := bst.root
	if n == nil {
		return nil
	}
	for {
		if n.left == nil {
			return &n.value
		}
		n = n.left
	}
}

// Max returns the Item with max value stored in the tree
func (bst *ItemBinarySearchTree) Max() *Item {
	bst.lock.RLock()
	defer bst.lock.RUnlock()
	n := bst.root
	if n == nil {
		return nil
	}
	for {
		if n.right == nil {
			return &n.value
		}
		n = n.right
	}
}

// Search returns true if the Item t exists in the tree
func (bst *ItemBinarySearchTree) Search(key int) bool {
	bst.lock.RLock()
	defer bst.lock.RUnlock()
	return search(bst.root, key)
}

// internal recursive function to search an item in the tree
func search(n *Node, key int) bool {
	if n == nil {
		return false
	}
	if key < n.key {
		return search(n.left, key)
	}
	if key > n.key {
		return search(n.right, key)
	}
	return true
}

// Remove removes the Item with key `key` from the tree
func (bst *ItemBinarySearchTree) Remove(key int) {
	bst.lock.Lock()
	defer bst.lock.Unlock()
	remove(bst.root, key)
}

// internal recursive function to remove an item
func remove(node *Node, key int) *Node {
	if node == nil {
		return nil
	}
	if key < node.key {
		node.left = remove(node.left, key)
		return node
	}
	if key > node.key {
		node.right = remove(node.right, key)
		return node
	}
	// key == node.key
	if node.left == nil && node.right == nil {
		node = nil
		return nil
	}
	if node.left == nil {
		node = node.right
		return node
	}
	if node.right == nil {
		node = node.left
		return node
	}
	leftmostrightside := node.right
	for {
		//find smallest value on the right side
		if leftmostrightside != nil && leftmostrightside.left != nil {
			leftmostrightside = leftmostrightside.left
		} else {
			break
		}
	}
	node.key, node.value = leftmostrightside.key, leftmostrightside.value
	node.right = remove(node.right, node.key)
	return node
}

// String prints a visual representation of the tree
func (bst *ItemBinarySearchTree) String() {
	bst.lock.Lock()
	defer bst.lock.Unlock()
	fmt.Println("------------------------------------------------")
	stringify(bst.root, 0)
	fmt.Println("------------------------------------------------")
}

// internal recursive function to print a tree
func stringify(n *Node, level int) {
	if n != nil {
		format := ""
		for i := 0; i < level; i++ {
			format += "       "
		}
		format += "---[ "
		level++
		stringify(n.left, level)
		fmt.Printf(format+"%d\n", n.key)
		stringify(n.right, level)
	}
}
```
