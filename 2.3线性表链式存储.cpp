#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//头插法和尾插法,按值查找，按序号查找，一般插入,删除结点
typedef struct LNode{//单链表结点类型
	int data;//数据域
	struct LNode* next;//指针域
}LNode, * LinkList;//定义指向单链表的头指针

LinkList ListHeadInsert(LinkList& L)
{
	LNode* s;//next域指针
	int x;
	L = (LinkList)malloc(sizeof(LNode));//创建头结点L
	L->next = NULL;//头结点指向空链表
	
	while (scanf("%d",&x)!= 9999)//输入9999表示结束
	{
		s = (LNode*)malloc(sizeof(LNode));//创建新节点s
		s->data = x;
		s->next = L->next;//头插法
		L->next = s;
		scanf("%d\n", &x);
	}
	return L;
}
LinkList ListRearInsert(LinkList& L)//尾插法
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));//建立头结点
	LNode *s2, *r = L;
	while (scanf("%d", &x) != 9999)
	{
		s2 = (LinkList)malloc(sizeof(LNode));
		s2->data = x;
		r->next = s2;
		r = s2;

	}
	r->next = NULL;
	return L;
}
LNode* FindX(LinkList& L, int val)//按值查找
{
	LNode *p = L->next;//设当前结点第一个结点为p
	while (p->data != val&&p!=NULL)
	{
		p = p->next;
	}
	return p;
}
LNode* FindLNodei(LinkList& L, int i)//按位查找
{
	int j = 1;
	LNode* p = L->next;
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;//返回第i个结点的指针
}
LinkList CommonInsert(LinkList& L,int i)//普通插入第i个位置,非尾插法
{
	int x;//待插入元素值
	if (i < 1)//输入位置错误
	{
		return false;
	}
		LNode* p = FindLNodei(L, i - 1);//找位置第i-1
		LNode* s = (LinkList)malloc(sizeof(LNode));//创建待插入结点s
		scanf("%x", &x);//输入待插入结点值
		s->data = x;
		s->next = p->next;
		p->next = s;
		return L;
		
	
	if (i == 1)
	{
		ListHeadInsert(L);//头插法插到第一个位置
	}
}
LinkList DeleteLNode(LinkList& L, int i)//删除第i个结点
{
	if (i < 1)//输入位置错误
	{
		return false;
	}
	LNode* p = FindLNodei(L, i-1);//定位待删除结点
	LNode* q = p->next;
	p->next = q->next;
	free(q);//回收结点指针
	return L;
}
