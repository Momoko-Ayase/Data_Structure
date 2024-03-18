template <class DT>
struct SqStack														// 顺序栈
{
	DT *base;														// 栈首址
	int top;														// 栈顶指针
	int stacksize;													// 栈容量
};

//基本操作的实现
//【算法3.1】														// 初始化栈													
template <class DT>
void InitStack(SqStack<DT> &S, int m)
{
	S.base=new DT[m];												// 申请栈空间
    if(S.base==NULL)												// 申请失败，退出
	{
		cout<<"未创建成功！";
		exit (1);
	}
	S.top=-1;														// 设置空栈属性
	S.stacksize=m;				
}


//算法3.2】															// 销毁栈
template <class DT>
void DestroyStack(SqStack<DT> &S)
{
	delete [] S.base;												// 释放栈空间
	S.top=-1;
	S.stacksize=0;													// 设置栈属性
}


//【算法3.3】														// 入栈
template<class DT>
bool Push(SqStack<DT> &S,DT e)
{
	if(S.top==S.stacksize-1)										// 栈满，不能入栈
		return false;												// 返回false
	S.top++;
	S.base[S.top]=e;
	return true;													// 入栈成功，返回true
}

//【算法3.4】														// 出栈
template<class DT>
bool Pop(SqStack<DT> &S,DT &e)
{
	if(S.top==-1)													// 栈空
        return false;												// 返回false
	e=S.base[S.top];												// 取栈顶元素
	S.top--;														// 栈顶指针下移
	return true;													// 出栈成功，返回true
}


//【算法3.5】														// 获取栈顶元素
template<class DT>
bool GetTop(SqStack<DT> S,DT &e)
{
	if(S.top==-1)													// 栈空
        return false;												// 返回false
	e=S.base[S.top];												// 栈非空，取栈顶元素
	return true;													// 返回true
}

																	// 测栈空
template<class DT>
bool StackEmpty(SqStack<DT> S)
{
	if(S.top==-1)													// 空栈，返回true
		return true;
	else															// 空栈，返回false
		return false;
}

																	//显示栈内容
template<class DT>
void DispStack(SqStack<DT> S)
{
    int i=S.top;
	while(i>=0)
	{
		cout<<S.base[i--]<<"\t";
	}
	cout<<endl;
}

template<class DT>
void ClearStack(SqStack<DT> &S)
{
    S.top=-1;
      
}

template<class DT>
int StackFull(SqStack<DT> S)
{
        if(S.top==S.stacksize-1)
           return 1;
        else
           return 0;
       
}


