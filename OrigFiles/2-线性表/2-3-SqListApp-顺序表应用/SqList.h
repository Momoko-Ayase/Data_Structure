template <class DT>
struct SqList   //顺序表类
{
	DT *elem; //表首址
	int length; //表长
	int size;//表容量
};

//【算法2.2】
template <class DT>  
bool InitList(SqList<DT> &L, int m)
{//构建函数，创建一表容量为m的空表
	L.elem=new DT[m];// 申请表空间
    if(L.elem==NULL)
	{
		cout<<"未创建成功！";
		exit (1); 
	}
	L.length=0;  // 空表，表长为0
	L.size=m;    //表容量为m
	return true;
}

//【算法2.3】
template <class DT>  
bool CreateList(SqList<DT> &L,int n)  //创建表长度为n的顺序表
{
	int i;
	if(n>L.size) 
	{
		cout<<"元素个数大于表长，不能创建！"<<endl;
		return false;
	}
	cout<<"请依次输入"<<n<<"个元素值："<<endl;
	for(i=1;i<=n;i++)
	   cin>>L.elem[i-1];
	L.length=n;
	return true;
}

//【算法2.4】
template <class DT>  
void DestroyList(SqList<DT> &L) //销毁顺序表，释放表空间
{
	delete [] L.elem;
	L.length=0; 
	L.size=0; 
}

//【算法2.5】
template<class DT>
bool GetElem_i(SqList<DT> L,int i, DT &e)// 获取第i个元素值
{
	if(i<0 || i>L.length)
		return false;
	e=L.elem[i-1];
	return true;
}

//【算法2.6】
template<class DT>
int LocateElem_e(SqList<DT> L, DT e) // 按值查找
{
	int i;
	for(i=0; i<L.length; i++)  // 顺序查找
		if(L.elem[i]==e)   // 找到
			return i+1; 
	return 0;    // 未找到
}

//【算法2.7】
template<class DT>
bool InsertElem_i(SqList<DT> &L,int i, DT e) // 在第i个位置插入新元素
{
	int j;
	if(L.length>=L.size)              //1.表满，不能插入
		return false; 
	if(i<1 || i>L.length+1)          //2.插入位置不合理，不能插入
		return false;
	for (j=L.length; j>=i; j--)  //3. an~ai依次后移
		L.elem[j]=L.elem[j-1];
	L.elem[i-1]=e;
	L.length++;
	return true;    // 插入成功，返回true
}

//【算法2.8】
template<class DT>
bool DeleElem_i(SqList<DT> &L,int i) // 删除第i个元素
{
	int j;
	if(L.length==0)                //1.表空，不能删除
		return false;
	if(i<1 || i>L.length)          //2.删除位置不合理，不能插入
		return false;
	for (j=i; j<L.length; j++)  //3. ai~an依次前移
		L.elem[j-1]=L.elem[j];
	L.length--;
	return true;                    // 删除成功，返回true
}


//【算法2.9】
template<class DT>
bool PutElem(SqList<DT> &L,int i, DT e) // 修改第i个元素的值
{
	if(i<1 || i>L.length)               //1.位置不合理，不能修改
		return false;
	L.elem[i-1]=e;                     //2.重置第i个元素值
	return true;                       //3.修改成功，返回true
}

//清空顺序表
template<class DT>
void ClearList(SqList<DT> &L)
{
	L.length=0;
}


//测表长
template<class DT>
int ListLength(SqList<DT> L)
{
	return L.length;
}

//测表空
template<class DT>
bool ListEmpty(SqList<DT> L)
{
	if(L.length==0)
		return true;
	else
		return false;
}

//测表满
template<class DT>
bool ListFull(SqList<DT> L)
{
	if(L.length==L.size)
		return true;
	else
		return false;
}

//【算法2.10】
template <class DT>
void DispList(SqList<DT> L)  //遍历输出
{
	int i;
	for(i=0;i<L.length;i++)
	{
		cout<<L.elem[i]<<"\t";
		
	}
	cout<<endl;
}

