#include<iostream>     //cout,cin
using namespace std;
#include "LinkQueue.h"

void dispmenu()
{//��ʾ���˵�
	cout<<endl;
	cout<<"1-��ʼ������\n";
	cout<<"2-Ԫ�����\n";
	cout<<"3-Ԫ�س���\n";
	cout<<"4-ȡ��ͷԪ��\n";
	cout<<"5-ȡ��βԪ��\n";
	cout<<"6-��ն�\n";
	cout<<"7-��ӿ�\n";
	cout<<"8-��ʾ����Ԫ��\n";
	cout<<"0-�˳�\n";
}

char pause;

 //������
int main()
{
	int e;
	LinkQueue<int> Q;
	system("cls");											// ִ��ϵͳ����cls������

	int choice;
    do
	{
		dispmenu();											// ��ʾ���˵�
		cout<<"����ѡ��(1~8��0 �˳�):";
		cin>>choice;
		switch(choice)
		{
			case 1:											// ��ʼ������
				InitQueue(Q);
				cout<<endl<<"�����ɹ���"<<endl;
				break;
		     case 2:										//���
                cout<<"����Ҫ�����Ԫ��ֵ��"<<endl;
                cin>>e;
				cout<<endl;
				if(EnQueue(Q,e))
				{
					 cout<<endl<<"��ӳɹ�������Ԫ��Ϊ��"<<endl;
					 DispQueue(Q);
				}
                else
					 cout<<endl<<"��Ӳ��ɹ���"<<endl;
				break;

			case 3:												// ����
				if(DeQueue(Q,e))
                 {
                     cout<<endl<<"���ӳɹ�������Ԫ��Ϊ:"<<e<<endl;
                     cout<<endl<<"���Ӻ󣬶���Ԫ��Ϊ��"<<endl;
					 DispQueue(Q);
                 }
				 else
					 cout<<endl<<"�ӿգ�����ʧ�ܣ�"<<endl;
				 break;

			 case 4:											// ��ȡ��ͷԪ��
				if(GetHead(Q,e))
                 {
 					 cout<<"����Ԫ��Ϊ��"<<endl;
					 DispQueue(Q);
                     cout<<endl<<"��ͷԪ��Ϊ:"<<e<<endl;
                 }
				 else
					 cout<<endl<<"�ӿգ�"<<endl;
				 break;
             case 5:											// ��ȡ��βԪ��
				if(GetTail(Q,e))
                 {
					 cout<<"����Ԫ��Ϊ��"<<endl;
					 DispQueue(Q);
                     cout<<endl<<"��βԪ��Ϊ:"<<e<<endl;

                 }
				 else
					 cout<<endl<<"�ӿգ�"<<endl;
				 break;
			 case 6:											// ��ն�
				 ClearQueue(Q);
				 cout<<endl<<"���ѿ�!"<<endl;
			 case 7:											// ��ӿ�
                 if(QueueEmpty(Q))
					 cout<<endl<<"�նӣ�"<<endl;
				 else
					 cout<<endl<<"���ǿնӣ�"<<endl;
				 break;
			 case 8:											 // �鿴����Ԫ��
				 DispQueue(Q);
                 cout<<endl;
				 break;
  			case 0:												 // �˳�
                DestroyQueue(Q);
				cout<<"��������Bye-bye!"<<endl;
                break;
			default:											// ��Чѡ��
				cout<<"��Чѡ��!\n";
				break;
			}
	}while(choice!=0);
	return 0;
}//end of main function
