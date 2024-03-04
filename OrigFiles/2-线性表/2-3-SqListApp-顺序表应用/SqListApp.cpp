
#include<iostream>//cout,cin
using namespace std;
#include "SqList.h"

char pause;

void dispmenu()
{														// ��ʾ���˵�
	cout<<"\n*** ˳����Ӧ�� ***\n";
	cout<<" 1-���ϲ�A=A��B\n";
	cout<<" 2-˳�������\n";
	cout<<" 3-����ʽ���\n";
	cout<<" 0-�˳�\n";
}


//�㷨2.11
template <class DT>
void Union(SqList<DT> &La, SqList<DT> Lb)				// ��La=La��La
{
	DT e;
	int k,i;
	for(i=1;i<=Lb.length;i++)						// ɨ��Lb
	{
		GetElem_i(Lb,i,e);								// 1. ��ȡLb�ĵ�i��Ԫ��
		if(!LocateElem_e(La,e))							// 2.���La���޴�Ԫ��
		{
			k=La.length+1;								// �����La�ı�β
			InsertElem_i(La,k,e);
		}
	}
}

//�㷨2.12
template <class DT>
void ReverseSqList(SqList<DT> &L)						// ˳���Ԫ������
{
	DT t;
	int i;
	for(i=0; i<L.length/2; i++)						// 2.L.elem[i]<-->L.elem[L.length-i-1]
	{
		t=L.elem[i];
		L.elem[i]=L.elem[L.length-i-1];
		L.elem[L.length-i-1]=t;
	}
	return;
}

//�㷨2.13												����ʽ��� lc=la+lb
void PolyAdd(SqList<float> la, SqList<float> lb, SqList<float> &lc) 
{
	int i=0;											// 1.��ʼ�������ô�����ʼλ��
	while(i<la.length && i<lb.length)					// 2.��������ʽ��δ������
	{
		lc.elem[i]=la.elem[i]+lb.elem[i];				// ��ͬλ���ϵ�ϵ�����
		i++;
		
	}
	if(la.length>lb.length)								// 3.laδ�����꣬lb�Ѵ�����
	{
		while(i<la.length)								// lcȡla��ʣ����
		{
			lc.elem[i]=la.elem[i];
			i++;
			
		}
	}
	else												// 3.lbδ�����꣬la�Ѵ�����
	{
		while(i<lb.length)								// lcȡlb��ʣ����
		{
			lc.elem[i]=lb.elem[i]; 
			i++;
			
		}
	}
}

														//��ʾ�ඥʽ
void DispPoly(float A[],int n)
{
	int i;
	cout<<A[0]<<"+";
	for (i=1; i<n-1;i++)
		cout<<A[i]<<"x^"<<i<<" + ";
	cout<<A[i]<<"x^"<<i;
	cout<<endl;
}



 //������
int main()
{
	int e;
	int na,nb,nc;
	SqList<int> La,Lb;										// ����A��B
	SqList<int> Lc;											// ˳���
	SqList<float> fa,fb,fc;									// ����ʽA��B��C
		
	system("cls");											// ����
    
	int choice;
    do
	{
		dispmenu();											// ��ʾ���˵�
		cout<<"Enter choice(1~4,0�˳�):";
		cin>>choice;
		switch(choice)
		{
			case 1:											// �󼯺ϲ�
				cout<<"��������A��B\n";
				cout<<"���뼯��AԪ�ظ�����";
				cin>>na;
				cout<<"���뼯��BԪ�ظ�����";
				cin>>nb;
				InitList(La,na+nb);							// ��������A
				cout<<"��������A��Ԫ��\n";
				CreateList(La,na);
				InitList(Lb,nb);							// ��������B
				cout<<"��������B��Ԫ��\n";
				CreateList(Lb,nb);
				cout<<"����AΪ��"<<endl;					// ��ʾ����A
				DispList(La); 
				cout<<"����BΪ��"<<endl;					// ��ʾ����B
				DispList(Lb);
				Union(La, Lb);								// �󼯺ϲ�
				cout<<"A��BΪ:"<<endl;						// ��ʾ���
				DispList(La);
				cout<<endl;
				DestroyList(La);
				DestroyList(Lb);
				break;
		    
			case 2:											// ˳�������
				cout<<"������Ҫ������˳�����Ԫ�ظ���:";
				cin>>nc;
				InitList(Lc,nc);
				cout<<endl;
				CreateList(Lc,nc);
				cout<<"������˳���Ϊ��"<<endl;				// ��ʾ����A
				DispList(Lc);
				ReverseSqList(Lc);
				cout<<"���ú��˳���Ϊ��"<<endl;			// ��ʾ����A
				DispList(Lc);
				cout<<endl;
                DestroyList(Lc);
				break;
			case 3:											//����ʽ���
				cout<<"\n��������ʽA\n";						// ��������ʽA
				cout<<"�������ʽA��������";
				cin>>na;
				InitList(fa,na);							
				cout<<"���������������ʽA����ϵ��\n";
				CreateList(fa,na);
				cout<<"\n��������ʽB\n";						// ��������ʽB
				cout<<"�������ʽB��������";
				cin>>nb;
				InitList(fb,nb);							
				cout<<"���������������ʽB����ϵ��\n";
				CreateList(fb,nb);
				cout<<"\n����ʽ A Ϊ ��"<<endl;				// ��ʾ����ʽA
				DispPoly(fa.elem,na);
				cout<<"\n����ʽ B Ϊ ��"<<endl;				// ��ʾ����ʽB
				DispPoly(fb.elem,nb);
				nc=(na>=nb)?na:nb;
				InitList(fc,nc);							// ��������ʽC
				PolyAdd(fa,fb,fc);							// �����ʽ C=A+B
				cout<<"\n����ʽA + ����ʽB = "<<endl;		// ��ʾ���
				DispPoly(fc.elem,nc);
				cout<<endl;
		     	DestroyList(fa);
				DestroyList(fb);
				DestroyList(fc);
				break;	
  			case 0:											// �˳�
                cout<<" ��������bye-bye!"<<endl;
                break;
			default:										// ��Чѡ��
				cout<<"��Чѡ��!\n";
				break;
			}
	}while(choice!=0);
    
	return 0;
}//end of main function
