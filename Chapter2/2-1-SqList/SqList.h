template <class DT>
struct SqList									// ˳���
{
	DT* elem;									// ����ַ
	int length;									// ��
	int size;									// ������
};

//�㷨2.1
template <class DT>
bool PriorElem_e(SqList<DT> L, DT e, DT& pre_e)				// ��ֵΪe��Ԫ��ǰ��
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

//���㷨2.2��									��ʼ��
template <class DT>
bool InitList(SqList<DT>& L, int m)
{
	L.elem = new DT[m];							// �����ռ�
	if (L.elem == NULL)
	{
		cout << "δ�����ɹ���";					// ���벻�ɹ����˳�
		exit(1);
	}
	L.length = 0;									// ����ɹ������Ը�ֵ���ձ���Ϊ0 
	L.size = m;									// ������Ϊm
	return true;
}

//���㷨2.3��									������Ԫ��
template <class DT>
bool CreateList(SqList<DT>& L, int n)
{
	int i;
	if (n > L.size)								// 1.Ԫ�ظ������ڱ����������ܴ�����
	{
		cout << "Ԫ�ظ������ڱ������ܴ�����" << endl;
		return false;
	}
	cout << "����������" << n << "��Ԫ��ֵ��" << endl;	// 2.��λ�������Ԫ��ֵ
	for (i = 1; i <= n; i++)
		cin >> L.elem[i - 1];
	L.length = n;									// 3.��Ϊ������Ԫ�ظ���
	return true;
}

//���㷨2.4��									����˳���
template <class DT>
void DestroyList(SqList<DT>& L)
{
	delete[] L.elem;							// 1.�ͷű�ռ�
	L.length = 0;									// 2.���Ը�ֵ
	L.size = 0;
}

//���㷨2.5��									��ȡ��i��Ԫ��ֵ
template<class DT>
bool GetElem_i(SqList<DT> L, int i, DT& e)
{
	if (i<1 || i>L.length)						// 1.λ�򲻺�������false
	{
		cout << "��Ԫ�ز����ڣ�" << endl;
		return false;
	}
	e = L.elem[i - 1];								// 2. ���򣬻�ȡ��i��Ԫ��ֵ
	return true;								// ����true
}

//���㷨2.6��									��ֵ����
template<class DT>
int LocateElem_e(SqList<DT> L, DT e)
{
	for (int i = 1; i <= L.length; i++)				// ˳�����
		if (L.elem[i - 1] == e)						// 1.�ҵ�
			return i;							// ����Ԫ��λ��
	return 0;									// 2.δ�ҵ�������0
}

//���㷨2.7��
template<class DT>
bool InsertElem_i(SqList<DT>& L, int i, DT e)
{
	if (L.length >= L.size)						// 1.���������ܲ���
		return false;
	if (i<1 || i>L.length + 1)						// 2.����λ�ò��������ܲ���
		return false;
	for (int j = L.length; j >= i; j--)				// 3. an~ai���κ���
		L.elem[j] = L.elem[j - 1];
	L.elem[i - 1] = e;
	L.length++;
	return true;								// ����ɹ�������true
}

//���㷨2.8��									ɾ����i��Ԫ��
template<class DT>
bool DeleElem_i(SqList<DT>& L, int i)
{
	if (L.length == 0)								// 1.��գ�����ɾ��
		return false;
	if (i<1 || i>L.length)						// 2.ɾ��λ�ò��������ܲ���
		return false;
	for (int j = i; j < L.length; j++)				// 3. ai+1~an����ǰ��
		L.elem[j - 1] = L.elem[j];
	L.length--;
	return true;								// ɾ���ɹ�������true
}


//���㷨2.9��
template<class DT>
bool PutElem(SqList<DT>& L, int i, DT e)			// �޸ĵ�i��Ԫ�ص�ֵ
{
	if (i<1 || i>L.length)						// 1.λ�򲻺��������޸ģ�
		return false;							// ����false
	L.elem[i - 1] = e;								// 2.���õ�i��Ԫ��ֵ
	return true;								// 3.�޸ĳɹ�������true
}

// ���˳���
template<class DT>
void ClearList(SqList<DT>& L)
{
	L.length = 0;									 // �ձ���Ϊ0
}


// ���
template<class DT>
int ListLength(SqList<DT> L)
{
	return L.length;
}


template<class DT>
bool ListEmpty(SqList<DT> L)					// ����
{
	if (L.length == 0)								 // �ձ�����true
		return true;
	else
		return false;							// �ǿձ�����false
}

template<class DT>
bool ListFull(SqList<DT> L)
{
	if (L.length == L.size)						// ����������true
		return true;
	else
		return false;							// ����������false
}

//���㷨2.10��									�������
template <class DT>
void DispList(SqList<DT> L)
{
	int i;
	for (i = 1; i <= L.length; i++)					// ��λ�����Ԫ��ֵ
	{
		cout << L.elem[i - 1] << "\t";

	}
	cout << endl;
}


