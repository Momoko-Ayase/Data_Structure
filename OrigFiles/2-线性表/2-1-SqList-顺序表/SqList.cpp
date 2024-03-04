
#include <iostream>//cout,cin
using namespace std;
#include "SqList.h"

char pause;


void dispmenu() {
	//��ʾ���˵�
	cout << endl;
	cout << "***  ˳ �� ��   ***\n";
	cout << " 1-��ʼ��˳���\n";
	cout << " 2-����˳���\n";
	cout << " 3-��ȡ��i��Ԫ��\n";
	cout << " 4-��ֵ����Ԫ��λ��\n";
	cout << " 5-�����i��Ԫ��\n";
	cout << " 6-ɾ����i��Ԫ��\n";
	cout << " 7-�޸ĵ�i��Ԫ��\n";
	cout << " 8-��ձ�\n";
	cout << " 9-���\n";
	cout << " 10-����\n";
	cout << " 11-�����\n";
	cout << " 12-��ʾ��\n";
	cout << " 13-��ֵ����ǰ��\n";
	cout << " 0-�˳�\n";
}


//������
void main() {
	int i;
	int e, pre_e;
	SqList<int> L;										//��������Ϊ20��Ԫ������Ϊ���͵Ŀ�˳���
	system("cls");										//ִ��ϵͳ����cls������

	int choice;
	do {
		dispmenu();										//��ʾ���˵�
		cout << "Enter choice(1~12��0 �˳�):";
		cin >> choice;
		switch (choice) {
			case 1:										//��ʼ�����Ա�
				cout << "������Ҫ������˳���ĳ��ȣ�";
				cin >> i;
				cout << endl;
				InitList(L, i);
				cout << endl << "�����ɹ���" << endl;
				break;
			case 2:									//�������Ա�
				cout << "������Ҫ������Ԫ�ظ���:";
				cin >> i;
				cout << endl;
				CreateList(L, i);
				cout << "������˳���Ԫ��Ϊ��\n";     //��ʾ��Ԫ��
				DispList(L);
				cout << endl;
				break;
			case 3:										//��ȡ��i��Ԫ��
				cout << "������Ԫ�����:";
				cin >> i;
				cout << endl;
				if (GetElem_i(L, i, e))
					cout << endl << "��" << i << "��Ԫ��Ϊ:" << e << endl;
				else
					cout << endl << "Ԫ�ز����ڣ�" << endl;
				break;
			case 4:									//��ֵ����
				cout << "������Ҫ��ѯ��Ԫ��ֵ:";
				cin >> e;
				i = LocateElem_e(L, e);
				if (i)
					cout << endl << e << "�ǵ�" << i << "������Ԫ��" << endl;
				else
					cout << endl << "�����ڴ�Ԫ�أ�" << endl;
				break;
			case 5:									// �ڵ�i��λ�ò���Ԫ��
				cout << "�������λ�ã�" << endl;
				cin >> i;
				cout << "�������Ԫ��ֵ��" << endl;
				cin >> e;
				if (InsertElem_i(L, i, e)) {
					cout << endl << "����ɹ���" << endl;
					DispList(L);
				} else
					cout << endl << "���벻�ɹ���" << endl;;
				break;
			case 6:									//ɾ����i��Ԫ��
				cout << "����ɾ��Ԫ��λ�ã�" << endl;
				cin >> i;
				if (DeleElem_i(L, i)) {
					cout << endl << "ɾ���ɹ���" << endl;
					DispList(L);
				} else
					cout << endl << "ɾ��ʧ�ܣ�" << endl;
				break;
			case 7:									//�޸ĵ�i��Ԫ�ص�ֵ
				cout << "�����޸�Ԫ��λ�ã�" << endl;
				cin >> i;
				cout << "������Ԫ��ֵ��" << endl;
				cin >> e;
				if (PutElem(L, i,  e)) {
					cout << endl << "�޸ĳɹ���" << endl;
					DispList(L);
				} else
					cout << endl << "�޸�ʧ�ܣ�" << endl;
				break;
			case 8:									// ��ձ�
				ClearList(L);
				break;
			case 9:									// ���
				cout << "��Ϊ��" << ListLength(L) << endl;
				break;
			case 10:									//����
				if (ListEmpty(L))
					cout << endl << "�ձ�" << endl;
				else
					cout << endl << "���ǿձ�" << endl;
				break;
			case 11:									// δ����
				if (ListFull(L))
					cout << endl << "������" << endl;
				else
					cout << endl << "������" << endl;
				break;
			case 12:									//������ʾ��
				DispList(L);
				cout << endl;
				cin.get(pause);
				system("pause");
				break;
			case 13:
				cout << "����˳���Ϊ\n";
				DispList(L);
				cout << "�������ǰ����Ԫ��ֵ��\n";
				cin >> e;
				if (PriorElem_e(L, e, pre_e))
					cout << e << "��ǰ��Ԫ��Ϊ��" << pre_e << endl;
				else
					cout << e << "��ǰ��Ԫ�أ�" << endl;
				break;
			case 0:  //�˳�
			
				cout << "��������bye-bye!" << endl;
				break;
			default:									//��Чѡ��
				cout << "��Чѡ��!\n";
				break;
		}
	} while (choice != 0);
}//end of main function

