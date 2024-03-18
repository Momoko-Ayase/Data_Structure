#include<iostream>     //cout,cin
using namespace std;
#include "LinkStack.h"


void dispmenu()
{//显示主菜单
	cout << endl;
	cout << "1-初始化链栈\n";
	cout << "2-元素入栈\n";
	cout << "3-元素出栈\n";
	cout << "4-取栈顶元素\n";
	cout << "5-清空栈\n";
	cout << "6-测栈空\n";
	cout << "7-显示栈元素\n";
	cout << "0-退出\n";
}

//主函数
int main()
{
	int e;
	SNode<int>* S;
	system("cls");                                       // 清屏
	int choice;
	do
	{
		dispmenu();                                         //显示主菜单
		cout << "Enter choice(1~6，0 退出):";
		cin >> choice;
		switch (choice)
		{
		case 1:                                        //初始化链栈
			InitStack(S);
			cout << endl << "创建成功！" << endl;
			break;
		case 2:                                        //入栈
			cout << "输入要入栈的元素值：" << endl;
			cin >> e;
			cout << endl;
			if (Push(S, e))
			{
				cout << endl << "入栈成功！栈中元素为：" << endl;
				DispStack(S);
			}
			else
				cout << endl << "入栈不成功！" << endl;
			break;

		case 3:                                         //出栈
			if (Pop(S, e))
			{
				cout << endl << "出栈成功！出栈元素为:" << e << endl;
				cout << "出栈后，栈中元素为" << endl;
				DispStack(S);
			}
			else
				cout << endl << "栈空，出栈失败！" << endl;
			break;

		case 4:                                       //获取栈顶元素
			if (GetTop(S, e))
			{
				cout << endl << "栈顶元素为:" << e << endl;
			}
			else
				cout << endl << "栈空！" << endl;
			break;
		case 5:									// 清空栈
			DestroyStack(S);
			cout << "栈已清空!" << endl;
			break;
		case 6:                                      //测栈空
			if (StackEmpty(S))
				cout << endl << "空栈！" << endl;
			else
				cout << endl << "不是空栈！" << endl;
			break;
		case 7:                                     //显示栈元素
			DispStack(S);
			cout << endl;
			break;
		case 0:                                     //退出
			DestroyStack(S);
			cout << "结束运行Bye-bye!" << endl;
			break;
		default:                                   //非法选择
			cout << "无效选择!\n";
			break;
		}
	} while (choice != 0);
	return 0;
}//end of main function
