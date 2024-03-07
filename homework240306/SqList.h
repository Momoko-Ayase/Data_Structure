template <class DT>
struct SqList									// 顺序表
{
	DT* elem;									// 表首址
	int length;									// 表长
	int size;									// 表容量
};

//算法2.1
template <class DT>
bool PriorElem_e(SqList<DT> L, DT e, DT& pre_e)				// 求值为e的元素前驱
{
	int k;
	k = LocateElem_e(L, e);					//
	if (k > 1)
	{
		GetElem_i(L, k - 1, pre_e);
		return false;
	}
	else
		return true;
}

//【算法2.2】									初始化
template <class DT>
bool InitList(SqList<DT>& L, int m)
{
	L.elem = new DT[m];							// 申请表空间
	if (L.elem == NULL)
	{
		cout << "未创建成功！";					// 申请不成功，退出
		exit(1);
	}
	L.length = 0;									// 申请成功，属性赋值。空表，表长为0 
	L.size = m;									// 表容量为m
	return true;
}

//【算法2.3】									创建表元素
template <class DT>
bool CreateList(SqList<DT>& L, int n)
{
	int i;
	if (n > L.size)								// 1.元素个数大于表容量，不能创建。
	{
		cout << "元素个数大于表长，不能创建！" << endl;
		return false;
	}
	cout << "请依次输入" << n << "个元素值：" << endl;	// 2.依位序输入各元素值
	for (i = 1; i <= n; i++)
		cin >> L.elem[i - 1];
	L.length = n;									// 3.表长为创建的元素个数
	return true;
}

//【算法2.4】									销毁顺序表
template <class DT>
void DestroyList(SqList<DT>& L)
{
	delete[] L.elem;							// 1.释放表空间
	L.length = 0;									// 2.属性赋值
	L.size = 0;
}

//【算法2.5】									获取第i个元素值
template<class DT>
bool GetElem_i(SqList<DT> L, int i, DT& e)
{
	if (i<1 || i>L.length)						// 1.位序不合理，返回false
	{
		cout << "该元素不存在！" << endl;
		return false;
	}
	e = L.elem[i - 1];								// 2. 否则，获取第i个元素值
	return true;								// 返回true
}

//【算法2.6】									按值查找
template<class DT>
int LocateElem_e(SqList<DT> L, DT e)
{
	for (int i = 1; i <= L.length; i++)				// 顺序查找
		if (L.elem[i - 1] == e)						// 1.找到
			return i;							// 返回元素位序
	return 0;									// 2.未找到，返回0
}

//【算法2.7】
template<class DT>
bool InsertElem_i(SqList<DT>& L, int i, DT e)
{
	if (L.length >= L.size)						// 1.表满，不能插入
		return false;
	if (i<1 || i>L.length + 1)						// 2.插入位置不合理，不能插入
		return false;
	for (int j = L.length; j >= i; j--)				// 3. an~ai依次后移
		L.elem[j] = L.elem[j - 1];
	L.elem[i - 1] = e;
	L.length++;
	return true;								// 插入成功，返回true
}

//【算法2.8】									删除第i个元素
template<class DT>
bool DeleElem_i(SqList<DT>& L, int i)
{
	if (L.length == 0)								// 1.表空，不能删除
		return false;
	if (i<1 || i>L.length)						// 2.删除位置不合理，不能插入
		return false;
	for (int j = i; j < L.length; j++)				// 3. ai+1~an依次前移
		L.elem[j - 1] = L.elem[j];
	L.length--;
	return true;								// 删除成功，返回true
}


//【算法2.9】
template<class DT>
bool PutElem(SqList<DT>& L, int i, DT e)			// 修改第i个元素的值
{
	if (i<1 || i>L.length)						// 1.位序不合理，不能修改，
		return false;							// 返回false
	L.elem[i - 1] = e;								// 2.重置第i个元素值
	return true;								// 3.修改成功，返回true
}

// 清空顺序表
template<class DT>
void ClearList(SqList<DT>& L)
{
	L.length = 0;									 // 空表，表长为0
}


// 测表长
template<class DT>
int ListLength(SqList<DT> L)
{
	return L.length;
}


template<class DT>
bool ListEmpty(SqList<DT> L)					// 测表空
{
	if (L.length == 0)								 // 空表，返回true
		return true;
	else
		return false;							// 非空表，返回false
}

template<class DT>
bool ListFull(SqList<DT> L)
{
	if (L.length == L.size)						// 表满，返回true
		return true;
	else
		return false;							// 表不满，返回false
}

//【算法2.10】									遍历输出
template <class DT>
void DispList(SqList<DT> L)
{
	int i;
	for (i = 1; i <= L.length; i++)					// 依位序输出元素值
	{
		cout << L.elem[i - 1] << "\t";

	}
	cout << endl;
}


