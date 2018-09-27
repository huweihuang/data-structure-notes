#include <stdio.h>
#include <malloc.h>
typedef int KeyType;
typedef char ElemType[10];
typedef struct tnode
{	
	KeyType key;
	ElemType data;
	struct tnode *lchild,*rchild;
} BSTNode;
BSTNode *BSTSearch(BSTNode *bt,KeyType k)
{
	BSTNode *p=bt;
	while (p!=NULL && p->key!=k)
	{
		if (k<p->key)
            p=p->lchild;  /*沿左子树查找*/
		else
            p=p->rchild;  /*沿右子树查找*/
	}
	return(p);
}
int BSTInsert(BSTNode *&bt,KeyType k)
{
	BSTNode *f,*p=bt;
	while (p!=NULL)
	{
		if (p->key==k)
			return(0);
		f=p;						/*f指向*p结点的双亲结点*/
		if (p->key>k)
			p=p->lchild;			/*在左子树中查找*/
		else
			p=p->rchild;			/*在右子树中查找*/
	}
	p=(BSTNode *)malloc(sizeof(BSTNode));	/*建立新结点*/
	p->key=k;
	p->lchild=p->rchild=NULL;
	if (bt==NULL)					/*原树为空时,*p作为根结点插入*/
		bt=p;
	else if (k<f->key)
		f->lchild=p;				/*插入*p作为*f的左孩子*/
	else
		f->rchild=p;				/*插入*p作为*f的右孩子*/
	return(1);
}
void CreateBST(BSTNode *&bt,KeyType str[],int n)
{
	bt=NULL;         			  /*初始时bt为空树*/
	int i=0;
	while (i<n) 
	{  	
		BSTInsert(bt,str[i]); /*将关键字str[i]插入二叉排序树bt中*/
		i++;
    }
}
void DispBST(BSTNode *bt)
{
	if (bt!=NULL)
	{	printf("%d",bt->key);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");
			DispBST(bt->lchild);				/*递归处理左子树*/
			if (bt->rchild!=NULL) printf(",");
			DispBST(bt->rchild);				/*递归处理右子树*/
			printf(")");
		}
	}
}
int BSTDelete(BSTNode *&bt,KeyType k)
{
	BSTNode *p=bt,*f,*r,*f1;
	f=NULL;						/*p指向待比较的结点,f指向*p的双亲结点*/
	while (p!=NULL && p->key!=k)/*查找值域为x的结点*/
	{	f=p;
        	if (p->key>k) 
			p=p->lchild;		/*在左子树中查找*/
        	else
			p=p->rchild;		/*在右子树中查找*/
	}
	if (p==NULL)				/*未找到key域为k的结点*/
		return(0);
	else if (p->lchild==NULL)  /**p为被删结点,若它无左子树*/
	{
		if (f==NULL)			/**p是根结点,则用右孩子替换它*/
			bt=p->rchild;
		else if (f->lchild==p)	/**p是双亲结点的左孩子,则用其右孩子替换它*/
		{	f->lchild=p->rchild;
			free(p);
		}
		else if(f->rchild==p)	/**p是双亲结点的右孩子,则用其右孩子替换它*/
		{	f->rchild=p->rchild;
			free(p);
		}
	}
	else if (p->rchild==NULL)	/**p为被删结点,若它无右子树*/
	{
		if (f==NULL)			/**p是根结点,则用左孩子替换它*/
			bt=p->lchild;
		if (f->lchild==p)		/**p是双亲结点的左孩子,则用其左孩子替换它*/
		{	f->lchild=p->lchild;
			free(p);
		}
		else if(f->rchild==p)	/**p是双亲结点的右孩子,则用其左孩子替换它*/
		{	f->rchild=p->lchild;
			free(p);
		}
	}
	else						/**p为被删结点,若它有左子树和右子树*/
	{
		f1=p;r=p->lchild;		/*查找*p的左子树中的最右下结点*r*/
		while (r->rchild!=NULL)	/**r一定是无右子树的结点,*f1作为r的双亲*/
		{	f1=r;
			r=r->rchild;
		}
		if (f1->lchild==r)		/**r是*f1的左孩子,删除*r*/
			f1->lchild=r->rchild;
		else if (f1->rchild==r)	/**r是*f1的右孩子,删除*r*/
			f1->rchild=r->lchild;
		r->lchild=p->lchild;	/*以下语句是用*r替代*p*/
		r->rchild=p->rchild;    
		if (f==NULL)			/**f为根结点*/
			bt=r;				/*被删结点是根结点*/
		else if (f->lchild==p)	/**p是*f的左孩子*/
			f->lchild=r;
		else					/**p是*f的右孩子*/
			f->rchild=r;
		free(p);
	}
	return(1);
}
void main()
{
	BSTNode *bt=NULL,*p;
	KeyType a[]={10,6,12,8,3,20,9,25,15},k;
	int n=9;
	CreateBST(bt,a,n);
	printf("BST:");DispBST(bt);printf("\n");
	k=9;
	printf("查找关键字为%d的结点\n",k);
	p=BSTSearch(bt,k);
	if (p!=NULL)
		printf("存在关键字为%d结点\n",k);
	else
		printf("不存在关键字为%d结点\n",k);
	k=7;
	printf("插入关键字为%d的结点\n",k);
	BSTInsert(bt,k);
	printf("BST:");DispBST(bt);printf("\n");
	k=10;
	printf("删除关键字为%d的结点\n",k);
	BSTDelete(bt,k);
	printf("BST:");DispBST(bt);printf("\n");
}
