// 2-4-PolyAdd-稀疏多项式求和
// WARNING: /sdl is disabled to pass the compilation process.

#include<iostream>//cout,cin
using namespace std;

struct PolyNode											// 多项式结点
{
	float coef;											// 系数
	int exp;											// 指数
	PolyNode* next;										// 指向下一项结点
};

void InitPoly(PolyNode*& L)
{ //创建一空多项式
	L = new PolyNode;
	L->next = NULL;
}

bool CreatePoly(PolyNode*& L, int n)                   // 尾插法创建n项多项式
{
	int i;
	PolyNode* p, * s;
	p = L;
	for (i = 1; i <= n; i++)                           // 按幂升序依次输入多项式各项系数与幂指数
	{
		s = new PolyNode;
		if (!s)
			return false;
		cout << "输入第" << i << "项系数和幂指数：";
		cin >> s->coef >> s->exp;
		s->next = p->next;
		p->next = s;
		p = s;
	}
	return true;
}


//显示多顶式
void DispPoly(PolyNode* L)								// 通过遍历结点，输出多项式
{
	PolyNode* p;
	if (!L)  // 空表，返回
	{
		cout << "空表!";
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

//【算法2.26】											求多项式LA=LA+LB
void PolyAdd(PolyNode*& LA, PolyNode*& LB)
{
	float sum;
	PolyNode* pa, * pb, * qa, * qb;							// 1.工作指针初始化
	pa = LA;
	qa = pa->next;
	pb = LB;
	qb = pb->next;
	while (qa != NULL && qb != NULL)						// 2. 两表均不空
	{
		if (qa->exp < qb->exp)							// 2.1 LA的幂小
		{												// pa、qa后移
			pa = qa; qa = qa->next;
		}
		else if (qa->exp > qb->exp)					//2.2 LA 幂大
		{
			pb->next = qb->next;							// qb链接到pa之后
			qb->next = qa;
			pa->next = qb;
			pa = qb;
			qb = pb->next;
		}
		else												// 2.3 LA与LB幂相同
		{
			sum = qa->coef + qb->coef;						// 计算系数和
			if (sum != 0)									// 2.3.1 系数和不为0
			{
				qa->coef = sum;							// 2.3.1.1 qa->coef←sum
				pa = qa; qa = qa->next;						// 2.3.1.2 pa，qa后移
				pb->next = qb->next;
				delete qb;								// 2.3.1.3删除qb，
				qb = pb->next;
			}
			else										// 2.3.2 系数和为0
			{
				pa->next = qa->next;
				delete qa;								// 2.3.2.1 删除qa，
				qa = pa->next;								// 2.3.2.2 qa为pa后继；
				pb->next = qb->next;
				delete qb;								// 2.3.2.3 删除qb
				qb = pb->next;								// 2.3.2.4 qb为pb的后继
			}
		}
	}//while
	if (qb != NULL)											// 3. LA处理结束，LB未结束
		pa->next = qb;										// 3.1 qb链到qa之后
	delete pb;											// 3.2 删除lb头结点
	LB = NULL;

}//Add


void DestroyPoly(PolyNode*& L)							// 释放链表所占空间
{
	PolyNode* p;
	while (L)											// 从头结点开始，依次释放结点
	{
		p = L;
		L = L->next;
		delete p;
	}
	L = NULL;												// 头结点指向空
}

void SortPoly(PolyNode*& L)						// 将多项式按幂升序排序
{
	PolyNode* p1, * p2, * q, * r;					// 采用插入排序算法
	p1 = L; p2 = p1->next;						// p1是p2的前驱
	if (p2 == NULL || p2->next == NULL)		// 空表或只有1项的多项式，不需要排序
	{
		cout << "不需要排序!" << endl;
		return;
	}
	r = L->next;								// 有序表表尾
	q = r->next;								// q为当前处理项，有序表的后一项
	while (q)								// 未处理完
	{										// 从首元结点开始查找插入点
		p1 = L; p2 = p1->next;
		while (q->exp > p2->exp && p2 != q)    // 当前结点幂大，插入点后移
		{
			p1 = p2; p2 = p2->next;
		}
		if (p2 == q)					// 当前项无需移动
		{
			r = q;					// 有序表表尾顺移
		}
		else						// q插入到p2前面
		{
			r->next = q->next;		// 摘除q结点
			q->next = p1->next;				// 在p1后插入结点q	
			p1->next = q;
		}
		q = r->next;				// 下一个需处理的项

	}
	return;
}



void dispmenu()
{//显示主菜单
	cout << endl;
	cout << "*** 稀疏多项式求和 ***\n";
	cout << "1-创建多项式A\n";
	cout << "2-创建多项式B\n";
	cout << "3-多项式求和A=A+B\n";
	cout << "4-显示多项式\n";
	cout << "0-退出\n";
}

//主函数
int main()
{
	int m, n;
	char c;
	PolyNode* LA, * LB;
	system("cls");											// 执行系统命令cls，清屏

	int choice;
	do
	{
		dispmenu();											// 显示主菜单
		cout << "Enter choice(1~4,0 退出):";
		cin >> choice;
		switch (choice)
		{
		case 1:											// 创建多项式A
			InitPoly(LA);
			cout << "请输入多项式 A 的项数： ";
			cin >> m;
			CreatePoly(LA, m);
			cout << "创建的多项式 A 为：" << endl;
			DispPoly(LA);
			SortPoly(LA);
			cout << "排序后多项式 A 为：" << endl;
			DispPoly(LA);
			break;
		case 2:											// 创建多项式B
			InitPoly(LB);
			cout << "请输入多项式B的项数： ";
			cin >> n;
			CreatePoly(LB, n);
			cout << "创建的多项式B为：" << endl;
			DispPoly(LB);
			SortPoly(LB);
			cout << "排序后多项式 B 为：" << endl;
			DispPoly(LB);
			break;
		case 3:											//多项式求和
			cout << "A = ";
			DispPoly(LA);
			cout << "B = ";
			DispPoly(LB);
			PolyAdd(LA, LB);								// 求多项式 LA=LA+LB
			cout << "A + B = ";			// 显示结果
			DispPoly(LA);
			cout << endl;
			break;
		case 4:											// 显示多项式
			cout << "选择要显示的多项式 A 或 B：" << endl;
			cin >> c;
			if (c == 'A' || c == 'a')
				DispPoly(LA);
			else if (c == 'B' || c == 'b')
				DispPoly(LB);
			else
				cout << "选择错误！" << endl;
			break;
		case 5:											//退出
			DestroyPoly(LA);
			DestroyPoly(LB);
			cout << "结束运行bye-bye!" << endl;
			break;
		default:										//非法选择
			cout << "非法选择!\n";
			break;
		}
	} while (choice != 0);

	return 0;
}//end of main function
