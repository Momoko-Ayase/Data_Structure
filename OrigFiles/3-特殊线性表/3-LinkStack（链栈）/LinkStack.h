
template <class DT>
struct SNode			 // ���
{
	DT data;			 // �����򣬴洢����Ԫ��ֵ
	SNode *next;		// ָ����ָ����һ�����
};


//���㷨3.6��
template <class DT>
bool InitStack(SNode<DT> *&S)	    // ��������ջ
{
	S=NULL;
	return true;
}

//���㷨3.7��
template <class DT>
void DestroyStack(SNode<DT> *(&S))	// �ͷ���ջ��ռ�ڴ�
{
	SNode<DT> *p;
	while(S)						//��ͷ��㿪ʼ�������ͷŽ��
	{
		p=S;
		S=S->next;
	    delete p;
	}
	S=NULL;
}



//���㷨3.8��
template<class DT>
bool Push(SNode<DT> *&S,DT e)
{
    SNode<DT> *p;
    p=new SNode<DT>;
    if(!p) 
		return false;  //����ʧ�ܣ���������
    p->data=e;       // �½�㸳ֵ
    p->next=S;  //���S���ӵ�p���֮��
    S=p;
	return true;    // ����ɹ�������true
}

//���㷨3.9��
template<class DT>
bool Pop(SNode<DT> *&S,DT &e)
{
    SNode<DT> *p;
    if(S==NULL)  return false;
    p=S;
    e=p->data;
    S=S->next;
    delete p;
	return true;    // ɾ���ɹ�������true
}


//���㷨3.10��
template<class DT>
bool GetTop(SNode<DT> *S,DT &e)
{
	SNode<DT> *p;
    if(S==NULL)  return false;
    p=S;
    e=p->data;
	return true;    // ɾ���ɹ�������true
}

//��ջ��
template<class DT>
bool StackEmpty(SNode<DT> *S)
{
	if(S==NULL)
		return true;
	else
		return false;
}

//��ʾջ����
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

