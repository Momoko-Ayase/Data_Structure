// 2-2-LinkList-������
// WARNING: /sdl is disabled to pass the compilation process.

#include<iostream>     //cout,cin
using namespace std;
#include "LinkList.h"

//�㷨2.25											����������
void ReverseLinkList(LNode<int>*& L)
{
	LNode<int>* p, * q;								// 1.���ù���ָ��
	p = L->next;										// ԭ����ͷ��㣬��Ϊ���ú���ͷ���
	L->next = NULL;
	while (p)										// 2. ����ժ��ԭ�����㣬��ͷ�巨���뵽����������
	{
		q = p;										// 2.1 qȡ��ǰ���λ��   
		p = p->next;									// 2.2 pָ����һ����������
		q->next = L->next;							// 2.3 ��q ���뵽ͷ���֮��
		L->next = q;
	}
}

void dispmenu()
{															// ��ʾ���˵�
	cout << endl;
	cout << " ***  ��  ��  ��  ***\n";
	cout << " 1-��ʼ��������\n";
	cout << " 2-β�巨˳���\n";
	cout << " 3-ͷ�巨����\n";
	cout << " 4-��ȡ��i��Ԫ��\n";
	cout << " 5-��ֵ����\n";
	cout << " 6-�����i��Ԫ��\n";
	cout << " 7-ɾ����i��Ԫ��\n";
	cout << " 8-�޸ĵ�i��Ԫ��\n";
	cout << " 9-��ձ�\n";
	cout << "10-���\n";
	cout << "11-����\n";
	cout << "12-�������\n";
	cout << "13-��ֵ����ǰ��\n";
	cout << "14-����������\n";
	cout << "0-�˳�\n";
}

char pause;

// ������
int main()
{
	int i, n;
	int e, pre_e;
	LNode<int>* L;
	system("cls");											// ����

	int choice;
	do
	{
		dispmenu();											// ��ʾ���˵�
		cout << "Enter choice(1~12��0 �˳�):";
		cin >> choice;
		switch (choice)
		{
		case 1:											// ��ʼ�������� 
			InitList(L);
			cout << endl << "�����ɹ���" << endl;
			break;
		case 2:										// β�巨��������
			cout << "β�巨����������" << endl;
			cout << "����Ҫ������˳�����Ԫ�ظ���:";
			cin >> n;
			cout << endl;
			CreateList_1(L, n);
			cout << "�����ĵ�����Ϊ��";
			DispList(L);
			cout << endl;
			break;
		case 3:											// ͷ�巨����������
			cout << "ͷ�巨����������" << endl;
			cout << "����Ҫ������˳�����Ԫ�ظ���:";
			cin >> n;
			cout << endl;
			CreateList_2(L, n);
			cout << "�����ĵ�����Ϊ��";
			DispList(L);
			cout << endl;
			break;
		case 4:										// ��ȡ��i��Ԫ��
			cout << "������Ԫ�����:";
			cin >> i;
			cout << endl;
			if (GetElem_i(L, i, e))
				cout << endl << "��" << i << "��Ԫ��Ϊ:" << e << endl;
			else
				cout << endl << "Ԫ�ز����ڣ�" << endl;
			break;
		case 5:										// ��ѯԪ��λ��
			cout << "������Ҫ��ѯ��Ԫ��ֵ:";
			cin >> e;
			i = LocateElem_e(L, e);
			if (i)
				cout << endl << e << "�ǵ�" << i << "������Ԫ��" << endl;
			else
				cout << endl << "�����ڴ�Ԫ�أ�" << endl;
			break;
		case 6:										// �����i��Ԫ��
			cout << "�������λ�ã�" << endl;
			cin >> i;
			cout << "�������Ԫ��ֵ��" << endl;
			cin >> e;
			if (InsertElem_i(L, i, e))
			{
				cout << endl << "����ɹ���" << endl;
				cout << "����Ԫ�غ�ĵ�����Ϊ��" << endl;
				DispList(L);
			}
			else
				cout << endl << "���벻�ɹ���" << endl;
			break;
		case 7:										// ɾ����i��Ԫ��
			cout << "����ɾ��Ԫ��λ�ã�" << endl;
			cin >> i;
			if (DeleElem_i(L, i))
			{
				cout << endl << "ɾ���ɹ���" << endl;
				cout << "ɾ��Ԫ�غ�ĵ�����Ϊ��" << endl;
				DispList(L);
			}
			else
				cout << endl << "ɾ��ʧ�ܣ�" << endl;
			break;
		case 8:										// �޸ĵ�i��Ԫ��
			cout << "�����޸�Ԫ��λ�ã�" << endl;
			cin >> i;
			cout << "������Ԫ��ֵ��" << endl;
			cin >> e;
			if (PutElem_i(L, i, e))
			{
				cout << endl << "�޸ĳɹ���" << endl;
				cout << "�޸ĺ�ĵ�����Ϊ��" << endl;
				DispList(L);
			}
			else
				cout << endl << "�޸�ʧ�ܣ�" << endl;
			break;
		case 9:										// ��ձ�
			ClearList(L);
			break;
		case 10:										// ���
			cout << "��Ϊ��" << ListLength(L) << endl;
			break;
		case 11:										// ����
			if (ListEmpty(L))
				cout << endl << "�ձ�" << endl;
			else
				cout << endl << "���ǿձ�" << endl;
			break;
		case 12:										//������ʾ��
			DispList(L);
			cout << endl;
			break;
		case 13:
			cout << "��������Ϊ\n";
			DispList(L);
			cout << "�������ǰ����Ԫ��ֵ��\n";
			cin >> e;
			if (PriorElem_e(L, e, pre_e))
				cout << e << "��ǰ��Ԫ��Ϊ��" << pre_e << endl;
			else
				cout << e << "��ǰ��Ԫ�أ�" << endl;
			break;
		case 14:									// ���õ�����
			cout << "����ǰ�ĵ�����Ϊ��";
			DispList(L);
			ReverseLinkList(L);
			cout << "���ú�ĵ�����Ϊ��";
			DispList(L);
			cout << endl;
			break;
		case 0:										//�˳�����������
			DestroyList(L);
			cout << "��������bye-bye!" << endl;
			break;
		default:										//��Чѡ��
			cout << "��Чѡ��!\n";
			break;
		}
	} while (choice != 0);
	return 0;
}//end of main function