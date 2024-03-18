#include<iostream>
#include<string>
using namespace std;

struct dancer							// 舞者信息
{
	string name;						// 姓名
	char sex;							// 性别
};


struct Node								// 队列结点
{
	dancer data;						// 数据域
	Node* next;							// 指针域，指向后继
}*front, * rear;							// 队头、队尾										

struct LinkQueue
{
	Node* front;
	Node* rear;
};											// 男队和女队

void InitialLinkQueue(LinkQueue& Q)						// 初始化队列
{
	Q.front = new Node;
	Q.front->next = NULL;
	Q.rear = Q.front;
}

void DestroyLinkQueue(LinkQueue& Q)						// 销毁队列
{
	Node* p;
	while (Q.front != NULL)
	{
		p = Q.front;
		Q.front = Q.front->next;
		delete p;
	}
}

void EnQueue(LinkQueue& Q, dancer& e)					// 入队
{
	Node* s = new Node;
	s->data = e;
	s->next = Q.rear->next;
	Q.rear->next = s;
	Q.rear = s;
}

bool IsEmpty(LinkQueue Q)								// 判队空
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

bool DeQueue(LinkQueue& Q, dancer& e)					// 出队
{
	Node* p;
	if (IsEmpty(Q))										// 队空，
	{
		cout << "队列为空，无法出队列！";
		return false;
	}
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (p == Q.rear)										// 只有一个元素，出队
		Q.rear = Q.front;									// 修改队尾指针
	delete p;
	return true;
}

bool GetHead(LinkQueue Q, dancer& e)
{
	if (IsEmpty(Q)) 										// 队空
	{
		cout << "队列为空，无法取得队首元素！";
		return false;
	}
	e = Q.front->next->data;								// 返回队头元素
	return true;
}

void QueueTranverse(LinkQueue Q)							// 遍历队
{
	Node* p;
	p = Q.front->next;
	while (p != NULL)
	{
		cout << (p->data).name << " ";
		p = p->next;
	}
	cout << endl;
}

void EntranHall(dancer person[], int num)					// 舞者入场
{
	int i;
	for (i = 0; i < num; i++)
	{
		cout << "请输入第" << i + 1 << "个舞者性别(F(女) or M(男))及姓名:" << endl;
		cin >> person[i].sex;
		cin >> person[i].name;
	}
	cout << "现有舞者：" << endl;
	for (i = 0; i < num; i++)
	{
		cout << i + 1 << ":" << person[i].sex
			<< "," << person[i].name << endl;
	}

}


//算法3.24
void DancePartner(dancer person[], int num)
{
	dancer newdancer, m, f, p;
	LinkQueue GenQueue;
	LinkQueue LadyQueue;
	InitialLinkQueue(GenQueue);							    // 初始化男队
	InitialLinkQueue(LadyQueue);									    // 初始化女队
	for (int i = 0; i < num; i++)										// 舞者入场
	{
		p = person[i];
		if (p.sex == 'F')
			EnQueue(LadyQueue, p);
		else
			EnQueue(GenQueue, p);
	}
	while ((!IsEmpty(GenQueue)) && (!IsEmpty(LadyQueue)))		// 匹配舞者
	{
		DeQueue(GenQueue, m);								// 女士出队
		DeQueue(LadyQueue, f);								// 男士出队
		cout << m.name << "<---配对--->" << f.name << endl;       // 男、女配队
	}
	if (!IsEmpty(GenQueue))
	{
		GetHead(GenQueue, m);
		cout << m.name << "先生还在等着呢!" << endl;
	}
	else if (!IsEmpty(LadyQueue))
	{
		GetHead(LadyQueue, f);
		cout << f.name << "女士还在等着呢!" << endl;
	}
	else
		cout << "配对完美结束!" << endl;
	DestroyLinkQueue(GenQueue);							// 销毁队列
	DestroyLinkQueue(LadyQueue);
}

int main()
{
	dancer* person;
	int num;
	cout << "请输入舞伴总数量:" << endl;
	cin >> num;
	person = new dancer[num];
	EntranHall(person, num);							// 舞者入场
	DancePartner(person, num);							// 舞者匹配
	return 0;
}

