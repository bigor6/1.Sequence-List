
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
//2-1线性表顺序的插入删除及按值查找操作实现(c风格)
typedef struct {
	int data[20];
	int max, length;
}seqlist;

int insertlist(seqlist& L, int i, int value)//插入第i个元素
{
	if (i<1 || i>L.length+1)//i是位序
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
int deletelist(seqlist& L, int i, int &val)//删除第i个元素
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
int locateelem(seqlist& L, int value)//按值查找元素,并返回位序
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == value)
		{
			return i + 1;
		}
	}
	return 0;//正常退出，说明查找失败
}
void printlist(const seqlist& L) {//打印操作后线性表
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
	memcpy(L.data, initial_values, sizeof(initial_values)); // 复制初值到 L.data

	//L.data[L.length] = { 1,3,5,7,9,11,13,15 };
	int a=insertlist(L, 5, 18);
	if (a == 0) {
		printf("Insert successful. Updated list: ");
		printlist(L); // 输出插入后的线性表
	}
	else {
		printf("Insert failed.\n");
	}

	int c=locateelem(L,11);
	if (c == 0)
	{
		cout << "查找元素11失败!" << endl;
	}
	else
		cout << "查找元素11成功!在第" <<c<<"个位置!" <<endl;

	int  val;
	int b = deletelist(L, 6, val);
	if (b == 0)
	{
		printf("delete complete!:%d\n:",val);
		printlist(L);
	}
	else
		cout << "删除失败!\n";

	int dval = 9;
	int d = locateelem(L, dval);
	if (d == 0)
	{
		cout << "查找元素"<<dval<<"失败!" << endl;
	}
	else
		cout << "查找元素"<<dval<<"成功!在第" << d << "个位置!" << endl;

	return 0;
}