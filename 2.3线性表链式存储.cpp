#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//ͷ�巨��β�巨,��ֵ���ң�����Ų��ң�һ�����,ɾ�����
typedef struct LNode{//������������
	int data;//������
	struct LNode* next;//ָ����
}LNode, * LinkList;//����ָ�������ͷָ��

LinkList ListHeadInsert(LinkList& L)
{
	LNode* s;//next��ָ��
	int x;
	L = (LinkList)malloc(sizeof(LNode));//����ͷ���L
	L->next = NULL;//ͷ���ָ�������
	
	while (scanf("%d",&x)!= 9999)//����9999��ʾ����
	{
		s = (LNode*)malloc(sizeof(LNode));//�����½ڵ�s
		s->data = x;
		s->next = L->next;//ͷ�巨
		L->next = s;
		scanf("%d\n", &x);
	}
	return L;
}
LinkList ListRearInsert(LinkList& L)//β�巨
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));//����ͷ���
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
LNode* FindX(LinkList& L, int val)//��ֵ����
{
	LNode *p = L->next;//�赱ǰ����һ�����Ϊp
	while (p->data != val&&p!=NULL)
	{
		p = p->next;
	}
	return p;
}
LNode* FindLNodei(LinkList& L, int i)//��λ����
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
	return p;//���ص�i������ָ��
}
LinkList CommonInsert(LinkList& L,int i)//��ͨ�����i��λ��,��β�巨
{
	int x;//������Ԫ��ֵ
	if (i < 1)//����λ�ô���
	{
		return false;
	}
		LNode* p = FindLNodei(L, i - 1);//��λ�õ�i-1
		LNode* s = (LinkList)malloc(sizeof(LNode));//������������s
		scanf("%x", &x);//�����������ֵ
		s->data = x;
		s->next = p->next;
		p->next = s;
		return L;
		
	
	if (i == 1)
	{
		ListHeadInsert(L);//ͷ�巨�嵽��һ��λ��
	}
}
LinkList DeleteLNode(LinkList& L, int i)//ɾ����i�����
{
	if (i < 1)//����λ�ô���
	{
		return false;
	}
	LNode* p = FindLNodei(L, i-1);//��λ��ɾ�����
	LNode* q = p->next;
	p->next = q->next;
	free(q);//���ս��ָ��
	return L;
}
