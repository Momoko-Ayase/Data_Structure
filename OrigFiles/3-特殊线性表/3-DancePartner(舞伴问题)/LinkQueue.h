
template <class DT>
struct QNode  //���
{
	DT data;     //�����򣬴洢����Ԫ��ֵ
	QNode *next;//ָ����ָ����һ�����
};

template<class DT>
struct LinkQueue
{
	QNode<DT> * front;
	QNode<DT> * rear;
};


//���㷨3.19��
template <class DT>
void InitQueue(LinkQueue<DT> &Q)//�����ն���
{
	Q.front=new QNode<DT>;     //����ͷ���
	if(!Q.front) exit(1);  //����ʧ�ܣ���������
	Q.front->next=NULL;
	Q.rear=Q.front;
}

//���㷨3.20��
template <class DT>
void DestroyQueue(LinkQueue<DT> &Q)//�ͷ�����
{
	QNode<DT> *p;
	while(Q.front)//��ͷ��㿪ʼ�������ͷŽ��
	{
		p=Q.front;
		Q.front=Q.front->next;
	    delete p;
	}
}

//���㷨3.21�� ���
template<class DT>
bool EnQueue(LinkQueue<DT> &Q,DT e)
{
    QNode<DT> *p;
    p=new QNode<DT>;         // �����½��
    if(!p) return false;      // ����ʧ�ܣ���������
    p->data=e;               // �½�㸳ֵ
    p->next=NULL;            // ���ڶ�β
    Q.rear->next=p;
    Q.rear=p;
	return true;             // ��ӳɹ�������true
}

//���㷨3.22�� ����
template<class DT>
bool DeQueue(LinkQueue<DT> &Q,DT &e)      
{
    QNode<DT> *p;
    if(Q.front==Q.rear)  return false;     //�ӿգ�����false
    p=Q.front->next;                      // ȡ����Ԫ��
    e=p->data;
    Q.front->next=p->next;                //����Ԫ�س���
    if(Q.rear==p)                         //ֻ��һ��Ԫ��ʱ���ӣ�
		Q.rear=Q.front;                  // �޸Ķ�β
    delete p;
	return true;                        // ���ӳɹ�������true
}


//���㷨3.23��  ȡ��ͷԪ��
template<class DT>
bool GetHead(LinkQueue<DT> Q,DT &e)
{
	if(Q.front==Q.rear)  return false;     // �ӿգ�����false
    e=Q.front->next->data;
	return true;                           // ɾ���ɹ�������true
}

//ȡ��βԪ��
template<class DT>
bool GetTail(LinkQueue<DT> Q,DT &e)
{
	if(Q.front==Q.rear)             // �ӿ�
		return false;               // ����false
    e=Q.rear->data;                 // ��ȡ��βԪ��
	return true;                    // ����true
}

//��ӿ�
template<class DT>
bool QueueEmpty(LinkQueue<DT> Q)
{
	if(Q.front==Q.rear)    // �ӿ�
		return true;       //����true
	else                  //�ǿ�
		return false;    //����false
}

//��ʾ��������
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

