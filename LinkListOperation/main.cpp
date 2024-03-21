#include <iostream>
using namespace std;
#include "LinkList.h"
template <class DT>
bool CreateOrderedList(LNode<DT>*& L, int n)
{
	int i;
	LNode<DT>* p, * s;
	p = L;
	cout << "依次输入" << n << "个数据元素：" << endl;
	for (i = 1; i <= n; i++)
	{
		s = new LNode<DT>;
		if (!s) return false;
		cin >> s->data;
		if (s->data >= p->data || p == NULL)
		{
			s->next = p->next;
			p->next = s;
			p = s;
		}
		else i--;
	}
	return true;
}
template <class DT>
void InsertElementToOrderedList(LNode<DT>*& L, int n, int length)
{
	LNode<DT>* p;
	p = L->next;
	for (int i = 1; i <= length; i++)
	{
		if ((p->data) > n)
		{
			InsertElem_i(L, i, n);
			break;
		}
		else if (p->next == NULL)
		{
			InsertElem_i(L, i + 1, n);
			break;
		}
		else p = p->next;
	}
}
template <class DT>
void MergeTwoOrderedLists(LNode<DT>*& L1, LNode<DT>*& L2)
{
	LNode<DT>* p, * q, * s;
	p = L1->next;
	q = L1->next->next;
	s = L2->next;
	while (!ListEmpty(L2))
	{
		if (q == NULL)
		{
			p->next = s;
			return;
		}
		else if ((q->data) >= (s->data) && (p->data) <= (s->data))
		{
			int n = s->data;
			LNode<DT>* t;
			t = s->next;
			s->next = q;
			p->next = s;
			s = t;
			if (s == NULL) return;
			p = p->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
}
int main()
{
	// Task 1: Create an ordered list
	LNode<int>* L;
	InitList(L);
	int length;
	cout << "请输入有序表的长度: ";
	cin >> length;
	CreateOrderedList(L, length);
	DispList(L);
	// Task 2: Insert a new element and keep the list ordered
	int n;
	cout << "请输入插入有序表的元素: ";
	cin >> n;
	InsertElementToOrderedList(L, n, length);
	DispList(L);
	// Task 3: Merge two ordered linked list
	LNode<int>* L2;
	InitList(L2);
	int length2;
	cout << "请输入另一个有序表的长度: ";
	cin >> length2;
	CreateOrderedList(L2, length2);
	DispList(L2);
	MergeTwoOrderedLists(L, L2);
	DispList(L);
	return 0;
}