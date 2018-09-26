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
void PreOrder(BTNode *bt)
{
	if (bt!=NULL)
	{
		printf("%c ",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
void InOrder(BTNode *bt)
{
	if (bt!=NULL)
	{	
		InOrder(bt->lchild);
		printf("%c ",bt->data);
		InOrder(bt->rchild);
	}
}
void PostOrder(BTNode *bt)
{
	if (bt!=NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%c ",bt->data);
	}
}
void LevelOrder(BTNode *b)
{
	BTNode *p;
	BTNode *qu[MaxSize];			/*定义环形队列,存放结点指针*/
	int front,rear;					/*定义队头和队尾指针*/
	front=rear=-1;					/*置队列为空队列*/
	rear++;
	qu[rear]=b;						/*根结点指针进入队列*/
	while (front!=rear)				/*队列不为空*/
	{	front=(front+1)%MaxSize;
		p=qu[front];				/*队头出队列*/
		printf("%c ",p->data);		/*访问结点*/
		if (p->lchild!=NULL)		/*有左孩子时将其进队*/
		{	rear=(rear+1)%MaxSize;
			qu[rear]=p->lchild;
		}
		if (p->rchild!=NULL)		/*有右孩子时将其进队*/
		{	rear=(rear+1)%MaxSize;
			qu[rear]=p->rchild;
		}
	} 
}
void main()
{
	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");	/*构造图5.10(a)所示的二叉树*/
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("先序遍历序列:");PreOrder(bt);printf("\n");
	printf("中序遍历序列:");InOrder(bt);printf("\n");
	printf("后序遍历序列:");PostOrder(bt);printf("\n");
	printf("层次遍历序列:");LevelOrder(bt);printf("\n");
}