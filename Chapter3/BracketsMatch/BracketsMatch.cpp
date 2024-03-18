/***链栈实现括号匹配***/
#include<string>
#include<iostream>
using namespace std;
#include"LinkStack.h"

//算法3.11												括号的匹配
bool match(string exp)
{
	//检验表达式(表达式以"#"结束)中所含"["和"]"、"("和")"是否匹配，如果匹配，则返回true，否则返回false。
	//表达式以“#”结束
	SNode<char>* S;
	InitStack(S);
	int flag = 1;        								// 标记查找结果以控制循环及返回结果
	char ch;
	char e, x;
	int i = 0;
	ch = exp[i++];            								// 读入第一个字符
	while (ch != '#' && flag)
	{
		switch (ch)
		{
		case '[':
		case '(': 								// 若是左括号，则将其压入栈
			cout << "左括号进栈！" << endl;
			Push(S, ch);
			break;
		case ')':     							// 若是右括号“)”，则根据栈顶元素的值分情况考虑
			GetTop(S, e);
			if (!StackEmpty(S) && e == '(')		// 若栈非空且栈顶元素是“(”，则匹配成功
			{
				Pop(S, x);
				cout << "右括号出栈！" << endl;
			}
			else
				flag = 0;                 		// 若栈空或栈顶元素不是“(”，则非法
			break;
		case ']':								 // 若是右括号“]”，则根据栈顶元素的值分情况考虑
			GetTop(S, e);
			if (!StackEmpty(S) && e == '[')		// 若栈顶元素是“[”，则匹配成功
				Pop(S, x);
			else
				flag = 0;                 		// 若栈空或栈顶元素不是“[”，则非法
			break;
		}//switch
		ch = exp[i++];       								//继续读入下一个字符
	}//while
	if (StackEmpty(S) && flag)						// 栈空且标志为true,括号匹配，返回true
		return true;
	else											// 否则，括号不匹配,返回false
		return false;
}//match



int main()
{
	int flag;
	string exp;
	cout << "请输入待匹配的表达式，以“#”结束：" << endl;
	cin >> exp;
	flag = match(exp);
	if (flag)
		cout << "括号匹配成功！" << endl;
	else
		cout << "括号匹配失败！" << endl;
	return 0;
}//end of main function

