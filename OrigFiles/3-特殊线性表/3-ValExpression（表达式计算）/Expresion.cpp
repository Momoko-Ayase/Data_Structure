#include<iostream>		//cout,cin
using namespace std;
#include"SqStack.h"

char pause;

char Precede(char t1,char t2)								//算符的优先级比较
 { 
   char f;
   switch(t2)
   {
     case '+':
     case '-':if(t1=='('||t1=='=')
                f='<';
              else
                f='>';
              break;
     case '*':
     case '/':if(t1=='*'||t1=='/'||t1==')')
                f='>';
              else
                f='<';
              break;
     case '(':if(t1==')')
              {
                cout<<"ERROR1"<<endl;
                exit(0);
              }
              else
                f='<';
              break;
     case ')':switch(t1)
              {
                case '(':f='=';
                         break;
                case '=':cout<<"ERROR2"<<endl;
                         exit(0);
                default: f='>';
              }
              break;
     case '=':switch(t1)
              {
                case '=':f='=';
                         break;
                case '(':cout<<"ERROR2"<<endl;
                         exit(0);
                default: f='>';
              }
   }
   return f;
 }

 
bool In(char ch)										// 判断 ch 是否为运算符
 { 
   switch(ch)
   {
     case'+':
     case'-':
     case'*':
     case'/':
     case'(':
     case')':
     case'=':return true; 
     default:return false;
   }
 }


float Operate(float a,char theta,float b) 
 {													// 实施一次运算
   float ch;
   switch(theta)
   {
     case'+':ch=a+b;
             break;
     case'-':ch=a-b;
             break;
     case'*':ch=a*b;
             break;
     case'/':ch=a/b;
   }
   return ch;
 }

//算法3.12 
float Val_Exp(char *exp)								// 中缀表达式求值。
{												
   SqStack<char>   OP;									// 运算符栈
   SqStack<float>  OD;									// 运算数栈
   InitStack(OP,30);
   InitStack(OD,30);
   char theta;
   float a,b,result;
   char ch,x;											// 存放由键盘接收的字符
   char z[6];											// 存放符点数字符串
   int i;
   Push(OP,'=');										// # 是表达式结束标志
   ch=*exp++;
   GetTop(OP,x);
   while(ch!='='||x!='=')
   {
      if(ch>='0'&&ch<='9'||ch=='.')					// ch 是操作数
      {
		i=0;
		do
		{
			 z[i]=ch;
			i++;
			ch=*exp++;
		 } while(ch>='0'&&ch<='9'||ch=='.');
		z[i]='\0';
		result=atof(z);										// 将字符串数组转为符点型存于result
		Push(OD,result);
      }
	  else if(In(ch))											// 是7种运算符之一
		  switch(Precede(x,ch))
			{
			case'<':Push(OP,ch);							// 栈顶元素优先权低
                 ch=*exp++;
                 break;
			 case'=':Pop(OP,x);								// 脱括号并接收下一字符
                 ch=*exp++;
                 break;
			case'>':Pop(OP,theta);							// 退栈并将运算结果入栈
                 Pop(OD,b);
                 Pop(OD,a);
                 Push(OD,Operate(a,theta,b));
			}
     else												// ch是非法字符
     {
       cout<<"ERROR3"<<endl;;
       exit(0);
     }
     GetTop(OP,x);
   }
   GetTop(OD,result);
   DestroyStack(OP);
   DestroyStack(OD);
   return result;
 }

void CreatePostExp(char * exp,char * &postexp)			// 由中缀式求后缀式
{
	char ch,x;
	int i=0;
	SqStack<char> OP;
	InitStack(OP,30);
	Push(OP,'=');										// # 是表达式结束标志
	cout<<"中缀表达式："<<exp<<endl;
	ch=*exp++;
	while(ch)
	{
		if((ch>='0'&&ch<='9')||ch=='.')
		{
			postexp[i++]=ch;
			ch=*exp++;
		}
		if(In(ch))										// 是7种运算符之一
		{
			postexp[i++]=' ';
     	    GetTop(OP,x);
			switch(Precede(x,ch))
			{
				case'<':Push(OP,ch);						// 栈顶元素优先权低
                         ch=*exp++;
                         break;
                 case'=':Pop(OP,x);						// 脱括号并接收下一字符
                         ch=*exp++;
                         break;
                 case'>':
					 Pop(OP,postexp[i++]);				// 运算符出栈输出
					     break;
			}
		}
		postexp[i]='\0';
	}//while
	cout<<"\n后缀表达式为:"<<postexp<<endl;
	DestroyStack(OP);
}

//算法3.13  
float Val_PostExp(char *postexp)						// 后缀表达式求值
{
	int i;
	char z[6];
	float result=0,d=0,a,b;
	char ch;
	SqStack<float> OD;
	InitStack(OD,30);
	ch=*postexp++;
	while(ch!='\0')
	{
		
		if(ch>='0'&&ch<='9'||ch=='.')						// ch为操作数符号
		{
			i=0;
			do
			{
				z[i++]=ch;
				ch=*postexp++;							// 取下一个操作数符号
			} while(ch>='0'&&ch<='9'||ch=='.');
			z[i]='\0';
			d=atof(z);									// 将字符串数组转为符点型存于result
			Push(OD,d);									// 操作数进栈
		}
		if(In(ch))										// ch为运算符
		{
			Pop (OD,a);
			Pop (OD,b);
			Push (OD,Operate(b,ch,a));
			ch=*postexp++;
		}
		ch=*postexp++;
	}
	Pop (OD,result);
	DestroyStack(OD);
	return result;
}


 //主函数
void main()
{
	//int i;
	char exp[20]="(2.2+5)+4*(5-3.1)=";
	char *postexp;
	postexp=new char[30];
	*postexp='\0';
	float v;
	system("cls");										// 清屏
	cout<<"\n缺省表达式："<<exp;
	cout<<endl;
	int choice;
    do
	{													// 显示主菜单
		cout<<endl;
		cout<<"1-创建表达式\n";	
		cout<<"2-表达式求值\n";
		cout<<"3-求后缀表达式\n";
		cout<<"4-后缀表达式求值\n";
		cout<<"5-显示表达式\n";
		cout<<"0-退出\n";
		cout<<"输入功能选项（1~5，0 退出）:\n";
		cin>>choice;
		switch(choice)
			{
			case 1:										// 创建表达式
				cout<<"\n请输入表达式，以=结束"<<endl;
				cin>>exp;
				break;
			case 2:										// 表达式求值
				v=Val_Exp(exp) ;
				cout<<exp;
				cout<<v<<endl;
				break;
			case 3:										// 求后缀表达式
				CreatePostExp(exp,postexp);
				break;
			case 4:										// 后缀表达式求值
				v=Val_PostExp(postexp);
				cout<<'\n'<<postexp<<"="<<v<<endl;
				break;
			case 5:										// 显示表达式
				cout<<endl;
				cout<<"\n已创建的表达式为：";
				cout<<exp<<endl;
				if(strlen(postexp))
				{
					cout<<"\n后缀表达式为：";
					cout<<postexp<<endl; 
				}
				break;
			case 0:										// 退出
				cout<<"\n结束运行，Bye-Bye!"<<endl;
				break;
			default://
				cout<<"\n无效选择!\n";
				break;
			}
	}while(choice!=0);
}//end main