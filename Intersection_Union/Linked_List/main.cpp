#include <iostream>
using namespace std;
#include "LinkList.h"
template <class DT>
bool CreateListNoRepeat(LNode<DT>*& L, int n)
{
	int i;
	LNode<DT>* p, * s;
	p = L;
	cout << "依次输入" << n << "个数据元素：" << endl;
	for (i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		if (LocateElem_e(L, temp)) i--;
		else
		{
			s = new LNode<DT>;
			if (!s) return false;
			s->data = temp;
			s->next = p->next;
			p->next = s;
			p = s;
		}
	}
	return true;
}
template <class DT>
void Union(LNode<DT>*& A, LNode<DT>*& B, int length_a, int length_b)
{
	for (int i = 1; i <= length_b; ++i) // as "i = 0" is the head node
	{
		int temp;
		GetElem_i(B, i, temp); // You should manually get the element instead of using B.elem[i]
		if (LocateElem_e(A, temp) == 0) InsertElem_i(A, ++length_a, temp); // ++length_a to always insert at the end
	}
}
template <class DT>
void Intersection(LNode<DT>*& A, LNode<DT>*& B, int length_a)
{
	int k = 0;
	for (int i = 1; i <= length_a; ++i)
	{
		int temp;
		GetElem_i(A, i, temp);
		if (LocateElem_e(B, temp) == 0)
		{
			DeleElem_i(A, i--);
			length_a--;
		}
	}
}
int main()
{
	LNode<int>* A;
	LNode<int>* B;
	InitList(A);
	InitList(B);
	int length_a, length_b;
	cout << "请输入集合A的元素个数: ";
	cin >> length_a;
	CreateListNoRepeat(A, length_a);
	cout << "请输入集合B的元素个数: ";
	cin >> length_b;
	CreateListNoRepeat(B, length_b);
	cout << "集合A: ";
	DispList(A);
	cout << "集合B: ";
	DispList(B);
	Union(A, B, length_a, length_b); // You should manually pass the length of the list instead of using A.length
	cout << "A∪B: ";
	DispList(A);
	while (true) if (!DeleElem_i(A, length_a + 1)) break; // Delete elements after the original list A
	Intersection(A, B, length_a);
	cout << "A∩B: ";
	DispList(A);
	DestroyList(A);
	DestroyList(B);
	return 0;
}