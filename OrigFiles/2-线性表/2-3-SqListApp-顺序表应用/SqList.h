template <class DT>
struct SqList   //˳�����
{
	DT *elem; //����ַ
	int length; //��
	int size;//������
};

//���㷨2.2��
template <class DT>  
bool InitList(SqList<DT> &L, int m)
{//��������������һ������Ϊm�Ŀձ�
	L.elem=new DT[m];// �����ռ�
    if(L.elem==NULL)
	{
		cout<<"δ�����ɹ���";
		exit (1); 
	}
	L.length=0;  // �ձ���Ϊ0
	L.size=m;    //������Ϊm
	return true;
}

//���㷨2.3��
template <class DT>  
bool CreateList(SqList<DT> &L,int n)  //��������Ϊn��˳���
{
	int i;
	if(n>L.size) 
	{
		cout<<"Ԫ�ظ������ڱ������ܴ�����"<<endl;
		return false;
	}
	cout<<"����������"<<n<<"��Ԫ��ֵ��"<<endl;
	for(i=1;i<=n;i++)
	   cin>>L.elem[i-1];
	L.length=n;
	return true;
}

//���㷨2.4��
template <class DT>  
void DestroyList(SqList<DT> &L) //����˳����ͷű�ռ�
{
	delete [] L.elem;
	L.length=0; 
	L.size=0; 
}

//���㷨2.5��
template<class DT>
bool GetElem_i(SqList<DT> L,int i, DT &e)// ��ȡ��i��Ԫ��ֵ
{
	if(i<0 || i>L.length)
		return false;
	e=L.elem[i-1];
	return true;
}

//���㷨2.6��
template<class DT>
int LocateElem_e(SqList<DT> L, DT e) // ��ֵ����
{
	int i;
	for(i=0; i<L.length; i++)  // ˳�����
		if(L.elem[i]==e)   // �ҵ�
			return i+1; 
	return 0;    // δ�ҵ�
}

//���㷨2.7��
template<class DT>
bool InsertElem_i(SqList<DT> &L,int i, DT e) // �ڵ�i��λ�ò�����Ԫ��
{
	int j;
	if(L.length>=L.size)              //1.���������ܲ���
		return false; 
	if(i<1 || i>L.length+1)          //2.����λ�ò��������ܲ���
		return false;
	for (j=L.length; j>=i; j--)  //3. an~ai���κ���
		L.elem[j]=L.elem[j-1];
	L.elem[i-1]=e;
	L.length++;
	return true;    // ����ɹ�������true
}

//���㷨2.8��
template<class DT>
bool DeleElem_i(SqList<DT> &L,int i) // ɾ����i��Ԫ��
{
	int j;
	if(L.length==0)                //1.��գ�����ɾ��
		return false;
	if(i<1 || i>L.length)          //2.ɾ��λ�ò��������ܲ���
		return false;
	for (j=i; j<L.length; j++)  //3. ai~an����ǰ��
		L.elem[j-1]=L.elem[j];
	L.length--;
	return true;                    // ɾ���ɹ�������true
}


//���㷨2.9��
template<class DT>
bool PutElem(SqList<DT> &L,int i, DT e) // �޸ĵ�i��Ԫ�ص�ֵ
{
	if(i<1 || i>L.length)               //1.λ�ò����������޸�
		return false;
	L.elem[i-1]=e;                     //2.���õ�i��Ԫ��ֵ
	return true;                       //3.�޸ĳɹ�������true
}

//���˳���
template<class DT>
void ClearList(SqList<DT> &L)
{
	L.length=0;
}


//���
template<class DT>
int ListLength(SqList<DT> L)
{
	return L.length;
}

//����
template<class DT>
bool ListEmpty(SqList<DT> L)
{
	if(L.length==0)
		return true;
	else
		return false;
}

//�����
template<class DT>
bool ListFull(SqList<DT> L)
{
	if(L.length==L.size)
		return true;
	else
		return false;
}

//���㷨2.10��
template <class DT>
void DispList(SqList<DT> L)  //�������
{
	int i;
	for(i=0;i<L.length;i++)
	{
		cout<<L.elem[i]<<"\t";
		
	}
	cout<<endl;
}

