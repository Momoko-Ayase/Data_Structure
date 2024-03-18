#include<iostream>
#include<string>
using namespace std;

struct dancer							// ������Ϣ
{   string name;						// ����
    char sex;							// �Ա�
};


struct Node								// ���н��
{   dancer data;						// ������
	Node* next;							// ָ����ָ����
}*front,*rear;							// ��ͷ����β										

struct LinkQueue
{    Node *front;
     Node *rear;
};											// �жӺ�Ů��

void InitialLinkQueue(LinkQueue &Q)						// ��ʼ������
{	
	Q.front=new Node;
    Q.front->next=NULL;
	Q.rear=Q.front;
}

void DestroyLinkQueue(LinkQueue &Q)						// ���ٶ���
{   Node *p;
    while(Q.front!=NULL)
    {	p=Q.front;
	    Q.front=Q.front->next;
	    delete p;
    }
}

void EnQueue(LinkQueue &Q,dancer &e)					// ���
{
	Node *s=new Node;
    s->data=e;
    s->next=Q.rear->next;
    Q.rear->next=s;
    Q.rear=s;
}

bool IsEmpty(LinkQueue Q)								// �жӿ�
{
	if (Q.front==Q.rear)
		return true;
	else
		return false;
}

bool DeQueue(LinkQueue &Q,dancer &e)					// ����
{  
   Node *p;
   if (IsEmpty(Q))										// �ӿգ�
   {
	   cout<<"����Ϊ�գ��޷������У�";
	   return false;
   }
   p=Q.front->next;
   e=p->data;
   Q.front->next=p->next;
   if (p==Q.rear)										// ֻ��һ��Ԫ�أ�����
	   Q.rear=Q.front;									// �޸Ķ�βָ��
   delete p;
   return true;
}

bool GetHead(LinkQueue Q,dancer &e)
{   if(IsEmpty(Q)) 										// �ӿ�
	{
		cout<< "����Ϊ�գ��޷�ȡ�ö���Ԫ�أ�";
		return false;
	}
    e=Q.front->next->data;								// ���ض�ͷԪ��
	return true;
}

void QueueTranverse(LinkQueue Q)							// ������
{	Node *p;
    p=Q.front->next;
    while(p!=NULL)
    {	cout<<(p->data).name<<" ";
	    p=p->next;
    }
    cout<<endl;
}

void EntranHall(dancer person[],int num)					// �����볡
{
	int i;
	for(i=0;i<num;i++)										
    {
		cout<<"�������"<<i+1<<"�������Ա�(F(Ů) or M(��))������:"<<endl;
		cin>>person[i].sex;
		cin>>person[i].name;
	}
	cout<<"�������ߣ�"<<endl;
	for(i=0;i<num;i++)									
    {
		cout<<i+1<<":"<<person[i].sex
			<<","<<person[i].name<<endl;
	}

}


//�㷨3.24
void DancePartner(dancer person[],int num)
{
	dancer newdancer,m,f,p;
	LinkQueue GenQueue;
	LinkQueue LadyQueue;
	InitialLinkQueue(GenQueue);							    // ��ʼ���ж�
	InitialLinkQueue(LadyQueue);									    // ��ʼ��Ů��
	for(int i=0;i<num;i++)										// �����볡
     {  p=person[i];
		if(p.sex=='F')											
            EnQueue(LadyQueue,p);
        else
            EnQueue(GenQueue,p);
	 }
	 while ( (!IsEmpty(GenQueue)) && (!IsEmpty(LadyQueue)) )		// ƥ������
	 {
		 DeQueue(GenQueue,m);								// Ůʿ����
		 DeQueue(LadyQueue,f);								// ��ʿ����
         cout<<m.name <<"<---���--->"<<f.name<<endl;       // �С�Ů���
	 }
     if (!IsEmpty(GenQueue))
	 {
		 GetHead(GenQueue,m);
         cout<<m.name<<"�������ڵ�����!"<<endl;
	 }
     else if (!IsEmpty(LadyQueue))
	 {
		GetHead(LadyQueue,f);
        cout<<f.name<<"Ůʿ���ڵ�����!"<<endl;
	 }
     else
        cout<<"�����������!"<<endl;
	DestroyLinkQueue(GenQueue);							// ���ٶ���
	DestroyLinkQueue(LadyQueue);
}

int main()
{    
    dancer *person;
	int num;
	cout<<"���������������:"<<endl;
	cin>>num;
	person=new dancer[num];
	EntranHall(person, num);							// �����볡
	DancePartner(person,num);							// ����ƥ��
    return 0;
}

