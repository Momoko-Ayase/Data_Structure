// 2-2-LinkList-单链表
// WARNING: /sdl is disabled to pass the compilation process.

#include<iostream>     //cout,cin
using namespace std;
#include "LinkList.h"

//算法2.25											单链表逆置
void ReverseLinkList(LNode<int>*& L)
{
	LNode<int>* p, * q;								// 1.设置工作指针
	p = L->next;										// 原链表头结点，作为逆置后表的头结点
	L->next = NULL;
	while (p)										// 2. 依次摘除原链表结点，以头插法插入到逆置链表中
	{
		q = p;										// 2.1 q取当前结点位置   
		p = p->next;									// 2.2 p指向下一个待处理结点
		q->next = L->next;							// 2.3 将q 插入到头结点之后
		L->next = q;
	}
}

void dispmenu()
{															// 显示主菜单
	cout << endl;
	cout << " ***  单  链  表  ***\n";
	cout << " 1-初始化单链表\n";
	cout << " 2-尾插法顺序表\n";
	cout << " 3-头插法建表\n";
	cout << " 4-获取第i个元素\n";
	cout << " 5-按值查找\n";
	cout << " 6-插入第i个元素\n";
	cout << " 7-删除第i个元素\n";
	cout << " 8-修改第i个元素\n";
	cout << " 9-清空表\n";
	cout << "10-测表长\n";
	cout << "11-测表空\n";
	cout << "12-遍历输出\n";
	cout << "13-按值查找前驱\n";
	cout << "14-单链表逆置\n";
	cout << "0-退出\n";
}

char pause;

// 主函数
int main()
{
	int i, n;
	int e, pre_e;
	LNode<int>* L;
	system("cls");											// 清屏

	int choice;
	do
	{
		dispmenu();											// 显示主菜单
		cout << "Enter choice(1~12，0 退出):";
		cin >> choice;
		switch (choice)
		{
		case 1:											// 初始化单链表 
			InitList(L);
			cout << endl << "创建成功！" << endl;
			break;
		case 2:										// 尾插法建单链表
			cout << "尾插法创建单链表" << endl;
			cout << "输入要创建的顺序表中元素个数:";
			cin >> n;
			cout << endl;
			CreateList_1(L, n);
			cout << "创建的单链表为：";
			DispList(L);
			cout << endl;
			break;
		case 3:											// 头插法创建单链表
			cout << "头插法创建单链表" << endl;
			cout << "输入要创建的顺序表中元素个数:";
			cin >> n;
			cout << endl;
			CreateList_2(L, n);
			cout << "创建的单链表为：";
			DispList(L);
			cout << endl;
			break;
		case 4:										// 获取第i个元素
			cout << "请输入元素序号:";
			cin >> i;
			cout << endl;
			if (GetElem_i(L, i, e))
				cout << endl << "第" << i << "个元素为:" << e << endl;
			else
				cout << endl << "元素不存在！" << endl;
			break;
		case 5:										// 查询元素位序
			cout << "请输入要查询的元素值:";
			cin >> e;
			i = LocateElem_e(L, e);
			if (i)
				cout << endl << e << "是第" << i << "个数据元素" << endl;
			else
				cout << endl << "不存在此元素！" << endl;
			break;
		case 6:										// 插入第i个元素
			cout << "输入插入位置：" << endl;
			cin >> i;
			cout << "输入插入元素值：" << endl;
			cin >> e;
			if (InsertElem_i(L, i, e))
			{
				cout << endl << "插入成功！" << endl;
				cout << "插入元素后的单链表为：" << endl;
				DispList(L);
			}
			else
				cout << endl << "插入不成功！" << endl;
			break;
		case 7:										// 删除第i个元素
			cout << "输入删除元素位置：" << endl;
			cin >> i;
			if (DeleElem_i(L, i))
			{
				cout << endl << "删除成功！" << endl;
				cout << "删除元素后的单链表为：" << endl;
				DispList(L);
			}
			else
				cout << endl << "删除失败！" << endl;
			break;
		case 8:										// 修改第i个元素
			cout << "输入修改元素位置：" << endl;
			cin >> i;
			cout << "输入新元素值：" << endl;
			cin >> e;
			if (PutElem_i(L, i, e))
			{
				cout << endl << "修改成功！" << endl;
				cout << "修改后的单链表为：" << endl;
				DispList(L);
			}
			else
				cout << endl << "修改失败！" << endl;
			break;
		case 9:										// 清空表
			ClearList(L);
			break;
		case 10:										// 测表长
			cout << "表长为：" << ListLength(L) << endl;
			break;
		case 11:										// 测表空
			if (ListEmpty(L))
				cout << endl << "空表！" << endl;
			else
				cout << endl << "不是空表！" << endl;
			break;
		case 12:										//遍历显示表
			DispList(L);
			cout << endl;
			break;
		case 13:
			cout << "测试链表为\n";
			DispList(L);
			cout << "输入查找前驱的元素值：\n";
			cin >> e;
			if (PriorElem_e(L, e, pre_e))
				cout << e << "的前驱元素为：" << pre_e << endl;
			else
				cout << e << "无前驱元素！" << endl;
			break;
		case 14:									// 逆置单链表
			cout << "逆置前的单链表为：";
			DispList(L);
			ReverseLinkList(L);
			cout << "逆置后的单链表为：";
			DispList(L);
			cout << endl;
			break;
		case 0:										//退出，销毁链表
			DestroyList(L);
			cout << "结束运行bye-bye!" << endl;
			break;
		default:										//无效选择
			cout << "无效选择!\n";
			break;
		}
	} while (choice != 0);
	return 0;
}//end of main function