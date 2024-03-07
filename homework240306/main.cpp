#include <iostream>
using namespace std;
#include "SqList.h"
template <class DT>
void Intersection(SqList<DT>& A, const SqList<DT>& B)
{
	int k = 0;
	for (int i = 0; i < A.length; ++i)
	{
		if (LocateElem_e(B, A.elem[i]) > 0)
		{
			A.elem[k++] = A.elem[i];
		}
	}
	A.length = k;
}
int main()
{
	SqList<int> A;
	SqList<int> B;
	InitList(A, 32);
	InitList(B, 32);
	int length_a, length_b;
	cout << "请输入集合A的元素个数: ";
	cin >> length_a;
	CreateList(A, length_a);
	cout << "请输入集合B的元素个数: ";
	cin >> length_b;
	CreateList(B, length_b);
	cout << "集合A: ";
	DispList(A);
	cout << "集合B: ";
	DispList(B);
	Intersection(A, B);
	cout << "A∩B: ";
	DispList(A);
	DestroyList(A);
	DestroyList(B);
	return 0;
}