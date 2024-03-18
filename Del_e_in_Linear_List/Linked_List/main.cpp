#include <iostream>
using namespace std;
#include "LinkList.h"
template <class DT>
void DeleElem_e(LNode<DT>*& L, int e)
{
	for (int i = 1; i <= L.length; i++)
	{
		int n;
		GetElem_i(L, i, n);
		if (e == n) DeleElem_i(L, i--);
	}
}
int main()
{
	int i;
	LNode<int>* L;
	InitList(L);
	int length;
	cout << "请输入要创建的元素个数:";
	cin >> length;
	CreateList_1(L, length);
	cout << "创建的顺序表元素为：\n";
	DispList(L);
	cout << endl;
	int e;
	cout << "请输入要删除的元素的值:";
	cin >> e;
	DeleElem_e(L, e);
	cout << "删除后的顺序表元素为：\n";
	DispList(L);
	cout << endl;
	return 0;
}