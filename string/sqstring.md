# 顺序串的基本运算

## 顺序串的定义

```c
#include <stdio.h>
#define MaxSize 100  /*最多字符个数*/

typedef struct
{	
	char ch[MaxSize];	/*存放串字符*/
   	int len;			/*存放串的实际长度*/
} SqString;				/*顺序串类型*/
```

## 赋值运算
```c
void Assign(SqString &s,char t[])	/*串赋值运算*/
{
	int i=0;
	while (t[i]!='\0')
	{
        s.ch[i]=t[i];
        i++;
	}
	s.len=i;
}
```

## 复制运算
```c
void StrCopy(SqString &s,SqString t)	/*串复制运算*/
{
	int i;
	for (i=0;i<t.len;i++)
		s.ch[i]=t.ch[i];
	s.len=t.len;
}
```

## 求串长运算
```c
int StrLength(SqString s)	/*求串长运算*/
{
	return(s.len);
} 
```

## 判断串相等运算
```c
int StrEqual(SqString s,SqString t)	/*判断串相等运算*/
{
	int i=0;
	if (s.len!=t.len)		/*串长不同时返回0*/
		return(0);
	else
	{
        for (i=0;i<s.len;i++)
			if (s.ch[i]!=t.ch[i]) /*有一个对应字符不同时返回0*/
				return(0);
		return(1);
	}
}
```

## 串连接运算
```c
SqString Concat(SqString s,SqString t)	/*串连接运算*/
{
	SqString r;
	int i,j;
	for (i=0;i<s.len;i++)		/*将s复制到r*/
		r.ch[i]=s.ch[i];
	for (j=0;j<t.len;j++)		/*将t复制到r*/
		r.ch[s.len+j]=t.ch[j];
	r.len=i+j;
	return(r);					/*返回r*/
}
```

## 求子串运算
```c
SqString SubStr(SqString s,int i,int j)	/*求子串运算*/
{
	SqString t;
	int k;
	if (i<1 || i>s.len || j<1 || i+j>s.len+1)
		t.len=0;			/*参数错误时返回空串*/
	else
	{
		for (k=i-1;k<i+j;k++)
			t.ch[k-i+1]=s.ch[k];
		t.len=j;
	}
	return(t);
} 
```

## 查找子串位置运算
```c
int Index(SqString s,SqString t)	/*查找子串位置运算*/
{
	int i=0,j=0,k;				/*i和j分别扫描主串s和子串t*/
	while (i<s.len && j<t.len)
	{
		if (s.ch[i]==t.ch[j]) /*对应字符相同时,继续比较下一对字符*/
		{
			i++;j++;
		}
		else				/*否则,主子串指针回溯重新开始下一次匹配*/
		{
			i=i-j+1;j=0;
		}
	}
	if (j>=t.len)
		k=i-t.len+1;/*求出第一个字符的位置*/
	else
		k=-1;		/*置特殊值-1*/
	return(k);
}
```

## 子串插入运算
```c
int InsStr(SqString &s,int i,SqString t)	/*子串插入运算*/
{
	int j;
	if (i>s.len+1)
		return(0);					/*位置参数值错误*/
	else 
	{
		for (j=s.len;j>=i-1;j--) 	/*将s.ch[i-1]-s.ch[s.len-1]*/
			s.ch[j+t.len]=s.ch[j];	/*后移t.len个位置*/
		for (j=0;j<t.len;j++)
			s.ch[i+j-1]=t.ch[j];
		s.len=s.len+t.len;     		/*修改s串长度*/
		return(1);
	}
}
```

## 子串删除运算
```c
int DelStr(SqString &s,int i,int j)	/*子串删除运算*/
{
	int k;
	if (i<1 || i>s.len || j<1 || i+j>s.len+1)
		return(0);		/*位置参数值错误*/
    else
	{
		for (k=i+j-1;k<s.len;k++) 	/*将s的第i+j位置之后的字符前移j位*/
			s.ch[k-j]=s.ch[k];
		s.len=s.len-j;            	/*修改s的长度*/
		return(1);
	}
} 
```

## 子串替换运算
```c
SqString RepStrAll(SqString s,SqString s1,SqString s2)	/*子串替换运算*/
{
	int i;
	i=Index(s,s1);
	while (i>=0)
	{
		DelStr(s,i,s1.len);	/*删除*/
		InsStr(s,i,s2);		/*插入*/
		i=Index(s,s1);
	}
	return(s);
}
```

## 输出串运算
```c
void DispStr(SqString s)	/*输出串运算*/
{
	int i;
	for (i=0;i<s.len;i++)
		printf("%c",s.ch[i]);
	printf("\n");
}
```

## main
```c
void main()
{
	SqString s1,s2,s3,s4,s5,s6,s7;
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
```
