#include<iostream>     //cout,cin
using namespace std;
#include "LinkStack.h"


void dispmenu()
{//��ʾ���˵�
	cout<<endl;
	cout<<"1-��ʼ����ջ\n";
	cout<<"2-Ԫ����ջ\n";
	cout<<"3-Ԫ�س�ջ\n";
	cout<<"4-ȡջ��Ԫ��\n";
    cout<<"5-���ջ\n";
	cout<<"6-��ջ��\n";
	cout<<"7-��ʾջԪ��\n";
	cout<<"0-�˳�\n";
}

 //������
int main()
{
	int e;
	SNode<int> * S;
	system("cls");                                       // ����
	int choice;
    do
	{
		dispmenu();                                         //��ʾ���˵�
		cout<<"Enter choice(1~6��0 �˳�):";
		cin>>choice;
		switch(choice)
		{
			case 1:                                        //��ʼ����ջ
				InitStack(S);
				cout<<endl<<"�����ɹ���"<<endl;
				break;
		     case 2:                                        //��ջ
                cout<<"����Ҫ��ջ��Ԫ��ֵ��"<<endl;
                cin>>e;
				cout<<endl;
				if(Push(S,e))
				{
					 cout<<endl<<"��ջ�ɹ���ջ��Ԫ��Ϊ��"<<endl;
					 DispStack(S);
				}
                else
					 cout<<endl<<"��ջ���ɹ���"<<endl;
				break;

			case 3:                                         //��ջ
				if(Pop(S,e))
                 {
                     cout<<endl<<"��ջ�ɹ�����ջԪ��Ϊ:"<<e<<endl;
					 cout<<"��ջ��ջ��Ԫ��Ϊ"<<endl;
					 DispStack(S);
                 }
				 else
					 cout<<endl<<"ջ�գ���ջʧ�ܣ�"<<endl;
				 break;

			 case 4:                                       //��ȡջ��Ԫ��
				if(GetTop(S,e))
                 {
                     cout<<endl<<"ջ��Ԫ��Ϊ:"<<e<<endl;
                 }
				 else
					 cout<<endl<<"ջ�գ�"<<endl;
				 break;
			 case 5:									// ���ջ
				 DestroyStack(S);
				 cout<<"ջ�����!"<<endl;
				 break;
			 case 6:                                      //��ջ��
                 if(StackEmpty(S))
					 cout<<endl<<"��ջ��"<<endl;
				 else
					 cout<<endl<<"���ǿ�ջ��"<<endl;
				 break;
			 case 7:                                     //��ʾջԪ��
				 DispStack(S);
                 cout<<endl;
				 break;
  			case 0:                                     //�˳�
                DestroyStack(S);
				cout<<"��������Bye-bye!"<<endl;
                break;
			default:                                   //�Ƿ�ѡ��
				cout<<"��Чѡ��!\n";
				break;
			}
	}while(choice!=0);
	return 0;
}//end of main function
