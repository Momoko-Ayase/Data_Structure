
template <class DT>
struct LNode										//链表结点
{
	DT data;										//数据域，存储数据元素值
	LNode* next;									//指针域，指向下一个结点
};

//算法2.1
template <class DT>
bool PriorElem_e(LNode<DT>* L, DT e, DT& pre_e)		// 求值为e的元素前驱
{
	int k;
	k = LocateElem_e(L, e);							// 1.获取e的位序k
	if (k > 1)											// 2.位序k大于1
	{
		GetElem_i(L, k - 1, pre_e);						// 第k-1个元素为e的前驱
		return true;
	}
	else											// 3.元素e无前驱
		return false;								// 返回false
}

//【算法2.14】										创建空单链表
template <class DT>
bool InitList(LNode<DT>*& L)
{
	L = new LNode<DT>;								// 1.创建头结点
	if (!L) exit(1);									// 2.创建失败，退出
	L->next = NULL;									// 3.创建成功
	return true;									// 返回true
}

//【算法2.15】										尾插法创建n的元素
template <class DT>
bool CreateList_1(LNode<DT>*& L, int n)
{
	int i;
	LNode<DT>* p, * s;
	p = L;											//1.工作指针初始化，指向尾结点
	cout << "依次输入" << n << "个数据元素：" << endl;
	for (i = 1; i <= n; i++)							// 2.按元素位序正序创建各结点
	{
		s = new LNode<DT>;							// 2.1 新建一个结点s
		if (!s)										// 2.2 创建失败，返回false
			return false;
		cin >> s->data;								// 2.3 输入结点值
		s->next = p->next;							// 2.4 s 链在表尾
		p->next = s;
		p = s;										// 2.5 工作指针指向 s
	}
	return true;									// 3.创建成功，返回true
}

//【算法2.16】										头插法创建n个元素
template <class DT>
bool CreateList_2(LNode<DT>* (&L), int n)
{
	int i;
	LNode<DT>* s;
	cout << "逆序输入" << n << "个数据元素：" << endl;
	for (i = 1; i <= n; i++)							// 1.按元素位序逆序创建各结点
	{
		s = new LNode<DT>;							// 1.1 新建一个结点 s
		if (!s)										// 1.2 创建失败，返回false
			return false;
		cin >> s->data;								// 1.3 输入结点值
		s->next = L->next;							// 1.4 s 在头结点后
		L->next = s;
	}
	return true;									// 1.创建成功，返回true
}

//【算法2.17】
template <class DT>
void DestroyList(LNode<DT>* (&L))					// 释放链表所占空间
{
	LNode<DT>* p;
	while (L)										// 1. 表非空,从头结点开始，依次释放结点
	{
		p = L;										// 1.1 处理表头结点
		L = L->next;									// 1.2 头指针后移
		delete p;									// 1.3 释放表头结点所占内存
	}
	L = NULL;											// 2.头指针指向空
}

//【算法2.18】										获取第i个元素
template<class DT>
bool GetElem_i(LNode<DT>* L, int i, DT& e)
{
	LNode<DT>* p;									// 1.初始化
	p = L->next;										// 1.1 设置工作指针，从首结点开始数结点
	int j = 1;										// 1.2 计数器初始化
	while (p && j < i)									// 2.定位到第i个元素结点
	{
		p = p->next; j++;
	}
	if (!p || j > i)									// 3 未找到，返回false
		return false;
	else											// 4. 找到
	{
		e = p->data;									// 获取第i个元素值
		return true;								// 返回true
	}
}

//【算法2.19】										查找值为e的元素位序
template<class DT>
int LocateElem_e(LNode<DT>* L, DT e)
{

	LNode<DT>* p;									// 1.初始化从首元开始查找
	p = L->next;										// 1.1从首元开始查找
	int j = 1;										// 1.2 计数器初值
	while (p && p->data != e)							// 2.顺序查找
	{
		p = p->next;									// 2.1未找到指针后移
		j++;										// 2.2 计数器增1
	}
	if (p == NULL)										// 3. 判断是否找到
		return 0;									// 3.1末找到，返回0
	else
		return j;									// 3.2 找到，返回位序
}

//【算法2.20】										插入第i个元素
template<class DT>
bool InsertElem_i(LNode<DT>*& L, int i, DT e)
{

	int j = 0;
	LNode<DT>* p;									// 1.初始化
	p = L;											// 工作指针初始化
	while (p && j < i - 1)								// 2. 定位到插入点前驱
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)									// 3.判断定位是否成功：    
		return false;								// 3.1 定位失败，不能插入
	else											// 3.2 定位成功
	{
		LNode<DT>* s;
		s = new LNode<DT>;							// 3.2.1建立新结点
		s->data = e;									// 3.2.2新结点赋值
		s->next = p->next;							// 3.2.3结点S链接到p结点之后
		p->next = s;
		return true;								// 3.2.4 插入成功，返回true
	}

}

//【算法2.21】										删除第i个元素
template<class DT>
bool DeleElem_i(LNode<DT>* (&L), int i)
{

	LNode<DT>* p, * q;								//1.初始化：设置工作指针
	p = L;											//查找从头结点开始
	int j = 0;										//计数器初始化
	while (p->next && j < i - 1)							//2.p定位到删除点的前驱
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)								//3.删除位置不合理，不能删除
		return false;								//返回false
	else											//4.删除操作
	{
		q = p->next;									//4.1暂存删除结点位置
		p->next = q->next;							//4.2从链表中摘除删除结点
		delete q;
		return true;								//4.3删除成功，返回true
	}
}


//【算法2.22】										修改第i个元素值
template<class DT>
bool PutElem_i(LNode<DT>* (&L), int i, DT e)
{
	LNode<DT>* p;									// 1.初始化:设置工作指针
	p = L->next;										// 从首结点开始，数结点
	int j = 1;										// 计数器初始化
	while (p && j < i)									// 2.查找第i个元素结点
	{
		p = p->next; j++;
	}
	if (!p || j > i)										// 3.元素不存在,返回false
		return false;
	else											// 4.定位成功
	{
		p->data = e;									// 修改元素值
		return true;								// 返回true
	}
}

// 释放链表所占空间
template<class DT>
void ClearList(LNode<DT>* (&L))
{

	LNode<DT>* p;
	while (L->next)									// 从首元结点开始，依次释放结点
	{
		p = L->next;
		L->next = p->next;
		delete p;
	}
	cout << endl << "表已清空!" << endl;
}


//【算法2.23】										测表长
template<class DT>
int ListLength(LNode<DT>* L)
{													// 1.初始化
	int len = 0;										// 1.1 结点计数器赋初值0
	LNode<DT>* p;									// 1.2设置工作指针
	p = L;											// 指向头结点
	while (p->next)									// 2.数结点个数。有后继结点，  
	{
		len++; p = p->next;							// 结点数增1，指针后移
	}
	return len;										// 3.返回表长
}

//
template<class DT>
bool ListEmpty(LNode<DT>* L)						//测表空
{
	if (L->next == NULL)
		return true;								//空表，返回1
	else
		return false;								//不空，返回0
}


//【算法2.24】										遍历表
template <class DT>
void DispList(LNode<DT>* L)							// 显示表内容
{
	LNode<DT>* p;									// 1. 设置工作指针
	p = L;										// 从首元结点开始遍历
	while (p->next)										// 2.依次输出各结点值
	{
		p = p->next; cout << p->data << "\t";


	}
	cout << endl;
}
