/***��ջʵ������ƥ��***/
#include<string>
#include<iostream>
using namespace std;
#include"LinkStack.h"

//�㷨3.11												���ŵ�ƥ��
bool match(string exp)
{
	//������ʽ(���ʽ��"#"����)������"["��"]"��"("��")"�Ƿ�ƥ�䣬���ƥ�䣬�򷵻�true�����򷵻�false��
	//���ʽ�ԡ�#������
	SNode<char> *S;
	InitStack(S);
	int flag=1;        								// ��ǲ��ҽ���Կ���ѭ�������ؽ��
	char ch;
	char e,x;
	int i=0;
	ch=exp[i++];            								// �����һ���ַ�
	while(ch!='#' && flag)
	{
	   switch (ch)
		{
		    case '[':
            case '(': 								// ���������ţ�����ѹ��ջ
			    cout<<"�����Ž�ջ��"<<endl;
				Push(S,ch);
				break;
		   case ')' :     							// ���������š�)���������ջ��Ԫ�ص�ֵ���������
			    GetTop(S,e);
				if (!StackEmpty(S) && e=='(' )		// ��ջ�ǿ���ջ��Ԫ���ǡ�(������ƥ��ɹ�
				{
					Pop(S,x);
					cout<<"�����ų�ջ��"<<endl;
				}
				else
					flag=0;                 		// ��ջ�ջ�ջ��Ԫ�ز��ǡ�(������Ƿ�
				break;
		   case ']' :								 // ���������š�]���������ջ��Ԫ�ص�ֵ���������
				GetTop(S,e);
				if (!StackEmpty(S) && e=='[' )		// ��ջ��Ԫ���ǡ�[������ƥ��ɹ�
					 Pop(S,x);
				else
					flag=0;                 		// ��ջ�ջ�ջ��Ԫ�ز��ǡ�[������Ƿ�
			   break;
	   }//switch
	   ch=exp[i++];       								//����������һ���ַ�
	}//while
	if (StackEmpty(S) && flag )						// ջ���ұ�־Ϊtrue,����ƥ�䣬����true
	   return true;
	else											// �������Ų�ƥ��,����false
	   return false;
}//match



int main()
{
	int flag; 
	string exp;
	cout<<"�������ƥ��ı��ʽ���ԡ�#��������"<<endl;
	cin>>exp;
    flag = match(exp);
	if(flag)
		cout<<"����ƥ��ɹ���"<<endl;
	else
		cout<<"����ƥ��ʧ�ܣ�"<<endl;
	return 0;
}//end of main function

