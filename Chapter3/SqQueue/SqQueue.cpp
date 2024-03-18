
#include<iostream>//cout,cin
using namespace std;
#include "SqQueue.h"

char pause;


void dispmenu()						//菜单
{
	cout << endl;
	cout << "1-初始化顺序队列\n";
	cout << "2-元素入队\n";
	cout << "3-元素出队\n";
	cout << "4-取队头元素\n";
	cout << "5-取队尾元素\n";
	cout << "6-清空队\n";
	cout << "7-测队空\n";
	cout << "8-测队满\n";
	cout << "9-显示队列元素\n";
	cout << "10-显示队头、队尾指针\n";
	cout << "0-退出\n";
}


//主函数
int main()
{
	int i;
	int e;
	SqQueue<int> Q;									// 元素类型为整型的顺序队列
	system("cls");									// 清屏
	int choice;
	do
	{
		dispmenu();									//显示主菜单
		cout << "功能选择(1~10，0 退出！):";
		cin >> choice;
		switch (choice)
		{
		case 1:											// 初始化顺序队列
			cout << "请输入要创建的顺序队列的长度";
			cin >> i;
			cout << endl;
			InitQueue(Q, i);
			cout << endl << "创建成功！" << endl;
			break;
		case 2:										// 入队
			cout << "输入要入队的元素值：" << endl;
			cin >> e;
			cout << endl;
			if (EnQueue(Q, e))
			{
				cout << endl << "入队成功！入队后队列元素为：" << endl;
				DispQueue(Q);
			}
			else
				cout << endl << "队满，不能入队！" << endl;
			break;
		case 3:											// 出队
			if (DeQueue(Q, e))
			{
				cout << endl << "队列元素为：";
				DispQueue(Q);
				cout << endl << "出队元素为:" << e << endl;
			}
			else
				cout << endl << "队空，不能出队！" << endl;
			break;
		case 4:										// 取队头元素
			if (GetHead(Q, e))
			{
				cout << endl << "队列元素为：";
				DispQueue(Q);
				cout << endl << "队头元素为:" << e << endl;
			}
			else
				cout << endl << "队空！" << endl;
			break;
		case 5:										// 取队尾元素
			if (GetTail(Q, e))
			{
				cout << endl << "队列元素为：";
				DispQueue(Q);
				cout << endl << "队尾元素为:" << e << endl;
			}
			else
				cout << endl << "队空！无数据元素" << endl;
			break;
		case 6:								// 清空队
			ClearQueue(Q);
			cout << "队已清空!" << endl;
			break;
		case 7:										// 测队空
			if (QueueEmpty(Q))
				cout << endl << "空队！" << endl;
			else
				cout << endl << "非空队！" << endl;
			break;
		case 8:										// 测队满
			if (QueueFull(Q))
				cout << endl << "满队！" << endl;
			else
				cout << endl << "非满队！" << endl;
			break;
		case 9:										// 显示队列元素
			DispQueue(Q);
			cout << endl;
			break;
		case 10:
			cout << "\nQ.fornt=" << Q.front << endl;
			cout << "Q.rear=" << Q.rear << endl;
			break;
		case 0:											// 退出
			DestroyQueue(Q);
			cout << "结束运行Bye-bye!" << endl;
			break;
		default:										// 无效选择
			cout << "无效选择!\n";
			break;
		}
	} while (choice != 0);

	return 0;
}//end of main function

