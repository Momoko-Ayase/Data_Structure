#include <iostream>
using namespace std;
#include "SqList.h"
template <class DT>
void DeleElem_e(SqList<DT>& L, int e)
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
	SqList<int> L;
	InitList(L, 32);
	cout << "请输入要创建的元素个数:";
	cin >> i;
	cout << endl;
	CreateList(L, i);
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