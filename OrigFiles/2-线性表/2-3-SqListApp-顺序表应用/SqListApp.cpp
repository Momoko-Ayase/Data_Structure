
#include<iostream>//cout,cin
using namespace std;
#include "SqList.h"

char pause;

void dispmenu()
{														// 显示主菜单
	cout<<"\n*** 顺序表的应用 ***\n";
	cout<<" 1-集合并A=A∪B\n";
	cout<<" 2-顺序表逆置\n";
	cout<<" 3-多项式求和\n";
	cout<<" 0-退出\n";
}


//算法2.11
template <class DT>
void Union(SqList<DT> &La, SqList<DT> Lb)				// 求La=La∪La
{
	DT e;
	int k,i;
	for(i=1;i<=Lb.length;i++)						// 扫描Lb
	{
		GetElem_i(Lb,i,e);								// 1. 获取Lb的第i个元素
		if(!LocateElem_e(La,e))							// 2.如果La中无此元素
		{
			k=La.length+1;								// 添加在La的表尾
			InsertElem_i(La,k,e);
		}
	}
}

//算法2.12
template <class DT>
void ReverseSqList(SqList<DT> &L)						// 顺序表元素逆置
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

//算法2.13												多项式求和 lc=la+lb
void PolyAdd(SqList<float> la, SqList<float> lb, SqList<float> &lc) 
{
	int i=0;											// 1.初始化，设置处理起始位置
	while(i<la.length && i<lb.length)					// 2.两个多项式均未处理完
	{
		lc.elem[i]=la.elem[i]+lb.elem[i];				// 相同位序上的系数相加
		i++;
		
	}
	if(la.length>lb.length)								// 3.la未处理完，lb已处理完
	{
		while(i<la.length)								// lc取la中剩余项
		{
			lc.elem[i]=la.elem[i];
			i++;
			
		}
	}
	else												// 3.lb未处理完，la已处理完
	{
		while(i<lb.length)								// lc取lb中剩余项
		{
			lc.elem[i]=lb.elem[i]; 
			i++;
			
		}
	}
}

														//显示多顶式
void DispPoly(float A[],int n)
{
	int i;
	cout<<A[0]<<"+";
	for (i=1; i<n-1;i++)
		cout<<A[i]<<"x^"<<i<<" + ";
	cout<<A[i]<<"x^"<<i;
	cout<<endl;
}



 //主函数
int main()
{
	int e;
	int na,nb,nc;
	SqList<int> La,Lb;										// 集合A、B
	SqList<int> Lc;											// 顺序表
	SqList<float> fa,fb,fc;									// 多项式A、B、C
		
	system("cls");											// 清屏
    
	int choice;
    do
	{
		dispmenu();											// 显示主菜单
		cout<<"Enter choice(1~4,0退出):";
		cin>>choice;
		switch(choice)
		{
			case 1:											// 求集合并
				cout<<"创建集合A、B\n";
				cout<<"输入集合A元素个数：";
				cin>>na;
				cout<<"输入集合B元素个数：";
				cin>>nb;
				InitList(La,na+nb);							// 创建集合A
				cout<<"创建集合A的元素\n";
				CreateList(La,na);
				InitList(Lb,nb);							// 创建集合B
				cout<<"创建集合B的元素\n";
				CreateList(Lb,nb);
				cout<<"集合A为："<<endl;					// 显示集合A
				DispList(La); 
				cout<<"集合B为："<<endl;					// 显示集合B
				DispList(Lb);
				Union(La, Lb);								// 求集合并
				cout<<"A∪B为:"<<endl;						// 显示结果
				DispList(La);
				cout<<endl;
				DestroyList(La);
				DestroyList(Lb);
				break;
		    
			case 2:											// 顺序表逆置
				cout<<"请输入要创建的顺序表中元素个数:";
				cin>>nc;
				InitList(Lc,nc);
				cout<<endl;
				CreateList(Lc,nc);
				cout<<"创建的顺序表为："<<endl;				// 显示集合A
				DispList(Lc);
				ReverseSqList(Lc);
				cout<<"逆置后的顺序表为："<<endl;			// 显示集合A
				DispList(Lc);
				cout<<endl;
                DestroyList(Lc);
				break;
			case 3:											//多项式求和
				cout<<"\n创建多项式A\n";						// 创建多项式A
				cout<<"输入多项式A的项数：";
				cin>>na;
				InitList(fa,na);							
				cout<<"按幂升序输入多项式A各项系数\n";
				CreateList(fa,na);
				cout<<"\n创建多项式B\n";						// 创建多项式B
				cout<<"输入多项式B的项数：";
				cin>>nb;
				InitList(fb,nb);							
				cout<<"按幂升序输入多项式B各项系数\n";
				CreateList(fb,nb);
				cout<<"\n多项式 A 为 ："<<endl;				// 显示多项式A
				DispPoly(fa.elem,na);
				cout<<"\n多项式 B 为 ："<<endl;				// 显示多项式B
				DispPoly(fb.elem,nb);
				nc=(na>=nb)?na:nb;
				InitList(fc,nc);							// 创建多项式C
				PolyAdd(fa,fb,fc);							// 求多项式 C=A+B
				cout<<"\n多项式A + 多项式B = "<<endl;		// 显示结果
				DispPoly(fc.elem,nc);
				cout<<endl;
		     	DestroyList(fa);
				DestroyList(fb);
				DestroyList(fc);
				break;	
  			case 0:											// 退出
                cout<<" 结束运行bye-bye!"<<endl;
                break;
			default:										// 无效选择
				cout<<"无效选择!\n";
				break;
			}
	}while(choice!=0);
    
	return 0;
}//end of main function
