#include <iostream>
using namespace std;
#include "SqList.h"
template <class DT>
bool CreateListNoRepeat(SqList<DT>& L, int n)
{
	int i;
	if (n > L.size)
	{
		cout << "Ԫ�ظ������ڱ������ܴ�����" << endl;
		return false;
	}
	cout << "����������" << n << "��Ԫ��ֵ��" << endl;
	for (i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		if (LocateElem_e(L, temp) > 0) i--;
		else L.elem[i - 1] = temp;
		L.length++;
	}
	L.length = n;
	return true;
}
template <class DT>
void Union(SqList<DT>& A, const SqList<DT>& B)
{
	for (int i = 0; i < B.length; ++i)
	{
		if (LocateElem_e(A, B.elem[i]) == 0)
		{
			InsertElem_i(A, A.length + 1, B.elem[i]);
		}
	}
}
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
	cout << "�����뼯��A��Ԫ�ظ���: ";
	cin >> length_a;
	CreateListNoRepeat(A, length_a);
	cout << "�����뼯��B��Ԫ�ظ���: ";
	cin >> length_b;
	CreateListNoRepeat(B, length_b);
	cout << "����A: ";
	DispList(A);
	cout << "����B: ";
	DispList(B);
	Union(A, B);
	cout << "A��B: ";
	DispList(A);
	A.length = length_a; // Reset A to its original length
	Intersection(A, B);
	cout << "A��B: ";
	DispList(A);
	DestroyList(A);
	DestroyList(B);
	return 0;
}