
#include<iostream>//cout,cin
using namespace std;
#include "SqQueue.h"

char pause;


void dispmenu()						//�˵�
{
	cout<<endl;
	cout<<"1-��ʼ��˳�����\n";
	cout<<"2-Ԫ�����\n";
	cout<<"3-Ԫ�س���\n";
	cout<<"4-ȡ��ͷԪ��\n";
	cout<<"5-ȡ��βԪ��\n";
	cout<<"6-��ն�\n";
	cout<<"7-��ӿ�\n";
	cout<<"8-�����\n";
	cout<<"9-��ʾ����Ԫ��\n";
	cout<<"10-��ʾ��ͷ����βָ��\n";
	cout<<"0-�˳�\n";
}


 //������
int main()
{
	int i;
	int e;
	SqQueue<int> Q;									// Ԫ������Ϊ���͵�˳�����
	system("cls");									// ����
	int choice;
    do
	{
		dispmenu();									//��ʾ���˵�
		cout<<"����ѡ��(1~10��0 �˳���):";
		cin>>choice;
		switch(choice)
		{
			case 1:											// ��ʼ��˳�����
				cout<<"������Ҫ������˳����еĳ���";
				cin>>i;
				cout<<endl;
				InitQueue (Q,i);
				cout<<endl<<"�����ɹ���"<<endl;
				break;
		     case 2:										// ���
				cout<<"����Ҫ��ӵ�Ԫ��ֵ��"<<endl;
                cin>>e;
				cout<<endl;
				if(EnQueue(Q,e))
				{
					 cout<<endl<<"��ӳɹ�����Ӻ����Ԫ��Ϊ��"<<endl;
 					 DispQueue(Q);
				}
				 else
					 cout<<endl<<"������������ӣ�"<<endl;
				break;
			case 3:											// ����
				 if(DeQueue(Q,e))
                 {
					 cout<<endl<<"����Ԫ��Ϊ��";
					 DispQueue(Q);
                     cout<<endl<<"����Ԫ��Ϊ:"<<e<<endl;
                 }
				 else
					 cout<<endl<<"�ӿգ����ܳ��ӣ�"<<endl;
				break;
			 case 4:										// ȡ��ͷԪ��
                 if(GetHead(Q,e))
				 {
 					 cout<<endl<<"����Ԫ��Ϊ��";
					 DispQueue(Q);
                     cout<<endl<<"��ͷԪ��Ϊ:"<<e<<endl;
                 }
				 else
					 cout<<endl<<"�ӿգ�"<<endl;
				 break;
             case 5:										// ȡ��βԪ��
                 if(GetTail(Q,e))
                 {
					 cout<<endl<<"����Ԫ��Ϊ��";
					 DispQueue(Q);
                     cout<<endl<<"��βԪ��Ϊ:"<<e<<endl;
                 }
				 else
					 cout<<endl<<"�ӿգ�������Ԫ��"<<endl;
				 break;
			 case 6:								// ��ն�
				 ClearQueue(Q);
				 cout<<"�������!"<<endl;
				 break;
			 case 7:										// ��ӿ�
				 if(QueueEmpty(Q))
					 cout<<endl<<"�նӣ�"<<endl;
				 else
					 cout<<endl<<"�ǿնӣ�"<<endl;
				 break;		
             case 8:										// �����
				 if(QueueFull(Q))
					 cout<<endl<<"���ӣ�"<<endl;
				 else
					 cout<<endl<<"�����ӣ�"<<endl;
				 break;
			 case 9:										// ��ʾ����Ԫ��
                DispQueue(Q);
				cout<<endl;
				break;
			 case 10:
				 cout<<"\nQ.fornt="<<Q.front<<endl;
				 cout<<"Q.rear="<<Q.rear<<endl;
				 break;
  			case 0:											// �˳�
                DestroyQueue(Q);
				cout<<"��������Bye-bye!"<<endl;
                break; 
			default:										// ��Чѡ��
				cout<<"��Чѡ��!\n";
				break;
			}
	}while(choice!=0);

	return 0;
}//end of main function

