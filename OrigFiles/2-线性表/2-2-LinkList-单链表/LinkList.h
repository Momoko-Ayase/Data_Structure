
template <class DT>
struct LNode										//������
{
	DT data;										//�����򣬴洢����Ԫ��ֵ
	LNode *next;									//ָ����ָ����һ�����
};

//�㷨2.1
template <class DT>
bool PriorElem_e(LNode<DT> *L, DT e, DT &pre_e)		// ��ֵΪe��Ԫ��ǰ��
{
	int k;
	k=LocateElem_e(L,e);							// 1.��ȡe��λ��k
	if(k>1)											// 2.λ��k����1
	{
		GetElem_i(L,k-1,pre_e);						// ��k-1��Ԫ��Ϊe��ǰ��
		return true;
	}
	else											// 3.Ԫ��e��ǰ��
		return false;								// ����false
}

//���㷨2.14��										�����յ�����
template <class DT>  
bool InitList(LNode<DT> *&L)			
{
	L=new LNode<DT>;								// 1.����ͷ���
	if(!L) exit(1);									// 2.����ʧ�ܣ��˳�
	L->next=NULL;									// 3.�����ɹ�
	return true;									// ����true
}

//���㷨2.15��										β�巨����n��Ԫ��
template <class DT>  
bool CreateList_1(LNode<DT> *&L,int n)  
{
	int i;
	LNode<DT> *p,*s;
	p=L;											//1.����ָ���ʼ����ָ��β���
	cout<<"��������"<<n<<"������Ԫ�أ�"<<endl;
	for(i=1; i<=n;i++)							// 2.��Ԫ��λ�����򴴽������
	{
		s=new LNode<DT>;							// 2.1 �½�һ�����s
		if (!s)										// 2.2 ����ʧ�ܣ�����false
			return false;
		cin>>s->data;								// 2.3 ������ֵ
		s->next=p->next;							// 2.4 s ���ڱ�β
		p->next=s;
		p=s;										// 2.5 ����ָ��ָ�� s
	}
	return true;									// 3.�����ɹ�������true
}

//���㷨2.16��										ͷ�巨����n��Ԫ��
template <class DT>  
bool CreateList_2(LNode<DT> *(&L),int n)  
{
	int i;
	LNode<DT> *s;
	cout<<"��������"<<n<<"������Ԫ�أ�"<<endl;
	for(i=1; i<=n;i++)							// 1.��Ԫ��λ�����򴴽������
	{
		s=new LNode<DT>;							// 1.1 �½�һ����� s
		if (!s)										// 1.2 ����ʧ�ܣ�����false
			return false;
		cin>>s->data;								// 1.3 ������ֵ
		s->next=L->next;							// 1.4 s ��ͷ����
		L->next=s;
	}
	return true;									// 1.�����ɹ�������true
}

//���㷨2.17��
template <class DT>  
void DestroyList(LNode<DT> *(&L))					// �ͷ�������ռ�ռ�
{
	LNode<DT> *p;
	while(L)										// 1. ��ǿ�,��ͷ��㿪ʼ�������ͷŽ��
	{
		p=L;										// 1.1 �����ͷ���
		L=L->next;									// 1.2 ͷָ�����
	    delete p;									// 1.3 �ͷű�ͷ�����ռ�ڴ�
	}
	L=NULL;											// 2.ͷָ��ָ���
}

//���㷨2.18��										��ȡ��i��Ԫ��
template<class DT>
bool GetElem_i(LNode<DT> *L,int i, DT &e)   
{
	LNode<DT> *p;									// 1.��ʼ��
	p=L->next;										// 1.1 ���ù���ָ�룬���׽�㿪ʼ�����
	int j=1;										// 1.2 ��������ʼ��
	while(p&&j<i)									// 2.��λ����i��Ԫ�ؽ��
	{
		p=p->next;j++;
	}                 
	if(!p ||j>i )									// 3 δ�ҵ�������false
		return false;
	else											// 4. �ҵ�
	{
		e=p->data;									// ��ȡ��i��Ԫ��ֵ
		return true;								// ����true
	}
}

//���㷨2.19��										����ֵΪe��Ԫ��λ��
template<class DT>
int LocateElem_e(LNode<DT> *L, DT e)  
{
	
	LNode<DT> *p;									// 1.��ʼ������Ԫ��ʼ����
	p=L->next;										// 1.1����Ԫ��ʼ����
	int j=1;										// 1.2 ��������ֵ
	while(p && p->data!=e)							// 2.˳�����
	{                         
		p=p->next;									// 2.1δ�ҵ�ָ�����
		j++;										// 2.2 ��������1
	}
	if(p==NULL)										// 3. �ж��Ƿ��ҵ�
		return 0;									// 3.1ĩ�ҵ�������0
	else 
		return j;									// 3.2 �ҵ�������λ��
}

//���㷨2.20��										�����i��Ԫ��
template<class DT>
bool InsertElem_i(LNode<DT> *&L,int i, DT e)		
{

	int j=0;
	LNode<DT> *p;									// 1.��ʼ��
	p=L;											// ����ָ���ʼ��
	while(p && j<i-1)								// 2. ��λ�������ǰ��
	{
		p=p->next;	
		j++;
	}
	if(!p||j>i-1)									// 3.�ж϶�λ�Ƿ�ɹ���    
    	return false;								// 3.1 ��λʧ�ܣ����ܲ���
	else											// 3.2 ��λ�ɹ�
	{
		LNode<DT> *s;
		s=new LNode<DT>;							// 3.2.1�����½��
		s->data=e;									// 3.2.2�½�㸳ֵ
		s->next=p->next;							// 3.2.3���S���ӵ�p���֮��
		p->next=s;  
       	return true;								// 3.2.4 ����ɹ�������true
	}
	
}

//���㷨2.21��										ɾ����i��Ԫ��
template<class DT>
bool DeleElem_i(LNode<DT> *(&L),int i)
{
	
	LNode<DT> *p,*q;								//1.��ʼ�������ù���ָ��
	p=L;											//���Ҵ�ͷ��㿪ʼ
	int j=0;										//��������ʼ��
	while(p->next && j<i-1)							//2.p��λ��ɾ�����ǰ��
	{
		p=p->next;   
		j++;
	}
	if(!p->next||j>i-1)								//3.ɾ��λ�ò���������ɾ��
		return false;								//����false
	else											//4.ɾ������
	{
		q=p->next;									//4.1�ݴ�ɾ�����λ��
		p->next=q->next;							//4.2��������ժ��ɾ�����
		delete q;
		return true;								//4.3ɾ���ɹ�������true
	}
}


//���㷨2.22��										�޸ĵ�i��Ԫ��ֵ
template<class DT>
bool PutElem_i(LNode<DT> *(&L),int i, DT e) 
{
	LNode<DT> *p;									// 1.��ʼ��:���ù���ָ��
	p=L->next;										// ���׽�㿪ʼ�������
	int j=1;										// ��������ʼ��
	while(p&&j<i)									// 2.���ҵ�i��Ԫ�ؽ��
	{
		p=p->next;j++;
	}
	if(!p||j>i)										// 3.Ԫ�ز�����,����false
		return false;
	else											// 4.��λ�ɹ�
	{ 
		p->data=e;									// �޸�Ԫ��ֵ
		return true;								// ����true
	}
}

													// �ͷ�������ռ�ռ�
template<class DT>									
void ClearList(LNode<DT> *(&L))  
{
	
	LNode<DT> *p;      
	while(L->next)									// ����Ԫ��㿪ʼ�������ͷŽ��
	{
		p=L->next;
		L->next=p->next;
	    delete p;
	}
	cout<<endl<<"�������!"<<endl;
}


//���㷨2.23��										���
template<class DT>
int ListLength(LNode<DT> *L)   
{													// 1.��ʼ��
	int len=0;										// 1.1 ������������ֵ0
	LNode<DT> *p;									// 1.2���ù���ָ��
	p=L;											// ָ��ͷ���
	while(p->next)									// 2.�����������к�̽�㣬  
	{
		len++;p=p->next;							// �������1��ָ�����
	}
	return len;										// 3.���ر�
}

//
template<class DT>
bool ListEmpty(LNode<DT> *L)						//����
{
	if(L->next==NULL)
		return true;								//�ձ�����1
	else
		return false;								//���գ�����0
}


//���㷨2.24��										������
template <class DT>
void DispList(LNode<DT> *L)							// ��ʾ������
{
	LNode<DT> *p;									// 1. ���ù���ָ��
	p=L;										// ����Ԫ��㿪ʼ����
	while(p->next)										// 2.������������ֵ
	{
		p=p->next;cout<<p->data<<"\t";
		
		
	}
	cout<<endl;
}
