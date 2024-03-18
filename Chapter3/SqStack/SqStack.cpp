
#include<iostream>//cout,cin
using namespace std;
#include "SqStack.h"

char pause;


void dispmenu()
{																		//显示主菜单
	cout << endl;
	cout << "1-初始化顺序栈\n";
	cout << "2-元素入栈\n";
	cout << "3-元素出栈\n";
	cout << "4-取栈顶元素\n";
	cout << "5-清空栈\n";
	cout << "6-测栈空\n";
	cout << "7-测栈满\n";
	cout << "8-显示栈元素\n";
	cout << "9-查看栈顶指针\n";
	cout << "0-退出\n";
}


//主函数
int main()
{
	int i;
	int e;
	SqStack<int> S;//建立容量为20、元素类型为整型的空顺序栈
	system("cls");														// 清屏

	int choice;
	do
	{
		dispmenu();														// 显示主菜单
		cout << "Enter choice(1~6，0 退出):";
		cin >> choice;
		switch (choice)
		{
		case 1:														// 初始化顺序栈
			cout << "请输入要创建的顺序栈的长度";
			cin >> i;
			cout << endl;
			InitStack(S, i);
			cout << endl << "创建成功！" << endl;
			break;
		case 2:													// 入栈
			cout << "输入要入栈的元素值：" << endl;
			cin >> e;
			if (Push(S, e))
			{
				cout << "入栈成功！入栈后栈元素为：" << endl;
				DispStack(S);
			}
			else
				cout << endl << "栈满，不能入栈！" << endl;
			break;
		case 3:														// 出栈
			if (Pop(S, e))
			{
				cout << "出栈成功！出栈元素为:" << e << endl;
				cout << "出栈后栈元素为：" << endl;
				DispStack(S);
			}
			else
				cout << endl << "栈空，出栈失败！" << endl;
			break;
		case 4:													// 取栈顶元素
			if (GetTop(S, e))
			{
				cout << endl << "栈顶元素为:" << e << endl;
			}
			else
				cout << endl << "栈空！" << endl;
			break;
		case 5:													// 清空栈
			ClearStack(S);
			cout << endl << "栈已空！" << endl;
			break;
		case 6:													// 测栈空
			if (StackEmpty(S))
				cout << endl << "空栈！" << endl;
			else
				cout << endl << "不是空栈！" << endl;
			break;
		case 7:													// 测栈满
			if (StackFull(S))
				cout << endl << "栈满！" << endl;
			else
				cout << endl << "栈不满！" << endl;
			break;
		case 8:													// 显示栈元素
			DispStack(S);
			cout << endl;
			break;
		case 9:													// 显示栈顶指针
			cout << "栈顶指针top= " << S.top << endl;
			cout << endl;
			break;
		case 0:														// 退出
			DestroyStack(S);
			cout << "结束运行 Bye-bye!" << endl;
			break;
		default:													// 无效选择
			cout << "无效选择!\n";
			break;
		}
	} while (choice != 0);

	return 0;
}//end of main function

