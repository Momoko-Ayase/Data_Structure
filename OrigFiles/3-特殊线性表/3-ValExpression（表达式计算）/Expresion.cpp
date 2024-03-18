#include<iostream>		//cout,cin
using namespace std;
#include"SqStack.h"

char pause;

char Precede(char t1,char t2)								//��������ȼ��Ƚ�
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

 
bool In(char ch)										// �ж� ch �Ƿ�Ϊ�����
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
 {													// ʵʩһ������
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

//�㷨3.12 
float Val_Exp(char *exp)								// ��׺���ʽ��ֵ��
{												
   SqStack<char>   OP;									// �����ջ
   SqStack<float>  OD;									// ������ջ
   InitStack(OP,30);
   InitStack(OD,30);
   char theta;
   float a,b,result;
   char ch,x;											// ����ɼ��̽��յ��ַ�
   char z[6];											// ��ŷ������ַ���
   int i;
   Push(OP,'=');										// # �Ǳ��ʽ������־
   ch=*exp++;
   GetTop(OP,x);
   while(ch!='='||x!='=')
   {
      if(ch>='0'&&ch<='9'||ch=='.')					// ch �ǲ�����
      {
		i=0;
		do
		{
			 z[i]=ch;
			i++;
			ch=*exp++;
		 } while(ch>='0'&&ch<='9'||ch=='.');
		z[i]='\0';
		result=atof(z);										// ���ַ�������תΪ�����ʹ���result
		Push(OD,result);
      }
	  else if(In(ch))											// ��7�������֮һ
		  switch(Precede(x,ch))
			{
			case'<':Push(OP,ch);							// ջ��Ԫ������Ȩ��
                 ch=*exp++;
                 break;
			 case'=':Pop(OP,x);								// �����Ų�������һ�ַ�
                 ch=*exp++;
                 break;
			case'>':Pop(OP,theta);							// ��ջ������������ջ
                 Pop(OD,b);
                 Pop(OD,a);
                 Push(OD,Operate(a,theta,b));
			}
     else												// ch�ǷǷ��ַ�
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

void CreatePostExp(char * exp,char * &postexp)			// ����׺ʽ���׺ʽ
{
	char ch,x;
	int i=0;
	SqStack<char> OP;
	InitStack(OP,30);
	Push(OP,'=');										// # �Ǳ��ʽ������־
	cout<<"��׺���ʽ��"<<exp<<endl;
	ch=*exp++;
	while(ch)
	{
		if((ch>='0'&&ch<='9')||ch=='.')
		{
			postexp[i++]=ch;
			ch=*exp++;
		}
		if(In(ch))										// ��7�������֮һ
		{
			postexp[i++]=' ';
     	    GetTop(OP,x);
			switch(Precede(x,ch))
			{
				case'<':Push(OP,ch);						// ջ��Ԫ������Ȩ��
                         ch=*exp++;
                         break;
                 case'=':Pop(OP,x);						// �����Ų�������һ�ַ�
                         ch=*exp++;
                         break;
                 case'>':
					 Pop(OP,postexp[i++]);				// �������ջ���
					     break;
			}
		}
		postexp[i]='\0';
	}//while
	cout<<"\n��׺���ʽΪ:"<<postexp<<endl;
	DestroyStack(OP);
}

//�㷨3.13  
float Val_PostExp(char *postexp)						// ��׺���ʽ��ֵ
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
		
		if(ch>='0'&&ch<='9'||ch=='.')						// chΪ����������
		{
			i=0;
			do
			{
				z[i++]=ch;
				ch=*postexp++;							// ȡ��һ������������
			} while(ch>='0'&&ch<='9'||ch=='.');
			z[i]='\0';
			d=atof(z);									// ���ַ�������תΪ�����ʹ���result
			Push(OD,d);									// ��������ջ
		}
		if(In(ch))										// chΪ�����
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


 //������
void main()
{
	//int i;
	char exp[20]="(2.2+5)+4*(5-3.1)=";
	char *postexp;
	postexp=new char[30];
	*postexp='\0';
	float v;
	system("cls");										// ����
	cout<<"\nȱʡ���ʽ��"<<exp;
	cout<<endl;
	int choice;
    do
	{													// ��ʾ���˵�
		cout<<endl;
		cout<<"1-�������ʽ\n";	
		cout<<"2-���ʽ��ֵ\n";
		cout<<"3-���׺���ʽ\n";
		cout<<"4-��׺���ʽ��ֵ\n";
		cout<<"5-��ʾ���ʽ\n";
		cout<<"0-�˳�\n";
		cout<<"���빦��ѡ�1~5��0 �˳���:\n";
		cin>>choice;
		switch(choice)
			{
			case 1:										// �������ʽ
				cout<<"\n��������ʽ����=����"<<endl;
				cin>>exp;
				break;
			case 2:										// ���ʽ��ֵ
				v=Val_Exp(exp) ;
				cout<<exp;
				cout<<v<<endl;
				break;
			case 3:										// ���׺���ʽ
				CreatePostExp(exp,postexp);
				break;
			case 4:										// ��׺���ʽ��ֵ
				v=Val_PostExp(postexp);
				cout<<'\n'<<postexp<<"="<<v<<endl;
				break;
			case 5:										// ��ʾ���ʽ
				cout<<endl;
				cout<<"\n�Ѵ����ı��ʽΪ��";
				cout<<exp<<endl;
				if(strlen(postexp))
				{
					cout<<"\n��׺���ʽΪ��";
					cout<<postexp<<endl; 
				}
				break;
			case 0:										// �˳�
				cout<<"\n�������У�Bye-Bye!"<<endl;
				break;
			default://
				cout<<"\n��Чѡ��!\n";
				break;
			}
	}while(choice!=0);
}//end main