#include<iostream>     //cout,cin
using namespace std;
#include "LinkQueue.h"

void dispmenu()
{//显示主菜单
	cout<<endl;
	cout<<"1-初始化链队\n";
	cout<<"2-元素入队\n";
	cout<<"3-元素出队\n";
	cout<<"4-取队头元素\n";
	cout<<"5-取队尾元素\n";
	cout<<"6-清空队\n";
	cout<<"7-测队空\n";
	cout<<"8-显示队列元素\n";
	cout<<"0-退出\n";
}

char pause;

 //主函数
int main()
{
	int e;
	LinkQueue<int> Q;
	system("cls");											// 执行系统命令cls，清屏

	int choice;
    do
	{
		dispmenu();											// 显示主菜单
		cout<<"功能选择(1~8，0 退出):";
		cin>>choice;
		switch(choice)
		{
			case 1:											// 初始化链队
				InitQueue(Q);
				cout<<endl<<"创建成功！"<<endl;
				break;
		     case 2:										//入队
                cout<<"输入要插入的元素值："<<endl;
                cin>>e;
				cout<<endl;
				if(EnQueue(Q,e))
				{
					 cout<<endl<<"入队成功！队列元素为："<<endl;
					 DispQueue(Q);
				}
                else
					 cout<<endl<<"入队不成功！"<<endl;
				break;

			case 3:												// 出队
				if(DeQueue(Q,e))
                 {
                     cout<<endl<<"出队成功！出队元素为:"<<e<<endl;
                     cout<<endl<<"出队后，队列元素为："<<endl;
					 DispQueue(Q);
                 }
				 else
					 cout<<endl<<"队空，出队失败！"<<endl;
				 break;

			 case 4:											// 获取队头元素
				if(GetHead(Q,e))
                 {
 					 cout<<"队列元素为："<<endl;
					 DispQueue(Q);
                     cout<<endl<<"队头元素为:"<<e<<endl;
                 }
				 else
					 cout<<endl<<"队空！"<<endl;
				 break;
             case 5:											// 获取队尾元素
				if(GetTail(Q,e))
                 {
					 cout<<"队列元素为："<<endl;
					 DispQueue(Q);
                     cout<<endl<<"队尾元素为:"<<e<<endl;

                 }
				 else
					 cout<<endl<<"队空！"<<endl;
				 break;
			 case 6:											// 清空队
				 ClearQueue(Q);
				 cout<<endl<<"队已空!"<<endl;
			 case 7:											// 测队空
                 if(QueueEmpty(Q))
					 cout<<endl<<"空队！"<<endl;
				 else
					 cout<<endl<<"不是空队！"<<endl;
				 break;
			 case 8:											 // 查看队列元素
				 DispQueue(Q);
                 cout<<endl;
				 break;
  			case 0:												 // 退出
                DestroyQueue(Q);
				cout<<"结束运行Bye-bye!"<<endl;
                break;
			default:											// 无效选择
				cout<<"无效选择!\n";
				break;
			}
	}while(choice!=0);
	return 0;
}//end of main function
