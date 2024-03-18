
template <class DT>
struct SNode			 // 结点
{
	DT data;			 // 数据域，存储数据元素值
	SNode *next;		// 指针域，指向下一个结点
};


//【算法3.6】
template <class DT>
bool InitStack(SNode<DT> *&S)	    // 创建空链栈
{
	S=NULL;
	return true;
}

//【算法3.7】
template <class DT>
void DestroyStack(SNode<DT> *(&S))	// 释放链栈所占内存
{
	SNode<DT> *p;
	while(S)						//从头结点开始，依次释放结点
	{
		p=S;
		S=S->next;
	    delete p;
	}
	S=NULL;
}



//【算法3.8】
template<class DT>
bool Push(SNode<DT> *&S,DT e)
{
    SNode<DT> *p;
    p=new SNode<DT>;
    if(!p) 
		return false;  //创建失败，结束运行
    p->data=e;       // 新结点赋值
    p->next=S;  //结点S链接到p结点之后
    S=p;
	return true;    // 插入成功，返回true
}

//【算法3.9】
template<class DT>
bool Pop(SNode<DT> *&S,DT &e)
{
    SNode<DT> *p;
    if(S==NULL)  return false;
    p=S;
    e=p->data;
    S=S->next;
    delete p;
	return true;    // 删除成功，返回true
}


//【算法3.10】
template<class DT>
bool GetTop(SNode<DT> *S,DT &e)
{
	SNode<DT> *p;
    if(S==NULL)  return false;
    p=S;
    e=p->data;
	return true;    // 删除成功，返回true
}

//测栈空
template<class DT>
bool StackEmpty(SNode<DT> *S)
{
	if(S==NULL)
		return true;
	else
		return false;
}

//显示栈内容
template<class DT>
void DispStack(SNode<DT> *S)
{
    SNode<DT> *p;
    p=S;
	while(p)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
}

