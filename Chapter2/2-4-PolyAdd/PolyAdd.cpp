// 2-4-PolyAdd-ϡ�����ʽ���
// WARNING: /sdl is disabled to pass the compilation process.

#include<iostream>//cout,cin
using namespace std;

struct PolyNode											// ����ʽ���
{
	float coef;											// ϵ��
	int exp;											// ָ��
	PolyNode* next;										// ָ����һ����
};

void InitPoly(PolyNode*& L)
{ //����һ�ն���ʽ
	L = new PolyNode;
	L->next = NULL;
}

bool CreatePoly(PolyNode*& L, int n)                   // β�巨����n�����ʽ
{
	int i;
	PolyNode* p, * s;
	p = L;
	for (i = 1; i <= n; i++)                           // �������������������ʽ����ϵ������ָ��
	{
		s = new PolyNode;
		if (!s)
			return false;
		cout << "�����" << i << "��ϵ������ָ����";
		cin >> s->coef >> s->exp;
		s->next = p->next;
		p->next = s;
		p = s;
	}
	return true;
}


//��ʾ�ඥʽ
void DispPoly(PolyNode* L)								// ͨ��������㣬�������ʽ
{
	PolyNode* p;
	if (!L)  // �ձ�����
	{
		cout << "�ձ�!";
		return;
	}
	p = L->next;
	while (p && p->next)
	{
		cout << p->coef << "x^" << p->exp << " + ";
		p = p->next;
	}
	cout << p->coef << "x^" << p->exp;
	cout << endl;
}

//���㷨2.26��											�����ʽLA=LA+LB
void PolyAdd(PolyNode*& LA, PolyNode*& LB)
{
	float sum;
	PolyNode* pa, * pb, * qa, * qb;							// 1.����ָ���ʼ��
	pa = LA;
	qa = pa->next;
	pb = LB;
	qb = pb->next;
	while (qa != NULL && qb != NULL)						// 2. ���������
	{
		if (qa->exp < qb->exp)							// 2.1 LA����С
		{												// pa��qa����
			pa = qa; qa = qa->next;
		}
		else if (qa->exp > qb->exp)					//2.2 LA �ݴ�
		{
			pb->next = qb->next;							// qb���ӵ�pa֮��
			qb->next = qa;
			pa->next = qb;
			pa = qb;
			qb = pb->next;
		}
		else												// 2.3 LA��LB����ͬ
		{
			sum = qa->coef + qb->coef;						// ����ϵ����
			if (sum != 0)									// 2.3.1 ϵ���Ͳ�Ϊ0
			{
				qa->coef = sum;							// 2.3.1.1 qa->coef��sum
				pa = qa; qa = qa->next;						// 2.3.1.2 pa��qa����
				pb->next = qb->next;
				delete qb;								// 2.3.1.3ɾ��qb��
				qb = pb->next;
			}
			else										// 2.3.2 ϵ����Ϊ0
			{
				pa->next = qa->next;
				delete qa;								// 2.3.2.1 ɾ��qa��
				qa = pa->next;								// 2.3.2.2 qaΪpa��̣�
				pb->next = qb->next;
				delete qb;								// 2.3.2.3 ɾ��qb
				qb = pb->next;								// 2.3.2.4 qbΪpb�ĺ��
			}
		}
	}//while
	if (qb != NULL)											// 3. LA���������LBδ����
		pa->next = qb;										// 3.1 qb����qa֮��
	delete pb;											// 3.2 ɾ��lbͷ���
	LB = NULL;

}//Add


void DestroyPoly(PolyNode*& L)							// �ͷ�������ռ�ռ�
{
	PolyNode* p;
	while (L)											// ��ͷ��㿪ʼ�������ͷŽ��
	{
		p = L;
		L = L->next;
		delete p;
	}
	L = NULL;												// ͷ���ָ���
}

void SortPoly(PolyNode*& L)						// ������ʽ������������
{
	PolyNode* p1, * p2, * q, * r;					// ���ò��������㷨
	p1 = L; p2 = p1->next;						// p1��p2��ǰ��
	if (p2 == NULL || p2->next == NULL)		// �ձ��ֻ��1��Ķ���ʽ������Ҫ����
	{
		cout << "����Ҫ����!" << endl;
		return;
	}
	r = L->next;								// ������β
	q = r->next;								// qΪ��ǰ����������ĺ�һ��
	while (q)								// δ������
	{										// ����Ԫ��㿪ʼ���Ҳ����
		p1 = L; p2 = p1->next;
		while (q->exp > p2->exp && p2 != q)    // ��ǰ����ݴ󣬲�������
		{
			p1 = p2; p2 = p2->next;
		}
		if (p2 == q)					// ��ǰ�������ƶ�
		{
			r = q;					// ������β˳��
		}
		else						// q���뵽p2ǰ��
		{
			r->next = q->next;		// ժ��q���
			q->next = p1->next;				// ��p1�������q	
			p1->next = q;
		}
		q = r->next;				// ��һ���账�����

	}
	return;
}



void dispmenu()
{//��ʾ���˵�
	cout << endl;
	cout << "*** ϡ�����ʽ��� ***\n";
	cout << "1-��������ʽA\n";
	cout << "2-��������ʽB\n";
	cout << "3-����ʽ���A=A+B\n";
	cout << "4-��ʾ����ʽ\n";
	cout << "0-�˳�\n";
}

//������
int main()
{
	int m, n;
	char c;
	PolyNode* LA, * LB;
	system("cls");											// ִ��ϵͳ����cls������

	int choice;
	do
	{
		dispmenu();											// ��ʾ���˵�
		cout << "Enter choice(1~4,0 �˳�):";
		cin >> choice;
		switch (choice)
		{
		case 1:											// ��������ʽA
			InitPoly(LA);
			cout << "���������ʽ A �������� ";
			cin >> m;
			CreatePoly(LA, m);
			cout << "�����Ķ���ʽ A Ϊ��" << endl;
			DispPoly(LA);
			SortPoly(LA);
			cout << "��������ʽ A Ϊ��" << endl;
			DispPoly(LA);
			break;
		case 2:											// ��������ʽB
			InitPoly(LB);
			cout << "���������ʽB�������� ";
			cin >> n;
			CreatePoly(LB, n);
			cout << "�����Ķ���ʽBΪ��" << endl;
			DispPoly(LB);
			SortPoly(LB);
			cout << "��������ʽ B Ϊ��" << endl;
			DispPoly(LB);
			break;
		case 3:											//����ʽ���
			cout << "A = ";
			DispPoly(LA);
			cout << "B = ";
			DispPoly(LB);
			PolyAdd(LA, LB);								// �����ʽ LA=LA+LB
			cout << "A + B = ";			// ��ʾ���
			DispPoly(LA);
			cout << endl;
			break;
		case 4:											// ��ʾ����ʽ
			cout << "ѡ��Ҫ��ʾ�Ķ���ʽ A �� B��" << endl;
			cin >> c;
			if (c == 'A' || c == 'a')
				DispPoly(LA);
			else if (c == 'B' || c == 'b')
				DispPoly(LB);
			else
				cout << "ѡ�����" << endl;
			break;
		case 5:											//�˳�
			DestroyPoly(LA);
			DestroyPoly(LB);
			cout << "��������bye-bye!" << endl;
			break;
		default:										//�Ƿ�ѡ��
			cout << "�Ƿ�ѡ��!\n";
			break;
		}
	} while (choice != 0);

	return 0;
}//end of main function
