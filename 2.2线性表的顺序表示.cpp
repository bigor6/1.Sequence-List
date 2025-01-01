
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
//2-1���Ա�˳��Ĳ���ɾ������ֵ���Ҳ���ʵ��(c���)
typedef struct {
	int data[20];
	int max, length;
}seqlist;

int insertlist(seqlist& L, int i, int value)//�����i��Ԫ��
{
	if (i<1 || i>L.length+1)//i��λ��
	{
		return -1;
	}
	if (L.length >= L.max)
	{
		return -1;
	}
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = value;
	L.length++;
	return 0;
}
int deletelist(seqlist& L, int i, int &val)//ɾ����i��Ԫ��
{
	if (i<1 || i>L.length)
		return -1;
	if (L.length > L.max)
		return -1;
	val=L.data[i - 1];
	for (int j = i; j <L.length; j++)
	{
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return 0;
}
int locateelem(seqlist& L, int value)//��ֵ����Ԫ��,������λ��
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == value)
		{
			return i + 1;
		}
	}
	return 0;//�����˳���˵������ʧ��
}
void printlist(const seqlist& L) {//��ӡ���������Ա�
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}
int main()
{
	seqlist L;
	L.max = 20;
	L.length = 8;
	int initial_values[8] = { 1, 3, 5, 7, 9, 11, 13, 15 };
	memcpy(L.data, initial_values, sizeof(initial_values)); // ���Ƴ�ֵ�� L.data

	//L.data[L.length] = { 1,3,5,7,9,11,13,15 };
	int a=insertlist(L, 5, 18);
	if (a == 0) {
		printf("Insert successful. Updated list: ");
		printlist(L); // ������������Ա�
	}
	else {
		printf("Insert failed.\n");
	}

	int c=locateelem(L,11);
	if (c == 0)
	{
		cout << "����Ԫ��11ʧ��!" << endl;
	}
	else
		cout << "����Ԫ��11�ɹ�!�ڵ�" <<c<<"��λ��!" <<endl;

	int  val;
	int b = deletelist(L, 6, val);
	if (b == 0)
	{
		printf("delete complete!:%d\n:",val);
		printlist(L);
	}
	else
		cout << "ɾ��ʧ��!\n";

	int dval = 9;
	int d = locateelem(L, dval);
	if (d == 0)
	{
		cout << "����Ԫ��"<<dval<<"ʧ��!" << endl;
	}
	else
		cout << "����Ԫ��"<<dval<<"�ɹ�!�ڵ�" << d << "��λ��!" << endl;

	return 0;
}