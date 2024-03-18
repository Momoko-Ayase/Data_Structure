
template <class DT>
struct QNode  //结点
{
	DT data;     //数据域，存储数据元素值
	QNode *next;//指针域，指向下一个结点
};

template<class DT>
struct LinkQueue
{
	QNode<DT> * front;
	QNode<DT> * rear;
};


//【算法3.19】
template <class DT>
void InitQueue(LinkQueue<DT> &Q)//创建空队列
{
	Q.front=new QNode<DT>;     //创建头结点
	if(!Q.front) exit(1);  //创建失败，结束运行
	Q.front->next=NULL;
	Q.rear=Q.front;
}

//【算法3.20】
template <class DT>
void DestroyQueue(LinkQueue<DT> &Q)//释放链队
{
	QNode<DT> *p;
	while(Q.front)//从头结点开始，依次释放结点
	{
		p=Q.front;
		Q.front=Q.front->next;
	    delete p;
	}
}

//【算法3.21】 入队
template<class DT>
bool EnQueue(LinkQueue<DT> &Q,DT e)
{
    QNode<DT> *p;
    p=new QNode<DT>;         // 创建新结点
    if(!p) return false;      // 创建失败，结束运行
    p->data=e;               // 新结点赋值
    p->next=NULL;            // 链在队尾
    Q.rear->next=p;
    Q.rear=p;
	return true;             // 入队成功，返回true
}

//【算法3.22】 出队
template<class DT>
bool DeQueue(LinkQueue<DT> &Q,DT &e)      
{
    QNode<DT> *p;
    if(Q.front==Q.rear)  return false;     //队空，返回false
    p=Q.front->next;                      // 取出队元素
    e=p->data;
    Q.front->next=p->next;                //队首元素出队
    if(Q.rear==p)                         //只有一个元素时出队，
		Q.rear=Q.front;                  // 修改队尾
    delete p;
	return true;                        // 出队成功，返回true
}


//【算法3.23】  取队头元素
template<class DT>
bool GetHead(LinkQueue<DT> Q,DT &e)
{
	if(Q.front==Q.rear)  return false;     // 队空，返回false
    e=Q.front->next->data;
	return true;                           // 删除成功，返回true
}

//取队尾元素
template<class DT>
bool GetTail(LinkQueue<DT> Q,DT &e)
{
	if(Q.front==Q.rear)             // 队空
		return false;               // 返回false
    e=Q.rear->data;                 // 获取队尾元素
	return true;                    // 返回true
}

//测队空
template<class DT>
bool QueueEmpty(LinkQueue<DT> Q)
{
	if(Q.front==Q.rear)    // 队空
		return true;       //返回true
	else                  //非空
		return false;    //返回false
}

//显示队列内容
template<class DT>
void DispQueue(LinkQueue<DT> Q)
{
    QNode<DT> *p;
    p=Q.front->next;
	while(p)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
}

