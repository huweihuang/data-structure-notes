#include <stdio.h>
#include <malloc.h>
typedef struct node
{	
	char data;			/*存放字符*/
	struct node *next;	/*指针域*/
} LinkString;
void Assign(LinkString *&s,char t[])
{
	int i=0;
	LinkString *q,*tc;
	s=(LinkString *)malloc(sizeof(LinkString)); /*建立头结点*/
	s->next=NULL;
	tc=s;					/*tc指向s串的尾结点*/
	while (t[i]!='\0')
	{
		q=(LinkString *)malloc(sizeof(LinkString));
		q->data=t[i];
		tc->next=q;tc=q;
		i++;
	}
	tc->next=NULL;		/*终端结点的next置NULL*/
}
void StrCopy(LinkString *&s,LinkString *t)	/*t=>s*/
{
	LinkString *p=t->next,*q,*tc;
	s=(LinkString *)malloc(sizeof(LinkString)); /*建立头结点*/
	s->next=NULL;
	tc=s;				/*tc指向s串的尾结点*/
	while (p!=NULL)		/*复制t的所有结点*/
	{
		q=(LinkString *)malloc(sizeof(LinkString));
		q->data=p->data;
		tc->next=q;tc=q;
		p=p->next;
    }
	tc->next=NULL;		/*终端结点的next置NULL*/
}
int StrLength(LinkString *s)
{
	int n=0;
	LinkString *p=s->next;
	while (p!=NULL)		/*扫描串s的所有结点*/
	{
		n++;p=p->next;
	}
    return(n);
}
int StrEqual(LinkString *s,LinkString *t)
{
	LinkString *p=s->next,*q=t->next;
	while (p!=NULL && q!=NULL)	/*比较两串的当前结点*/
	{
		if (p->data!=q->data)	/*data域不等时返回0*/
			return(0);
        p=p->next;q=q->next;
	}
	if (p!=NULL || q!=NULL)		/*两串长度不等时返回0*/
		return(0);
	return(1);
}
LinkString *Concat(LinkString *s,LinkString *t)
{
	LinkString *p=s->next,*q,*tc,*str;
    str=(LinkString *)malloc(sizeof(LinkString));  /*建立头结点*/
	str->next=NULL;
	tc=str;				/*tc总是指向新链表的尾结点*/
	while (p!=NULL)		/*将s串复制给str*/
	{
		q=(LinkString *)malloc(sizeof(LinkString));
		q->data=p->data;
		tc->next=q;tc=q;
		p=p->next;
	}
	p=t->next;
	while (p!=NULL)		/*将t串复制给str*/
	{
		q=(LinkString *)malloc(sizeof(LinkString));
		q->data=p->data;
		tc->next=q;tc=q;
		p=p->next;
	}
    tc->next=NULL;
    return(str);
}
LinkString *SubStr(LinkString *s,int i,int j)
{
	int k=1;
	LinkString *p=s->next,*q,*tc,*str;
    str=(LinkString *)malloc(sizeof(LinkString));  /*建立头结点*/
	str->next=NULL;
	tc=str;							/*tc总是指向新链表的尾结点*/
	while (k<i && p!=NULL)
	{
		p=p->next;k++;
	}
	if (p!=NULL)
	{
		k=1;
		while (k<=j && p!=NULL)		/*复制j个结点*/
		{
			q=(LinkString *)malloc(sizeof(LinkString));
			q->data=p->data;
			tc->next=q;tc=q;
			p=p->next;
			k++;
		}
		tc->next=NULL;
	}
	return(str);
}
int Index(LinkString *s,LinkString *t)
{
	LinkString *p=s->next,*p1,*q,*q1;
	int i=0;
	while (p!=NULL)   		/*循环扫描s的每个结点*/
	{
        q=t->next;			/*子串总是从第一个字符开始比较*/
        if (p->data==q->data)/*判定两串当前字符相等*/
        {			/*若首字符相同,则判定s其后字符是否与t的依次相同*/
			p1=p->next;q1=q->next;
			while (p1!=NULL && q1!=NULL && p1->data==q1->data)
			{
				p1=p1->next;
				q1=q1->next;
			}
			if (q1==NULL)	/*若都相同,则返回相同的子串的起始位置*/
				return(i);
        }
        p=p->next;i++;
	}
	return(-1);		/*若不是子串,返回-1*/
}
int InsStr(LinkString *&s,int i,LinkString *t)
{
	int k;
	LinkString *q=s->next,*p,*str;
	StrCopy(str,t);		/*将t复制到str*/
	p=str;str=str->next;
	free(p);			/*删除str的头结点*/
	for (k=1;k<i;k++)	/*在s中找到第i-1个结点,由p指向它,q指向下一个结点*/
	{
		if (q==NULL)	/*位置参数i错误*/
			return(0);
		p=q;
		q=q->next;
	}
	p->next=str;		/*将str链表链接到*p之后*/
	while (str->next!=NULL)	/*由str指向尾结点*/
		str=str->next;		
	str->next=q;		/*将*q链接到*str之后*/
	return(1);
}
int DelStr(LinkString *&s,int i,int j)
{
	int k;
	LinkString *q=s->next,*p,*t;
	for (k=1;k<i;k++)	/*在s中找到第i-1个结点,由p指向它,q指向下一个结点*/
	{
        if (q==NULL)		/*位置参数i错误*/
			return(0);
        p=q;
        q=q->next;
	}
    for (k=1;k<=j;k++)	/*删除*p之后的j个结点,并由q指向下一个结点*/
	{
		if (q==NULL)	/*长度参数j错误*/
            return(0);
		t=q;
		q=q->next;
		free(t);
	}
	p->next=q;
	return(1);
}
LinkString *RepStrAll(LinkString *s,LinkString *s1,LinkString *s2)
{
	int i;
	i=Index(s,s1);
	while (i>=0)
	{
		DelStr(s,i+1,StrLength(s1));	/*删除串s1*/
		InsStr(s,i+1,s2);				/*插入串s2*/
		i=Index(s,s1);
	}
	return(s);
}
void DispStr(LinkString *s)
{
	LinkString *p=s->next;
	while (p!=NULL)
	{
        printf("%c",p->data);
        p=p->next;
	}
	printf("\n");
}
void main()
{
	LinkString *s1,*s2,*s3,*s4,*s5,*s6,*s7;
	Assign(s1,"abcd");
	printf("s1:");DispStr(s1);
	printf("s1的长度:%d\n",StrLength(s1));
	printf("s1=>s2\n");
	StrCopy(s2,s1);
	printf("s2:");DispStr(s2);
	printf("s1和s2%s\n",(StrEqual(s1,s2)==1?"相同":"不相同"));
	Assign(s3,"12345678");
	printf("s3:");DispStr(s3);
	printf("s1和s3连接=>s4\n");
	s4=Concat(s1,s3);
	printf("s4:");DispStr(s4);
	printf("s3[2..5]=>s5\n");
	s5=SubStr(s3,2,4);
	printf("s5:");DispStr(s5);
	Assign(s6,"567");
	printf("s6:");DispStr(s6);
	printf("s6在s3中位置:%d\n",Index(s3,s6));
	printf("从s3中删除s3[3..6]字符\n");
	DelStr(s3,3,4);
	printf("s3:");DispStr(s3);
	printf("从s4中将s6替换成s1=>s7\n");
	s7=RepStrAll(s4,s6,s1);
	printf("s7:");DispStr(s7);
}
